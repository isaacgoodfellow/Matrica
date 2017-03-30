#ifndef _MATRICA_APP_APPDEFS_H_
#define _MATRICA_APP_APPDEFS_H_

#include <string>
#include <ds/util/bit_mask.h>

namespace matrica {
extern const ds::BitMask		APP_LOG;

// SETTINGS
extern const std::string&		SETTINGS_APP;


// PHYSICS
// Front layer: 0, Back layer: highest number
extern const int				PHYSICS_INDUSTRIES_LAYER_0_CATEGORY;
extern const int				PHYSICS_INDUSTRIES_LAYER_1_CATEGORY;
extern const int				PHYSICS_INDUSTRIES_LAYER_2_CATEGORY;
extern const int				PHYSICS_INDUSTRIES_LAYER_3_CATEGORY;

} // !namespace matrica

#endif // !_MATRICA_APP_APPDEFS_H_