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

	MatricaController::MatricaController( Globals& g,  const MatricaPanel* mc )
	: inherited(g.mEngine)
	, mGlobals(g)
	, mMatrica(mc)
	, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){

		mVoice.push_back(ci::audio::Voice::create(ci::audio::load(ci::app::loadAsset("kick_ish.wav"))));
		mVoice.push_back(ci::audio::Voice::create(ci::audio::load(ci::app::loadAsset("dink.wav"))));
		mVoice.push_back(ci::audio::Voice::create(ci::audio::load(ci::app::loadAsset("bttn2.wav"))));
		mVoice.push_back(ci::audio::Voice::create(ci::audio::load(ci::app::loadAsset("pwr_dwn.wav"))));

	}

	//advance the step iterator and fire active steps
	void MatricaController::onTick(){
		auto xrow = mMatrica->mButtons[it_pos];
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

		it_pos++;
		it_pos %= mMatrica->x_res;
	}

	void MatricaController::onAppEvent(const ds::Event& in_e) {
		if (in_e.mWhat == MetroTickEvent::WHAT()){
			onTick();
		}
	}



}