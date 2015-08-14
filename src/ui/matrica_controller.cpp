#include "matrica_controller.h"
#include "app/globals.h"
#include "matrica_button.h"

#include "cinder/Rand.h"

#include "OscSender.h"


namespace matrica{

	MatricaController::MatricaController( Globals& g,  const MatricaPanel* mc )
	: inherited(g.mEngine)
	, mGlobals(g)
	, mMatrica(mc)
	, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){
		mLastFire = 0.0f;
		time_between = 0.4f;

		host = "127.0.0.1";
		port = 9001;
		sender.setup(host, port, true);

	}

	void MatricaController::updateServer(const ds::UpdateParams& updateParams){
		//Polling for new, yuck
		if ((mTimer.elapsed() - mLastFire) > time_between){
			for( auto it = mMatrica->mButtons.begin(); it != mMatrica->mButtons.end(); ++it){
				if ( (*it)->x == it_pos && (*it)->mState){
					(*it)->fireLed();
					ci::osc::Message message;
					message.setAddress("/test");
					message.addIntArg(mMatrica->x_res-(*it)->y);
					sender.sendMessage(message);
				}
			}

			it_pos += 1;
			it_pos %= mMatrica->x_res;

			mLastFire = mTimer.elapsed();
		}
	}

	void MatricaController::onAppEvent(const ds::Event& in_e) {
	}

	void onAppEvent(const ds::Event&){
	}


}