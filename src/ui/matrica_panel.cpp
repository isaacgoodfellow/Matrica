#include "ui/matrica_panel.h"

#include <ds/app/engine/engine_cfg.h>
#include <ds/app/environment.h>
#include <ds/app/event_notifier.h>
#include <ds/debug/debug_defines.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/sprite_engine.h>
#include <ds/ui/tween/tweenline.h>
#include "app/app_defs.h"
#include "app/globals.h"
#include "ui/matrica_button.h"

#pragma warning(disable: 4355)

namespace matrica {
	
	/**
	* Matrica::MatricaPanel
	*/

	MatricaPanel::MatricaPanel(Globals& g)
		: inherited(g.mEngine)
		, mGlobals(g)
		, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){

		setColor(ci::Color(1.0f,0.0f, 0.6f));
//		setColor(ci::Color(0.0f, 1.0f, 0.69f));

		ci::Vec2f pos = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getSize("matrica:panel:position");
		ci::Vec2f size = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getSize("matrica:panel:size");
		ci::Vec2f button_area = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getSize("matrica:panel:button:area");
		float cornerRad = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getFloat("matrica:panel:corner:radius");

		setPosition(pos.x,pos.y);
		setSize(size);
		setCornerRadius(cornerRad);
		setTransparent(false);
		enable(true);

		int n_buttons = 8;

		float button_gutter_x = size.x - button_area.x;
		float button_gutter_y = size.y - button_area.y;

		float xp = button_gutter_x;
		float yp = button_gutter_y;


		float max_width = button_area.x / n_buttons;
		
		float button_size = max_width;
		if (max_width > 20){
			button_size -= 20;
		}

		float button_pad = 20;

		for (int x = 0; x < n_buttons; x++){
			for (int y = 0; y < n_buttons; y++){
				MatricaButton *p = new MatricaButton(mGlobals);
				addChildPtr(p);
				p->setSize(button_size, button_size);
				p->setCornerRadius(button_size * 0.1);
				p->setPosition(xp, yp);
				p->layout();
				yp += button_size;
				yp += button_pad;
			}
			yp = button_gutter_y;
			xp += button_size;
			xp += button_pad;
		}

	}

	void MatricaPanel::onAppEvent(const ds::Event& in_e) {

	
	}

} // namespace jci