#pragma once
#ifndef UI_MATRICA_UTIL_METRONOME_H_
#define UI_MATRICA_UTIL_METRONOME_H_

#include "util/time_seconds.h"
#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>
#include "events/app_events.h"


#include "OscSender.h"

namespace matrica {

	class Globals;

	/*
	* \class matrica::Metronome
	* \brief Metronome and tempo notifier
	*/

	class Metronome {
	public:

		Metronome(Globals&);

		void update();

	private:

		Globals&					mGlobals;

		ds::time::Seconds		mTimer;
		float mLastFire;
		float mTimeBetween;

		int mTime;

	};

}

#endif