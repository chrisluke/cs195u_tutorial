#include "ticksystem.h"
#include "system.h"
#include "game_logic/gameobject.h"
#include "game_logic/components/component.h"
#include "game_logic/components/tickcomponent.h"

TickSystem::TickSystem()
{

}

void TickSystem::tick(float seconds)
{
    for (std::shared_ptr<GameObject> obj : m_objlist)
    {
        std::shared_ptr<TickComponent> tickComp = (std::shared_ptr<TickComponent>) obj->getComponent<TickComponent>();
        tickComp -> tick(seconds);
    }
}
