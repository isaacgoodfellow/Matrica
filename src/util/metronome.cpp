#include "metronome.h"
#include "app/globals.h"
#include "events/time_events.h"
#include <ds/app/event_notifier.h>


namespace matrica{

	Metronome::Metronome(Globals& g)
		: mGlobals(g){
		mLastFire = 0.0f;
		mTimeBetween = 0.2f;
		mTime = 0;
	}

	void Metronome::update(){
		if ((mTimer.elapsed() - mLastFire) > mTimeBetween){
			mTime = (mTime + 1) % 64;
			mGlobals.mEngine.getNotifier().notify(MetroTickEvent(mTime));
			mLastFire = (float)mTimer.elapsed();
		}

	}

}