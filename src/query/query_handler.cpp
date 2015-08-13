#include "query_handler.h"

#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <cinder/Json.h>
#include <ds/app/event_notifier.h>
#include <ds/debug/logger.h>
#include "app/app_defs.h"
#include "app/globals.h"

namespace matrica {

/**
 * \class matrica::QueryHandler
 */
QueryHandler::QueryHandler(ds::ui::SpriteEngine& se, AllData &ad)
		: mEventClient(se.getNotifier(), [this](const ds::Event* e){if (e) onAppEvent(*e); })
{


}

void QueryHandler::onAppEvent(const ds::Event& _e) {
}



} // !namespace matrica
