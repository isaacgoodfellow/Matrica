#include "matrica_app.h"

#include <Poco/String.h>
#include <ds/app/environment.h>
#include <ds/debug/logger.h>
#include <ds/app/engine/engine.h>
#include <ds/ui/interface_xml/interface_xml_importer.h>

#include <ds/ui/media/media_viewer.h>

#include <cinder/Rand.h>

#include "ui/background/background_view.h"
#include "ui/background/transition.h"
#include "ui/matrica_controller.h"
#include "visuals/visual_controller.h"


#include "app/app_defs.h"
#include "app/globals.h"

#include "events/app_events.h"



namespace matrica {

Matrica::Matrica()
	: ds::App(ds::RootList()
	// Note: this is where you'll customize the root list
	.ortho()
	.pickColor()

	// If you need a perspective view, add it here.
	// Then you can refer to the perspective root later and modify its properties (see setupServer())
	/*
	.persp()
	.perspFov(60.0f)
	.perspPosition(ci::Vec3f(0.0, 0.0f, 10.0f))
	.perspTarget(ci::Vec3f(0.0f, 0.0f, 0.0f))
	.perspNear(0.0002f)
	.perspFar(20.0f)

	.ortho()
	*/

	)
	, mGlobals(mEngine, mAllData)
	, mMetronome(mGlobals)
	, mQueryHandler(mEngine, mAllData)
	, mIdling(false)
	, mTouchDebug(mEngine)
	, mEventClient(mEngine.getNotifier(), [this](const ds::Event *m){ if(m) this->onAppEvent(*m); })
{

	// Register events so they can be called by string
	// after this registration, you can call the event like the following, or from an interface xml file
	// mEngine.getNotifier().notify("StoryDataUpdatedEvent");
	ds::event::Registry::get().addEventCreator(StoryDataUpdatedEvent::NAME(), [this]()->ds::Event*{return new StoryDataUpdatedEvent(); });
	ds::event::Registry::get().addEventCreator(RequestAppExitEvent::NAME(), [this]()->ds::Event*{return new RequestAppExitEvent(); });


	enableCommonKeystrokes(true);
}

void Matrica::setupServer(){

	// Fonts links together a font name and a physical font file
	// Then the "text.xml" and TextCfg will use those font names to specify visible settings (size, color, leading)
	mEngine.loadSettings("FONTS", "fonts.xml");
	mEngine.editFonts().clear();
	mEngine.getSettings("FONTS").forEachTextKey([this](const std::string& key){
		mEngine.editFonts().install(ds::Environment::expand(mEngine.getSettings("FONTS").getText(key)), key);
	});

	// Colors
	// After registration, colors can be called by name from settings files or in the app
	mEngine.editColors().clear();
	mEngine.editColors().install(ci::Color(1.0f, 1.0f, 1.0f), "white");
	mEngine.editColors().install(ci::Color(0.0f, 0.0f, 0.0f), "black");
	mEngine.loadSettings("COLORS", "colors.xml");
	mEngine.getSettings("COLORS").forEachColorAKey([this](const std::string& key){
		mEngine.editColors().install(mEngine.getSettings("COLORS").getColorA(key), key);
	});

	/* Settings */
	mEngine.loadSettings(SETTINGS_APP, "app_settings.xml");
	mEngine.loadTextCfg("text.xml");

	mGlobals.initialize();
	mQueryHandler.runInitialQueries(true);

	const bool cacheXML = mGlobals.getAppSettings().getBool("xml:cache", 0, true);
	ds::ui::XmlImporter::setAutoCache(cacheXML);

	const int numRoots = mEngine.getRootCount();
	int numPlacemats = 0;
	for(int i = 0; i < numRoots - 1; i++){
		// don't clear the last root, which is the debug draw
		if(mEngine.getRootBuilder(i).mDebugDraw) continue;

		ds::ui::Sprite& rooty = mEngine.getRootSprite(i);
		if(rooty.getPerspective()){
			const float clippFar = 10000.0f;
			const float fov = 60.0f;
			ds::PerspCameraParams p = mEngine.getPerspectiveCamera(i);
			p.mTarget = ci::Vec3f(mEngine.getWorldWidth() / 2.0f, mEngine.getWorldHeight() / 2.0f, 0.0f);
			p.mFarPlane = clippFar;
			p.mFov = fov;
			p.mPosition = ci::Vec3f(mEngine.getWorldWidth() / 2.0f, mEngine.getWorldHeight() / 2.0f, mEngine.getWorldWidth() / 2.0f);
			mEngine.setPerspectiveCamera(i, p);
		} else {
			mEngine.setOrthoViewPlanes(i, -10000.0f, 10000.0f);
		}

		rooty.clearChildren();
	}

	ds::ui::Sprite &rootSprite = mEngine.getRootSprite();
	rootSprite.setTransparent(false);
	rootSprite.setColor(ci::Color(0.1f, 0.1f, 0.1f));
	

	BackgroundView* bg = new BackgroundView(mGlobals, 2000, 2000);
	rootSprite.addChildPtr(bg);
	bg->show();
	bg->setPosition(0.0f, 0.0f);

	// add sprites
	MatricaModel m = MatricaModel(1, 16, 8, "triangle/", TriggerableVisual::kVisualPop, mGlobals.mColor_Green, mGlobals.mColor_Pink, mGlobals.mColor_Green);
	MatricaPanel *p = new MatricaPanel(mGlobals, m);
	rootSprite.addChildPtr(new MatricaController(mGlobals, p));
	rootSprite.addChildPtr(p);
	p->setPosition(mGlobals.mEngine.getWorldWidth() / 2.0f, mGlobals.mEngine.getWorldHeight() / 2.0f);

	VisualController *vc = new VisualController(mGlobals);
	rootSprite.addChildPtr(vc);
	vc->sendToFront();

	rootSprite.addChildPtr(new TransitionView(mGlobals));

	// The engine will actually be idling, and this gets picked up on the next update
	mIdling = false;
	mEngine.getNotifier().notify(IdleEndedEvent());



}

void Matrica::update() {
	ds::App::update();

	bool rootsIdle = true;
	const int numRoots = mEngine.getRootCount();
	for(int i = 0; i < numRoots - 1; i++){
		// don't clear the last root, which is the debug draw
		if(mEngine.getRootBuilder(i).mDebugDraw) continue;
		if(!mEngine.getRootSprite(i).isIdling()){
			rootsIdle = false;
			break;
		}
	}

	if(rootsIdle && !mIdling){
		//Start idling
		mIdling = true;
		mEngine.getNotifier().notify(IdleStartedEvent());
		

	} else if(!rootsIdle && mIdling){
		//Stop idling
		mIdling = false;
		mEngine.getNotifier().notify(IdleEndedEvent());
	}

	mMetronome.update();


}

void Matrica::forceStartIdleMode(){
	// force idle mode to start again
	const int numRoots = mEngine.getRootCount();
	for(int i = 0; i < numRoots - 1; i++){
		// don't clear the last root, which is the debug draw
		if(mEngine.getRootBuilder(i).mDebugDraw) continue;
		mEngine.getRootSprite(i).startIdling();
	}
	mEngine.startIdling();
	mIdling = true;

	mEngine.getNotifier().notify(IdleStartedEvent());
}

void Matrica::onAppEvent(const ds::Event& in_e){
	if(in_e.mWhat == RequestAppExitEvent::WHAT()){
		quit();
	} 
}

void Matrica::keyDown(ci::app::KeyEvent event){
	using ci::app::KeyEvent;
	ds::App::keyDown(event);
	if(event.getChar() == KeyEvent::KEY_r){ // R = reload all configs and start over without quitting app
		setupServer();

	// Shows all enabled sprites with a label for class type
	} else if(event.getCode() == KeyEvent::KEY_f){

	} else if(event.getCode() == KeyEvent::KEY_i){
		forceStartIdleMode();
	}
}

void Matrica::mouseDown(ci::app::MouseEvent e) {
	mTouchDebug.mouseDown(e);
}

void Matrica::mouseDrag(ci::app::MouseEvent e) {
	mTouchDebug.mouseDrag(e);
}

void Matrica::mouseUp(ci::app::MouseEvent e) {
	mTouchDebug.mouseUp(e);
}

void Matrica::fileDrop(ci::app::FileDropEvent event){

}

} // namespace matrica

// This line tells Cinder to actually create the application
CINDER_APP_BASIC(matrica::Matrica, ci::app::RendererGl(ci::app::RendererGl::AA_MSAA_4))