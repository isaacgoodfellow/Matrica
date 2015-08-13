#ifndef _MATRICA_APP_QUERY_QUERYHANDLER_H_
#define _MATRICA_APP_QUERY_QUERYHANDLER_H_

#include <ds/app/event_client.h>
#include <ds/data/resource_list.h>
#include <ds/thread/serial_runnable.h>
#include <ds/ui/sprite/sprite_engine.h>
// NOTE: Placing this include at the top gets a conflict
// with cinder. Need to look into that.
#include <ds/network/node_watcher.h>
#include "model/all_data.h"

namespace matrica {

/**
 * \class matrica::QueryHandler
 * \brief Handle app events that deal with querying for data.
 */
class QueryHandler {
public:
	QueryHandler(ds::ui::SpriteEngine&, AllData&);

private:

	void								onAppEvent(const ds::Event&);

	ds::EventClient						mEventClient;

	// CACHING
	ds::ResourceList					mResources;
};

} // !namespace matrica

#endif // !_MATRICA_APP_QUERY_QUERYHANDLER_H_