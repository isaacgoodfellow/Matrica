#include "metronome.h"
#include "app/globals.h"
#include "events/app_events.h"
#include "events/time_events.h"

#include "cinder/Rand.h"

#include "OscSender.h"


namespace matrica{

	Metronome::Metronome(Globals& g)
		: inherited(g.mEngine)
		, mGlobals(g)
		, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){

		mLastFire = 0.0f;
		time_between = 0.2f;

	}

	void Metronome::updateServer(const ds::UpdateParams& updateParams){

		//Polling for new, yuck
		if ((mTimer.elapsed() - mLastFire) > time_between){
			mGlobals.mEngine.getNotifier().notify(MetroTickEvent());
			mLastFire = (float)mTimer.elapsed();
		}

	}

	void Metronome::onAppEvent(const ds::Event& in_e) {
	}

}