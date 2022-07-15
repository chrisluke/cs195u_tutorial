#include "drawsystem.h"
#include "system.h"
#include "game_logic/gameobject.h"
#include "game_logic/components/component.h"
#include "game_logic/components/drawcomponent.h"

DrawSystem::DrawSystem()
{

}

void DrawSystem:: draw(Graphics *g)
{
    for (std::shared_ptr<GameObject> obj : m_objlist)
    {
        std::shared_ptr<DrawComponent> drawComp = (std::shared_ptr<DrawComponent>) obj->getComponent<DrawComponent>();
        drawComp->draw(g);
    }
}

