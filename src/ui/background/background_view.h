#pragma once
#ifndef UI_BACKGROUND_VIEW_H_
#define UI_BACKGROUND_VIEW_H_

#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/sprite.h>


namespace matrica {

	class Globals;

	/**
	* \class Matrica::BackgroundView
	* \brief the background view
	*/
	class BackgroundView : public ds::ui::Sprite {

	public:

		BackgroundView(Globals&, float x, float y);

	private:

		typedef ds::ui::Sprite		inherited;
		ds::ui::Image&				mShadeImg;
		Globals&					mGlobals;


	};

}

#endif // GUARD