#pragma once
#ifndef UI_BOX_SLIDE
#define UI_BOX_SLIDE

#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/sprite.h>
#include "visuals/triggerable_visual.h"

namespace matrica {

	class Globals;

	/**
	* \class Matrica::TrigPop
	* \brief a box appears and slides apart
	*/
	class TrigBoxSlide : public TriggerableVisual {

	public:

		TrigBoxSlide(Globals&);
		void trigger();
		void init();

		std::vector < ds::ui::Sprite*> mSliders;

	};

}

#endif // GUARD