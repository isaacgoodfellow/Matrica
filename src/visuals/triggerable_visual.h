#pragma once
#ifndef UI_TRIGGERABLE_VISUAL
#define UI_TRIGGERABLE_VISUAL


#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/sprite.h>

namespace matrica {

	class Globals;

	/**
	* \class Matrica::TriggerableVisual
	* \brief Abstract superclass for visuals that can be pooled and triggered
	*/
	class TriggerableVisual : public ds::ui::Sprite {
	public:

		enum VisualType {
			kVisualBase, kVisualPop, kVisualSpinningRect, kVisualBoxSlide
		};

		TriggerableVisual(Globals& g);
		virtual void trigger();
		virtual void init();
		VisualType mType;


	protected:
		typedef ds::ui::Sprite		inherited;
		Globals&					mGlobals;


	};

}

#endif // GUARD