#include "metronome.h"
#include "app/globals.h"
#include "events/time_events.h"
#include <ds/app/event_notifier.h>


namespace matrica{

	Metronome::Metronome(Globals& g)
		: mGlobals(g){
		mLastFire = 0.0f;
		mTimeBetween = 0.2f;
	}

	void Metronome::update(){
		if ((mTimer.elapsed() - mLastFire) > mTimeBetween){
			mGlobals.mEngine.getNotifier().notify(MetroTickEvent());
			mLastFire = (float)mTimer.elapsed();
		}

	}

}