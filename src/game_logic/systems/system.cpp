#include "system.h"
#include "game_logic/gameobject.h"

System::System():
    m_objlist(std::vector<shared_ptr<GameObject>>())
{

}

void System::addObj(std::shared_ptr<GameObject> obj)
{
    m_objlist.push_back(obj);
}

void System::removeObj()
{
    m_objlist.pop_back();
}

std::shared_ptr<GameObject> System::getObj(int pos)
{
    return m_objlist.at(pos);
}

