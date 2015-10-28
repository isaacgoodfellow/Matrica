#pragma once
#ifndef UI_VISUAL_CONTROLLER
#define UI_VISUAL_CONTROLLER

#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/sprite.h>

#include "visuals/primitive_pool.h"
#include "visuals/triggerable_visual.h"


namespace matrica {

	class Globals;

	/**
	* \class Matrica::VisualController
	* \brief A patatap style visual controller
	*/
	class VisualController : public ds::ui::Sprite {
	public:

		VisualController(Globals&);

	private:

		void						onAppEvent(const ds::Event&);


		typedef ds::ui::Sprite		inherited;
		Globals&					mGlobals;
		ds::EventClient				mEventClient;

		PrimitivePool* mRectPool;

	};

}

#endif // GUARD