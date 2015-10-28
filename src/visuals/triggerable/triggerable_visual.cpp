#include "visuals/triggerable_visual.h"

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
	* Matrica::TriggerableVisual
	*/

	TriggerableVisual::TriggerableVisual(Globals& g)
		: inherited(g.mEngine)
		, mGlobals(g)
		, mType(TriggerableVisual::kVisualBase)
	{

		setTransparent(false);
		enable(false);
		show();

	}

	void TriggerableVisual::trigger(){

	}
	
	void TriggerableVisual::init(){

	}


} // namespace jci