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

	private:

		int it_pos = 0;

		void onAppEvent(const ds::Event&);
		void onTick();

		friend class MatricaPanel;

		typedef ds::ui::Sprite		inherited;
		Globals&					mGlobals;
		ds::EventClient				mEventClient;
		const MatricaPanel* mMatrica;

	};

}

#endif