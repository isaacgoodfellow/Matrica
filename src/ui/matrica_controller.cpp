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

	MatricaController::MatricaController( Globals& g,  const MatricaPanel* mc, MatricaModel model )
		: inherited(g.mEngine)
		, mGlobals(g)
		, mModel(model)
		, mMatrica(mc)
		, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); })
		, mDivisor(model.getDivisor())
	{
		mXRes = model.getXRes();
		mYRes = model.getYRes();
	}

	//advance the step iterator and fire active steps
	void MatricaController::onTick(int tick){

		if (!mMatrica) return;

		//A tick is a 64th note
		int newPos = tick / mDivisor;
		newPos %= mXRes;
		if (mItPos == newPos) return;
		mItPos = newPos;

		for (int y = 0; y < mYRes; ++y){
			mMatrica->showStep(mItPos,y);
			if (mMatrica->getState(newPos, y)){
				int note_no = mYRes - y;
				note_no -= 1;
				mGlobals.mEngine.getNotifier().notify(NoteFiredEvent(mModel, note_no));
				mMatrica->fireLed(mItPos, y);
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