#ifndef TICKSYSTEM_H
#define TICKSYSTEM_H

#include "system.h"

class TickSystem : public System
{
public:
    TickSystem();
    void tick(float seconds);

};

#endif // TICKSYSTEM_H
