#pragma once
#ifndef UI_SPINNING_RECT
#define UI_SPINNING_RECT

#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/sprite.h>
#include "visuals/triggerable_visual.h"


namespace matrica {

	class Globals;

	/**
	* \class Matrica::TrigSpinningRect
	* \brief A rectangle that spins and grows
	*/
	class TrigSpinningRect : public TriggerableVisual {

	public:

		TrigSpinningRect(Globals&);
		void trigger();
		void init();

	};

}

#endif // GUARD