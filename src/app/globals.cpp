#include "globals.h"

#include <Poco/String.h>

#include <ds/app/engine/engine_cfg.h>
#include <ds/app/environment.h>
#include <ds/cfg/settings.h>

#include "app_defs.h"

namespace matrica {

/**
 * \class matrica::Globals
 */
Globals::Globals(ds::ui::SpriteEngine& e , const AllData& d )
		: mEngine(e)
		, mAllData(d)
		, mAnimationDuration(0.35f)
{

	mColor_Green = ci::Color8u(85, 106, 91);
	mColor_Pink = ci::Color8u(222, 172, 171);
	mColor_Yellow = ci::Color8u(255, 234, 129);
	mColor_Blue = ci::Color8u(54, 179, 223);

}

const float Globals::getAnimDur(){
	return mAnimationDuration;
}

void Globals::initialize(){
	mAnimationDuration = getAppSettings().getFloat("animation:duration", 0, mAnimationDuration);
}

const ds::cfg::Settings& Globals::getSettings(const std::string& name) const {
	return mEngine.getEngineCfg().getSettings(name);
}

const ds::cfg::Settings& Globals::getAppSettings() const {
	return mEngine.getEngineCfg().getSettings(SETTINGS_APP);
}


const ds::cfg::Text& Globals::getText(const std::string& name) const {
	return mEngine.getEngineCfg().getText(name);

}



} // !namespace matrica
