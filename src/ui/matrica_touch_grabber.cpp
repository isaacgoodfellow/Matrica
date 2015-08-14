#include "ui/matrica_panel.h"
#include "ui/matrica_touch_grabber.h"

#include <ds/app/engine/engine_cfg.h>
#include <ds/app/environment.h>
#include <ds/app/event_notifier.h>
#include <ds/debug/debug_defines.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/sprite_engine.h>
#include <ds/ui/tween/tweenline.h>
#include "app/app_defs.h"
#include "app/globals.h"
#include "ui/matrica_button.h"

#pragma warning(disable: 4355)

namespace matrica {

	/**
	* Matrica::MatricaTouchGrabber
	*/

	MatricaTouchGrabber::MatricaTouchGrabber(Globals& g, MatricaPanel* mp)
		: inherited(g.mEngine)
		, mGlobals(g)
		, mMatrica(mp)
		, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){

		setTransparent(false);
		setOpacity(0.3f);

		setProcessTouchCallback([this](ds::ui::Sprite *sprite, const ds::ui::TouchInfo &touchInfo) {
			this->handleTouch(touchInfo);
		});

	}

	void MatricaTouchGrabber::handleTouch(const ds::ui::TouchInfo& touchInfo){

		std::cout << "Blah" << std::endl;
	}


	void MatricaTouchGrabber::onAppEvent(const ds::Event& in_e) {

	}

} // namespace jci