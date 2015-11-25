#include "visuals/triggerable/trig_smoke_pop.h"

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
	* Matrica::TrigSmokePop
	*/

	TrigSmokePop::TrigSmokePop(Globals& g)
		: TriggerableVisual(g)
	{
		mType = kVisualSpinningRect;
	}

	void TrigSmokePop::init(){
		setTransparent(false);
		enable(false);
		show();
	}

	void TrigSmokePop::trigger(){

		setTransparent(false);
		enable(false);
		show();

		float x = ci::Rand::randFloat(0, mGlobals.mEngine.getWorldWidth());
		float y = ci::Rand::randFloat(0, mGlobals.mEngine.getWorldHeight());
		setPosition(x, y);
		setSize(500, 50);
		setScale(ci::Rand::randFloat(0.4f, 3.0f), 1.0f);
		setCornerRadius(3.0f);
		setOpacity(1.0f);
		setRotation(ci::Vec3f(0.0f, 0.0f, ci::Rand::randFloat()));
		setCenter(0.5f, 0.5f);

		float dur = 0.9f;

		float r = ci::Rand::randFloat(-1.0f, 1.0f);

		float x2 = ci::Rand::randFloat(0, mGlobals.mEngine.getWorldWidth());
		float y2 = ci::Rand::randFloat(0, mGlobals.mEngine.getWorldHeight());

		tweenPosition(ci::Vec3f(x2, y2, 0.0f), dur, 0.0f, ci::EaseInOutCirc());
		tweenRotation(getRotation() + ci::Vec3f(0.0f, 0.0f, r * 360.0f), dur, 0.0f, cinder::EaseInOutCirc());
		tweenOpacity(0.0f, dur, 0.0f, cinder::EaseInOutCirc());
		tweenScale(ci::Vec3f(5.0f, 5.0f, 5.0f), dur, 0.0f, cinder::EaseInOutCirc());
		sendToFront();

	}

} // namespace jci