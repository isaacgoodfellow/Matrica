#pragma once
#ifndef UI_PRIMITIVE_POOL
#define UI_PRIMITIVE_POOL

#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/sprite.h>

#include "visuals/triggerable_visual.h"

namespace matrica {

	class Globals;

	/**
	* \class Matrica::PrimitivePool
	* \brief A very basic (primitive) object pool. Purpose built for the triggerable visuals
	*/
	class PrimitivePool : public ds::ui::Sprite {
	public:

		PrimitivePool(Globals&);
		void add(TriggerableVisual* toAdd);
		void triggerNext();


	private:

		typedef ds::ui::Sprite		inherited;
		Globals&					mGlobals;

		std::vector<TriggerableVisual*> mVisuals;
		int mPoolIndex, mPoolSize;


	};

}

#endif // GUARD