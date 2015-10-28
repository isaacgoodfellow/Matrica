#include "visuals/visual_controller.h"

#include <ds/app/event_notifier.h>
#include "ds/ui/sprite/sprite.h"
#include <ds/ui/sprite/sprite_engine.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/util/blend.h>

#include <ds/ui/tween/tweenline.h>

#include "app/app_defs.h"
#include "app/globals.h"
#include "events/app_events.h"
#include "events/instrument_events.h"
#include "model/MatricaModel.h"
#include "visuals/triggerable_visual.h"
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
		, mBoxPool(new PrimitivePool(g))
		, mPopPool(new PrimitivePool(g))
		, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){

		setTransparent(true);
		enable(false);
		show();
		setSize(mGlobals.mEngine.getWorldWidth(), mGlobals.mEngine.getWorldHeight());

		addChildPtr(mRectPool);
		addChildPtr(mBoxPool);
		addChildPtr(mPopPool);

		//todo: remove this placeholder pool filler
		for (int i = 0; i < 10; ++i){
			mRectPool->add(new TrigSpinningRect(mGlobals));
			mPopPool->add(new TrigPop(mGlobals));
			mBoxPool->add(new TrigBoxSlide(mGlobals));
		}

		sendToFront();

	}

	void VisualController::onAppEvent(const ds::Event& in_e) {
		if (in_e.mWhat == NoteFiredEvent::WHAT()){
			NoteFiredEvent& nf = NoteFiredEvent((NoteFiredEvent&)in_e);
			switch (nf.mModel.getVisualType())
			{

			case TriggerableVisual::kVisualPop:
				mPopPool->triggerNext();
				break;

			case TriggerableVisual::kVisualSpinningRect:
				mRectPool->triggerNext();
				break;

			case TriggerableVisual::kVisualBoxSlide:
				mBoxPool->triggerNext();
				break;

			default:
				break;
			}
		}
	}

} // namespace jci