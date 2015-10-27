#include "matrica_controller.h"
#include "app/globals.h"
#include "matrica_button.h"

#include "events/app_events.h"
#include "events/time_events.h"
#include "events/instrument_events.h"

#include "cinder/Rand.h"

#include "OscSender.h"


namespace matrica{

	MatricaController::MatricaController( Globals& g,  const MatricaPanel* mc )
	: inherited(g.mEngine)
	, mGlobals(g)
	, mMatrica(mc)
	, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){

	}

	//advance the step iterator and fire active steps
	void MatricaController::onTick(){
		auto xrow = mMatrica->mButtons[it_pos];
		(*xrow.begin())->showStep();
		for (auto it = xrow.begin(); it != xrow.end(); ++it){
			if ((*it)->mState){
				(*it)->fireLed();
				int note_no = mMatrica->y_res - (*it)->y;
				mGlobals.mEngine.getNotifier().notify( NoteFiredEvent( "triangle", note_no));
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