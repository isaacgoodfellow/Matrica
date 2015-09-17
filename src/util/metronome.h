#pragma once
#ifndef UI_MATRICA_CONTROLLER_H_
#define UI_MATRICA_CONTROLLER_H_

#include "util/time_seconds.h"
#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>

#include "OscSender.h"

namespace matrica {

	class Globals;

	/*
	* \class matrica::Metronome
	* \brief Metronome and tempo notifier
	*/

	class Metronome : public ds::ui::Sprite {
	public:

		Metronome(Globals&);

		void updateServer(const ds::UpdateParams& updateParams);

	private:

		void onAppEvent(const ds::Event&);

		typedef ds::ui::Sprite		inherited;
		Globals&					mGlobals;
		ds::EventClient				mEventClient;

		ds::time::Seconds		mTimer;

		float mLastFire;
		float time_between;

	};

}

#endif