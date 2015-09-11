#pragma once
#ifndef UI_POP
#define UI_POP

#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/sprite.h>
#include "visuals/triggerable_visual.h"

namespace matrica {

	class Globals;

	/**
	* \class Matrica::TrigPop
	* \brief a friendly burst
	*/
	class TrigPop : public TriggerableVisual {

	public:

		TrigPop(Globals&);
		void trigger();
		void init();

		ds::ui::Sprite* mBasePop;
		ds::ui::Sprite* mAccentPop;

		std::vector < ds::ui::Sprite*> mRays;

	};

}

#endif // GUARD