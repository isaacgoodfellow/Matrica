#include "matrica_controller.h"
#include "app/globals.h"
#include "matrica_button.h"
#include "events/app_events.h"

#include "cinder/Rand.h"

#include "OscSender.h"


namespace matrica{

	MatricaController::MatricaController( Globals& g,  const MatricaPanel* mc )
	: inherited(g.mEngine)
	, mGlobals(g)
	, mMatrica(mc)
	, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){
		mLastFire = 0.0f;
		time_between = 0.2f;

		host = "127.0.0.1";
		port = 9001;
		sender.setup(host, port, true);

	}

	void MatricaController::updateServer(const ds::UpdateParams& updateParams){
		//Polling for new, yuck
		if ((mTimer.elapsed() - mLastFire) > time_between){

			auto xrow = mMatrica->mButtons[it_pos];
			for( auto it = xrow.begin(); it != xrow.end(); ++it){	
				if ( (*it)->mState ){
					(*it)->fireLed();
					ci::osc::Message message;
					message.setAddress("/test");
					message.addIntArg(mMatrica->x_res - (*it)->y);
					sender.sendMessage(message);
					mGlobals.mEngine.getNotifier().notify(SawMessage());
				}
			}

			it_pos += 1;
			it_pos %= mMatrica->x_res;

			mLastFire = mTimer.elapsed();
		}
	}

	void MatricaController::onAppEvent(const ds::Event& in_e) {
		std::cout << "EVENT" << std::endl;
	}

	void onAppEvent(const ds::Event&){
	}


}