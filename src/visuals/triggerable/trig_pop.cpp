#include "visuals/triggerable/trig_pop.h"

#include <ds/app/event_notifier.h>
#include <ds/ui/sprite/sprite_engine.h>
#include <ds/ui/tween/tweenline.h>
#include <ds/app/environment.h>
#include <ds/ui/sprite/image.h>

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
	* Matrica::TrigPop
	*/

	TrigPop::TrigPop(Globals& g)
		: TriggerableVisual(g)
	{
		setColor(ci::Color(0.0f,0.0f,0.0f));
		mBasePop = new ds::ui::Sprite(mGlobals.mEngine);
		mAccentPop = new ds::ui::Sprite(mGlobals.mEngine);

		addChildPtr(mBasePop);
		addChildPtr(mAccentPop);

		int sw = ci::Rand::randInt(3);
		for (int i = 0; i < 10; ++i){
			ds::ui::Image* di = new ds::ui::Image(mGlobals.mEngine);
			mRays.push_back(di);
//			mRays.push_back(new ds::ui::Sprite(mGlobals.mEngine));

			switch (sw)
			{
			case 0:
				di->setImageFile(ds::Environment::getAppFolder("data/images/", "comp_trail.png"));
				break;
			case 1:
				di->setImageFile(ds::Environment::getAppFolder("data/images/", "trail_white.png"));
				break;
			case 2:
				di->setImageFile(ds::Environment::getAppFolder("data/images/", "trail.png"));
				break;
			default:
				di->setImageFile(ds::Environment::getAppFolder("data/images/", "trail.png"));
				break;
			}
			
			
			
			addChildPtr(mRays.back());
			mRays.back()->setSize(40.0f, 5.0f);
			mRays.back()->setTransparent(false);
			mRays.back()->enable(false);
			mRays.back()->sendToFront();
		}

	}

	void TrigPop::init(){
		
		setTransparent(true);
		enable(false);
		hide();

		float s = ci::Rand::randFloat(1.0f, 2.0f);
		float s2 = ci::Rand::randFloat(1.0f, 2.0f);
		mBasePop->setSize(50.0f,50.0f);
		mBasePop->enable(false);
		mBasePop->setTransparent(false);
		mBasePop->show();
		mBasePop->setCenter(0.5f, 0.5f);
		mBasePop->setScale(s);
		mBasePop->setCornerRadius(mBasePop->getWidth()/2.0f);
		mBasePop->setOpacity(1.0f);
		
		mAccentPop->setSize(20.0f, 20.0f);
		mAccentPop->enable(false);
		mAccentPop->setTransparent(false);
		mAccentPop->show();
		mAccentPop->setCenter(0.5f, 0.5f);
		mAccentPop->setCornerRadius(mAccentPop->getWidth() / 2.0f);
		mAccentPop->setScale(s2);
		mAccentPop->setOpacity(1.0f);
		mAccentPop->setColor(ci::Color(0, 0, 0));


		for( auto it = mRays.begin(); it != mRays.end(); ++it){
			(*it)->setOpacity(1.0f);
			(*it)->setScale(ci::Vec3f(0.0f, 0.3f, 1.0f));
			(*it)->setCenter(1.0f, 0.5f);
			float r = ci::Rand::randFloat(0.0f, 360.0f);
			(*it)->setRotation(r);
		}

	}

	void TrigPop::trigger(){

		//Set the location of the explosion
		float x = ci::Rand::randFloat(0, mGlobals.mEngine.getWorldWidth());
		float y = ci::Rand::randFloat(0, mGlobals.mEngine.getWorldHeight());
		setTransparent(true);
		enable(false);
		show();
		setPosition(x, y);

		//set the scale of
		float dur = 0.9f;

		mBasePop->tweenOpacity(0.0f, dur, 0.0f, cinder::EaseOutCirc());
		float s = ci::Rand::randFloat(5.0f, 30.0f);
		mBasePop->tweenScale(ci::Vec3f(s,s,s), dur, 0.0f, cinder::EaseOutCirc());
		mBasePop->sendToFront();

		mAccentPop->tweenOpacity(0.0f, dur, 0.0f, cinder::EaseOutCirc());
		float s2 = ci::Rand::randFloat(5.0f, 30.0f);
		mAccentPop->tweenScale(ci::Vec3f(s2, s2, s2), dur, 0.0f, cinder::EaseOutCirc());
		mAccentPop->sendToFront();

		for( auto it = mRays.begin(); it != mRays.end(); ++it){
			float rs = ci::Rand::randFloat(4.0f, 10.0f);
			(*it)->show();
			(*it)->tweenOpacity(0.0f, dur, 0.0f, cinder::EaseOutCirc());
			(*it)->tweenScale(ci::Vec3f(rs, 0.3f, 1.0f), dur, 0.0f, cinder::EaseOutCirc());
		}

	}

} // namespace jci