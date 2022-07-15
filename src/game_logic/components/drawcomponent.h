#ifndef DRAWCOMPONENT_H
#define DRAWCOMPONENT_H

#include "engine/graphics/Graphics.h"
#include "component.h"

class DrawComponent : public Component
{
public:
    DrawComponent();
    ~DrawComponent() override;

    void draw(Graphics *g);
};

#endif // DRAWCOMPONENT_H
