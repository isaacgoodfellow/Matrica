#ifndef _MATRICA_APP_GLOBALS_
#define _MATRICA_APP_GLOBALS_

#include <ds/app/event_notifier.h>
#include <ds/cfg/cfg_text.h>
#include <ds/cfg/settings.h>
#include <ds/cfg/cfg_nine_patch.h>
#include <ds/ui/sprite/sprite_engine.h>

#include "model/all_data.h"

namespace ds {
namespace ui {
class SpriteEngine;
} // namespace ui
} // namespace ds

namespace matrica {

/**
 * \class matrica::Globals
 * \brief Global data for the app.
 */
class Globals {
public:
	Globals(ds::ui::SpriteEngine&, const AllData& d);

	ds::ui::SpriteEngine&			mEngine;
	ds::EventNotifier				mNotifier;

	//Shortcuts
	const ds::cfg::Text&			getText(const std::string& name) const;
	const ds::cfg::Settings&		getSettingsLayout() const;
	const ds::cfg::Settings&		getSettings(const std::string& name) const;

	ci::Color				mColor_Green;
	ci::Color				mColor_Pink;

};

} // !namespace matrica

#endif // !_MATRICA_APP_GLOBALS_