#include "matrica_controller.h"
#include "app/globals.h"

namespace matrica{

	MatricaController::MatricaController( Globals& g,  const MatricaPanel* mc )
	: inherited(g.mEngine)
	, mGlobals(g)
	, mMatrica(mc)
	, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){
	}

	void MatricaController::updateServer(const ds::UpdateParams& updateParams){
		mTimer.elapsed();
	}

	void MatricaController::onAppEvent(const ds::Event& in_e) {

	}

	void onAppEvent(const ds::Event&){

	}


}