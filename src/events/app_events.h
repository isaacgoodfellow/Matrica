#ifndef _MATRICA_APP_APPEVENTS_H_
#define _MATRICA_APP_APPEVENTS_H_

#include <ds/app/event.h>

namespace matrica {

class IdleStartedEvent : public ds::RegisteredEvent < IdleStartedEvent > {
public:
	IdleStartedEvent(){};
};

class SawMessage : public ds::RegisteredEvent < SawMessage > {
public:
	SawMessage(){ };
};

class IdleEndedEvent : public ds::RegisteredEvent < IdleEndedEvent > {
public:
	IdleEndedEvent(){};

};

} // !namespace matrica

#endif // !_MATRICA_APP_APPEVENTS_H_