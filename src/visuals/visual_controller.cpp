#include "visuals/visual_controller.h"

#include <ds/app/event_notifier.h>
#include <ds/ui/sprite/sprite_engine.h>
#include <ds/ui/tween/tweenline.h>

#include "app/app_defs.h"
#include "app/globals.h"
#include "events/app_events.h"
#include "events/instrument_events.h"
#include "ds/ui/sprite/sprite.h"
#include "ds/ui/sprite/util/blend.h"

#include <ds/ui/sprite/image.h>

#include "cinder/Rand.h"

#include "visuals/triggerable/trig_spinning_rect.h"
#include "visuals/triggerable/trig_pop.h"
#include "visuals/triggerable/trig_box_slide.h"

#pragma warning(disable: 4355)

namespace matrica {

	/**
	* Matrica::VisualController
	*/

	VisualController::VisualController(Globals& g)
		: inherited(g.mEngine)
		, mGlobals(g)
		, mRectPool(new PrimitivePool(g))
		, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){

		setTransparent(true);
		enable(false);
		show();
		setSize(mGlobals.mEngine.getWorldWidth(), mGlobals.mEngine.getWorldHeight());

		addChildPtr(mRectPool);


		//todo: remove this placeholder pool filler
		for (int i = 0; i < 10; ++i){

//			mRectPool->add(new TrigBoxSlide(mGlobals));
 			if (ci::Rand::randBool()){
 				mRectPool->add(new TrigSpinningRect(mGlobals));
 			}	else {
 				mRectPool->add(new TrigPop(mGlobals));
 			}
		}

		sendToFront();

	}

	void VisualController::onAppEvent(const ds::Event& in_e) {
		if (in_e.mWhat == NoteFiredEvent::WHAT()){
			mRectPool->triggerNext();
		}
	}

} // namespace jci