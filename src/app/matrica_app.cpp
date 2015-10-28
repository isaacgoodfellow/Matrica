#include "matrica_app.h"

#include <Poco/String.h>
#include <ds/app/environment.h>
#include <ds/debug/logger.h>
#include <ds/app/engine/engine.h>

#include "app/app_defs.h"
#include "app/globals.h"

#include "events/app_events.h"

#include "ui/background/background_view.h"
#include "ui/background/transition.h"
#include "ui/matrica_panel.h"
#include "ui/matrica_controller.h"

#include "util/metronome.h"
#include "util/osc_sender.h"

#include "visuals/triggerable_visual.h"
#include "visuals/visual_controller.h"

namespace matrica {

Matrica::Matrica()
	: inherited(ds::RootList()
	.ortho() // sample ortho view
	.pickColor()

	.persp() // sample perp view
	.perspFov(60.0f)
	.perspPosition(ci::Vec3f(0.0, 0.0f, 10.0f))
	.perspTarget(ci::Vec3f(0.0f, 0.0f, 0.0f))
	.perspNear(0.0002f)
	.perspFar(20.0f)

	.ortho() ) // ortho view on top
	, mGlobals(mEngine , mAllData )
	, mQueryHandler(mEngine, mAllData)
	, mIdling( false )
	, mOscSender( mGlobals, "127.0.0.1", 9001 )
	, mMetronome(mGlobals)
{

	/*fonts in use */
	mEngine.editFonts().install(ds::Environment::getAppFile("data/fonts/NotoSans-Bold.ttf"), "noto-bold");
	enableCommonKeystrokes(true);

}

void Matrica::setupServer(){

	/* Settings */
	mEngine.loadSettings(SETTINGS_LAYOUT, "layout.xml");
	mEngine.loadTextCfg("text.xml");

	mEngine.getRootSprite(0).clearChildren();
	mEngine.getRootSprite(1).clearChildren();
	mEngine.getRootSprite(2).clearChildren();

	ds::ui::Sprite &rootSprite = mEngine.getRootSprite();
	rootSprite.setTransparent(false);
	rootSprite.setColor(ci::Color(0.1f, 0.1f, 0.1f));

	
	BackgroundView* bg = new BackgroundView(mGlobals,  2000, 2000 );
	rootSprite.addChildPtr(bg);
	bg->show();
	bg->setPosition(0.0f, 0.0f);

	// add sprites
	MatricaModel m = MatricaModel(1, 16, 8, "triangle/", TriggerableVisual::kVisualPop, mGlobals.mColor_Green, mGlobals.mColor_Pink, mGlobals.mColor_Green);
	MatricaPanel *p = new MatricaPanel(mGlobals, m);
	rootSprite.addChildPtr(new MatricaController(mGlobals,p));
	rootSprite.addChildPtr(p);
	p->setColor(ci::Color(0.8f,0.8f,0.8f));

	VisualController *vc = new VisualController(mGlobals);
	rootSprite.addChildPtr(vc);
	vc->sendToFront();

	rootSprite.addChildPtr(new TransitionView(mGlobals));

}

void Matrica::update() {
	inherited::update();

	if( mEngine.isIdling() && !mIdling ){
		//Start idling
		mIdling = true;
		mEngine.getNotifier().notify( IdleStartedEvent() );
	} else if ( !mEngine.isIdling() && mIdling ){
		//Stop idling
		mIdling = false;
		mEngine.getNotifier().notify( IdleEndedEvent() );
	}

	mMetronome.update();

}

void Matrica::keyDown(ci::app::KeyEvent event){
	using ci::app::KeyEvent;
	inherited::keyDown(event);
	if(event.getChar() == KeyEvent::KEY_r){ // R = reload all configs and start over without quitting app
		setupServer();
	} else if(event.getCode() == KeyEvent::KEY_d){
		moveCamera(ci::Vec3f(1.0f, 0.0f, 0.0f));
	} else if(event.getCode() == KeyEvent::KEY_a){
		moveCamera(ci::Vec3f(-1.0f, 0.0f, 0.0f));
	} else if(event.getCode() == KeyEvent::KEY_w){
		moveCamera(ci::Vec3f(0.0f, -1.0f, 0.0f));
	} else if(event.getCode() == KeyEvent::KEY_s){
		moveCamera(ci::Vec3f(0.0f, 1.0f, 0.0f));
	} else if(event.getCode() == KeyEvent::KEY_RIGHTBRACKET){
		moveCamera(ci::Vec3f(0.0f, 0.0f, 1.0f));
	} else if(event.getCode() == KeyEvent::KEY_LEFTBRACKET){
		moveCamera(ci::Vec3f(0.0f, 0.0f, -1.0f));
	} else if(event.getCode() == KeyEvent::KEY_EQUALS){
		ds::PerspCameraParams p = mEngine.getPerspectiveCamera(1);
		p.mFarPlane += 1.0f;
		std::cout << "Clip Far camera: " << p.mFarPlane << std::endl;
		mEngine.setPerspectiveCamera(1, p);
	} else if(event.getCode() == KeyEvent::KEY_MINUS){
		ds::PerspCameraParams p = mEngine.getPerspectiveCamera(1);
		p.mFarPlane -= 1.0f;
		std::cout << "Clip Far camera: " << p.mFarPlane << std::endl;
		mEngine.setPerspectiveCamera(1, p);
	}
}

void Matrica::moveCamera(const ci::Vec3f& deltaMove){
	ds::PerspCameraParams p = mEngine.getPerspectiveCamera(1);
	p.mPosition += deltaMove;
	std::cout << "Moving camera: " << p.mPosition.x << " " << p.mPosition.y << " " << p.mPosition.z << std::endl;
	mEngine.setPerspectiveCamera(1, p);
}

} // namespace matrica

// This line tells Cinder to actually create the application
CINDER_APP_BASIC(matrica::Matrica, ci::app::RendererGl(ci::app::RendererGl::AA_MSAA_4))