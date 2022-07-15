#ifndef DRAWSYSTEM_H
#define DRAWSYSTEM_H

#include "system.h"
#include "engine/graphics/Graphics.h"

class DrawSystem : public System
{
public:
    DrawSystem();
    void draw(Graphics *g);

};

#endif // DRAWSYSTEM_H
