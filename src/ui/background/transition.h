#pragma once
#ifndef UI_TRANSITION_VIEW_H_
#define UI_TRANSITION_VIEW_H_

#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/sprite.h>

namespace matrica {

	class Globals;

	/**
	* \class Matrica::TransitionView
	* \brief the dramatic fade in at the start
	*/
	class TransitionView : public ds::ui::Sprite {

	public:

		TransitionView(Globals&);

	private:

		typedef ds::ui::Sprite		inherited;
		Globals&					mGlobals;

	};

}

#endif // GUARD