#include "ui/matrica_button.h"

#include <ds/app/engine/engine_cfg.h>
#include <ds/app/environment.h>
#include <ds/app/event_notifier.h>
#include <ds/debug/debug_defines.h>
#include <ds/ui/sprite/sprite_engine.h>
#include <ds/ui/tween/tweenline.h>

#include "app/app_defs.h"
#include "app/globals.h"
#include "ds/ui/sprite/sprite.h"
#include "ds/ui/sprite/util/blend.h"

#pragma warning(disable: 4355)

namespace matrica {

	/**
	* Matrica::MatricaButton
	*/

	MatricaButton::MatricaButton(Globals& g)
		: inherited(g.mEngine)
		, mGlobals(g)
		, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){

		setTransparent(false);
		enable(true);

		setProcessTouchCallback([this](ds::ui::Sprite *sprite, const ds::ui::TouchInfo &touchInfo) {
			this->handleTouch(touchInfo);
		});
		setDown(false);

		mLed = new Sprite(mGlobals.mEngine);
		addChildPtr(mLed);
		mLed->setPosition(0.0f, 0.0f);
		mLed->setColor(0.0f, 1.0f, 0.69f);

		mLed->setTransparent(false);
		mLed->enable(false);

		mLed->setScale(0.0f);
		mLed->setOpacity(0.0f);

		changeState(false);

	}

	void MatricaButton::layout(){
		mLed->setSize(getWidth() / 2.0f, getHeight() / 2.0f);
		mLed->setCenter(0.5f, 0.5f);
		mLed->setPosition(getWidth() / 2.0f, getHeight() / 2.0f);
	}

	void MatricaButton::setDown(bool in){

	}

	bool MatricaButton::touchInside(const ci::Vec3f& point) {
		ci::Vec3f localPoint = globalToLocal(point);
		if (localPoint.x >= 0.0f && localPoint.x <= getWidth() && localPoint.y >= 0 && localPoint.y <= getHeight())
			return true;
		return false;
	}

	void MatricaButton::handleTouch(const ds::ui::TouchInfo& touchInfo){
		if (touchInfo.mPhase == ds::ui::TouchInfo::Added) {
			setDown(true);
		}	else if (touchInfo.mPhase == ds::ui::TouchInfo::Moved) {
			setDown(true);
		}	else if (touchInfo.mPhase == ds::ui::TouchInfo::Removed) {
			setDown(false);
			changeState(!mState);
		}
	}

	void MatricaButton::fireLed(){

		mLed->setOpacity(1.0f);
		mGlobals.mEngine.getTweenline().apply(*mLed, ANIM_OPACITY(), 0.0f, 0.3f);
		
		float scale_amnt = 3.0f;
		mLed->setScale(scale_amnt);
		mGlobals.mEngine.getTweenline().apply(*mLed, ANIM_SCALE(), ci::Vec3f(0.0f,0.0f,0.0f), 0.3f);

		float rot_amnt = 180.0f;//Rand::randBool() ? -180.f : 180.f;
		mLed->setRotation(0.0f);
		mGlobals.mEngine.getTweenline().apply(*mLed, ANIM_ROTATION(), ci::Vec3f( 0.0f , 0.0f , rot_amnt ), 0.3f);

	}

	void MatricaButton::changeState(bool in){

		if (!mLed) return;

		mState = in;
		mLed->sendToFront();
		mLed->setSize(getWidth() / 2.0f, getWidth() / 2.0f);

		if (in){
			setColor(ci::Color(.8f, .8f, .8f));
			fireLed();
		}	else {
			setColor(ci::Color(0.1f, 0.1f, 0.1f));
		}
	}

	void MatricaButton::onAppEvent(const ds::Event& in_e) {


	}

} // namespace jci