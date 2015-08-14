#pragma once
#ifndef UI_MATRICA_CONTROLLER_H_
#define UI_MATRICA_CONTROLLER_H_

#include "matrica_panel.h"
#include "util/time_seconds.h"
#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>

#include "OscSender.h"

namespace matrica {

	class Globals;

	/*
	* \class matrica::MatricaController
	* \brief Superclass for all MatricaControllers
	*/

	class MatricaController : public ds::ui::Sprite {
	public:
		
		MatricaController(Globals& , const MatricaPanel* mc);

		void updateServer(const ds::UpdateParams& updateParams);

	private:

		int it_pos = 0;

		void onAppEvent(const ds::Event&);

		//Making this a friend to avoid a lot of function call overhead
		friend class MatricaPanel;

		typedef ds::ui::Sprite		inherited;
		Globals&					mGlobals;
		ds::EventClient				mEventClient;
		const MatricaPanel* mMatrica;

		ds::time::Seconds		mTimer;

		ci::osc::Sender sender;
		std::string		host;
		int 			port;

		float mLastFire;
		float time_between;

	};

}

#endif