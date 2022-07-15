#ifndef TICKCOMPONENT_H
#define TICKCOMPONENT_H

#include "component.h"

class TickComponent : public Component
{
public:
    TickComponent();
    ~TickComponent() override;

    void tick(float seconds);
};

#endif // TICKCOMPONENT_H
