#include "gameworld.h"
#include "gameobject.h"

GameWorld::GameWorld()
{

}


void GameWorld::addObj(std::string name, std::shared_ptr<GameObject> obj)
{
    m_objlist.insert({name, obj});
}

void GameWorld::removeObj(std::string name)
{
    m_objlist.erase(name);
}

GameObject GameWorld::getObj(std::string name)
{
    return *m_objlist.find(name)->second;
}
