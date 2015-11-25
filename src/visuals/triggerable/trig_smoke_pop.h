#pragma once
#ifndef UI_SMOKE_POP
#define UI_SMOKE_POP

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
	class TrigSmokePop : public TriggerableVisual {

	public:

		TrigSmokePop(Globals&);
		void trigger();
		void init();

	};

}

#endif // GUARD