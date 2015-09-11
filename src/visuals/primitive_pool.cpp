#include "visuals/primitive_pool.h"

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
	* Matrica::PrimitivePool
	*/

	PrimitivePool::PrimitivePool(Globals& g)
		: inherited(g.mEngine)
		, mGlobals(g)
		, mPoolIndex(0)
		, mPoolSize(0)
	{

		setTransparent(false);
		enable(false);
		show();

	}

	void PrimitivePool::triggerNext(){

		if (mPoolIndex > mPoolSize){
			mPoolIndex = 0;
		}

		TriggerableVisual* tv = mVisuals[mPoolIndex];
		if (tv == NULL || tv == nullptr) return;
		tv->init();
		tv->trigger();
		mPoolIndex = (mPoolIndex + 1) % mPoolSize;

	}

	void PrimitivePool::add(TriggerableVisual* toAdd){
		mVisuals.push_back(toAdd);
		addChildPtr(toAdd);
		toAdd->init();
		mPoolSize++;
	}


} // namespace jci