#include "visuals/triggerable/trig_box_slide.h"

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
	* Matrica::TrigBoxSlide
	*/

	TrigBoxSlide::TrigBoxSlide(Globals& g)
		: TriggerableVisual(g)
	{
		mType = kVisualBoxSlide;
		setSize(100, 100);
		for (int i = 0; i < 3; ++i){
			mSliders.push_back(new Sprite(mGlobals.mEngine));
			addChildPtr((mSliders.back()));
		}

	}

	void TrigBoxSlide::init(){

		setTransparent(false);
		enable(false);
		hide();

	}

	void TrigBoxSlide::trigger(){

		//Set the location of the explosion
		float x = ci::Rand::randFloat(0, mGlobals.mEngine.getWorldWidth());
		float y = ci::Rand::randFloat(0, mGlobals.mEngine.getWorldHeight());
		setTransparent(true);
		enable(false);
		show();
		setPosition(x, y);
		setRotation(ci::Vec3f::zero());
		setOpacity(1.0f);
		setScale(1.3f);

		float xp = 0.0f;
		int alternate = 0;
		for( auto it = mSliders.begin(); it != mSliders.end(); ++it){
			
			(*it)->setPosition(xp,0.0f);
			(*it)->setTransparent(false);
			(*it)->setOpacity(1.0f);
			(*it)->show();
			(*it)->setSize(33, 100);

			xp += (*it)->getWidth();
			ci::Vec3f npos = ci::Vec3f((*it)->getPosition().x, (*it)->getPosition().y + (*it)->getHeight()*-(alternate%2),0.0f);
			(*it)->tweenPosition(npos, 0.5f, 0.0f, ci::easeInCirc);
			alternate++;
		}

		float rot = ci::Rand::randFloat(-360, 360);
		tweenRotation(ci::Vec3f(0.0f,0.0f,rot), 1.0f, 0.0f, ci::EaseInCirc());
		tweenOpacity(0.0f, 0.5f, 0.0f, ci::EaseInCirc());

	}

} // namespace jci