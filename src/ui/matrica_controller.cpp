#include "matrica_controller.h"
#include "app/globals.h"
#include "matrica_button.h"
#include <ds/app/environment.h>

#include <cinder/app/App.h>

#include "events/app_events.h"
#include "events/time_events.h"
#include "events/instrument_events.h"

#include "cinder/Rand.h"

#include "OscSender.h"

#include <ds/app/event_notifier.h>

namespace matrica{

	MatricaController::MatricaController( Globals& g,  const MatricaPanel* mc, int divisor )
		: inherited(g.mEngine)
		, mGlobals(g)
		, mMatrica(mc)
		, mDivisor(divisor)
		, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); })
	{
	}

	//advance the step iterator and fire active steps
	void MatricaController::onTick(int tick){

		//A tick is a 64th note
		int newPos = tick / mDivisor;
		if (mItPos )

		auto xrow = mMatrica->mButtons[mItPos];
		(*xrow.begin())->showStep();
		for (auto it = xrow.begin(); it != xrow.end(); ++it){
			if ((*it)->mState){
				(*it)->fireLed();
				int note_no = mMatrica->y_res - (*it)->y;
				note_no -= 1;
				mGlobals.mEngine.getNotifier().notify( NoteFiredEvent( mMatrica->mModel , note_no));

				if (note_no < mVoice.size()){
					mVoice[note_no]->stop();
					mVoice[note_no]->setPan(0.5f);
					mVoice[note_no]->start();
				}

			}
		}

	}

	void MatricaController::onAppEvent(const ds::Event& in_e) {

		if (in_e.mWhat == MetroTickEvent::WHAT()){
			const MetroTickEvent& _e = dynamic_cast<const MetroTickEvent&>(in_e);
			onTick(_e.mTick);
		}
	}



}