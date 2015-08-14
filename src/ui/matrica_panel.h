#pragma once
#ifndef UI_MATRICA_PANEL_H_
#define UI_MATRICA_PANEL_H_

#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>

namespace matrica {
	class Globals;
	class MatricaButton;

	/**
	* \class Matrica::MatricaPanel
	* \brief One Panel of the matrica
	*/
	class MatricaPanel : public ds::ui::Sprite {
	public:
		MatricaPanel(Globals&);

	private:

		int x_res;

		friend class MatricaController;

		void						onAppEvent(const ds::Event&);

		typedef ds::ui::Sprite		inherited;
		Globals&					mGlobals;
		ds::EventClient				mEventClient;

		std::vector<MatricaButton*> mButtons;

	};

} 

#endif // GUARD