#pragma once
#ifndef UI_MATRICA_BUTTON_H_
#define UI_MATRICA_BUTTON_H_

#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/sprite.h>

namespace matrica {
	class Globals;

	/**
	* \class Matrica::MatricaButton
	* \brief A button on the panel
	*/
	class MatricaButton : public ds::ui::Sprite {
	public:
		
		MatricaButton(Globals&);
		void						layout();
		void						fireLed();

		int							x, y;
		bool						mState;

	private:
		
		void						onAppEvent(const ds::Event&);
		void						handleTouch(const ds::ui::TouchInfo& touchInfo);
		void						setDown(bool in);
		bool						touchInside(const ci::Vec3f& point);

		void						changeState(bool in);

		typedef ds::ui::Sprite		inherited;
		Globals&					mGlobals;
		ds::EventClient				mEventClient;

		Sprite*						mLed;



	};

}

#endif // GUARD