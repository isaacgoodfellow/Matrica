#pragma once
#ifndef UI_MATRICA_BUTTON_H_
#define UI_MATRICA_BUTTON_H_

#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/sprite.h>

namespace matrica {

	class Globals;

	/**
	* \class Matrica::VisualTest
	* \brief A patatap style visual blip test
	*/
	class VisualTest : public ds::ui::Sprite {
	public:

		VisualTest(Globals&);


	private:

		void						onAppEvent(const ds::Event&);


		typedef ds::ui::Sprite		inherited;
		Globals&					mGlobals;
		ds::EventClient				mEventClient;


		std::vector<ds::ui::Sprite*> mBars;
		int mPoolIndex, mPoolSize;


	};

}

#endif // GUARD