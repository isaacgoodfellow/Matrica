#include "visuals/visual_test.h"

#include <ds/app/event_notifier.h>
#include <ds/ui/sprite/sprite_engine.h>
#include <ds/ui/tween/tweenline.h>

#include "app/app_defs.h"
#include "app/globals.h"
#include "events/app_events.h"
#include "ds/ui/sprite/sprite.h"
#include "ds/ui/sprite/util/blend.h"

#include <ds/ui/sprite/image.h>

#include "cinder/Rand.h"

#pragma warning(disable: 4355)

namespace matrica {

	/**
	* Matrica::VisualTest
	*/

	VisualTest::VisualTest(Globals& g)
		: inherited(g.mEngine)
		, mGlobals(g)
		, mPoolIndex(0)
		, mPoolSize(5)
		, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){

		setTransparent(false);
		enable(false);
		show();


		for (int i = 0; i < mPoolSize; ++i){

//			mBars.push_back(new ds::ui::Image(mGlobals.mEngine, "C:\\Projects\\Matrica\\data\\images\\trail.png"));
			mBars.push_back(new ds::ui::Sprite(mGlobals.mEngine));
		
			addChildPtr(mBars.back());
		}

	}

	void VisualTest::onAppEvent(const ds::Event& in_e) {


		mPoolIndex = (mPoolIndex + 1) % mPoolSize;
		ds::ui::Sprite* s = mBars[mPoolIndex];


			s->setTransparent(false);
			s->enable(false);
			s->show();

			float x = ci::Rand::randFloat(0, mGlobals.mEngine.getWorldWidth());
			float y = ci::Rand::randFloat(0, mGlobals.mEngine.getWorldHeight());
			s->setPosition(x,y);
			s->setSize(500, 50);
			s->setScale(ci::Rand::randFloat(0.4f, 3.0f), 1.0f);
			s->setCornerRadius(3.0f);
			s->setOpacity(1.0f);
			s->setRotation(ci::Vec3f(0.0f, 0.0f, ci::Rand::randFloat()));
			s->setCenter(0.5f, 0.5f);


			float dur = 0.9f;

			float r = ci::Rand::randFloat(-1.0f, 1.0f);

			float x2 = ci::Rand::randFloat(0, mGlobals.mEngine.getWorldWidth());
			float y2 = ci::Rand::randFloat(0, mGlobals.mEngine.getWorldHeight());

			s->tweenPosition( ci::Vec3f(x2,y2,0.0f) , dur , 0.0f, ci::EaseInOutCirc() );
			s->tweenRotation( getRotation() + ci::Vec3f(0.0f, 0.0f, r * 360.0f), dur, 0.0f, cinder::EaseInOutCirc());
			s->tweenOpacity(0.0f, dur, 0.0f, cinder::EaseInOutCirc());
			s->tweenScale(ci::Vec3f(5.0f,5.0f,5.0f), dur, 0.0f, cinder::EaseInOutCirc());
			s->sendToFront();

	}

} // namespace jci