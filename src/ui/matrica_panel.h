#pragma once
#ifndef UI_MATRICA_PANEL_H_
#define UI_MATRICA_PANEL_H_

#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>
#include "model/MatricaModel.h"

namespace matrica {
	class Globals;
	class MatricaButton;
	class MatricaModel;

	/**
	* \class Matrica::MatricaPanel
	* \brief One Panel of the matrica
	*/
	class MatricaPanel : public ds::ui::Sprite {
	
	public:

		MatricaPanel(Globals&, MatricaModel& model);
		void						animateOn(float scale = 1.0f);

	private:

		int x_res,y_res;

		friend class MatricaController;
		friend class MatricaTouchGrabber;

		MatricaTouchGrabber*		mTouchGrabber;

		void						onAppEvent(const ds::Event&);


		typedef ds::ui::Sprite		inherited;
		Globals&					mGlobals;
		ds::EventClient				mEventClient;
		MatricaModel				mModel;

		std::vector<std::vector<MatricaButton*> > mButtons;

	};

} 

#endif // GUARD