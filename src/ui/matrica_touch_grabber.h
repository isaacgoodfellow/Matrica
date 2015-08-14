#pragma once
#ifndef UI_MATRICA_TOUCH_GRABBER_H_
#define UI_MATRICA_TOUCH_GRABBER_H_

#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>

namespace matrica {
	class Globals;
	class MatricaButton;
	class MatricaPanel;

	/**
	* \class Matrica::MatricaTouchGrabber
	* \brief Transparent overlay for controlling touch on the matrica
	*/

	//This class exists so that you can drag your finger across the panel and it will enable things
	//without it touch just kind of sucks

	class MatricaTouchGrabber: public ds::ui::Sprite {
	public:

		MatricaTouchGrabber(Globals& g, MatricaPanel* mp);

	private:

		friend class MatricaPanel;

		void						handleTouch(const ds::ui::TouchInfo& touchInfo);

		void						onAppEvent(const ds::Event&);

		const MatricaPanel*			mMatrica;

		typedef ds::ui::Sprite		inherited;
		Globals&					mGlobals;
		ds::EventClient				mEventClient;

	};

}

#endif // GUARD