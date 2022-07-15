#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "engine/util/CommonIncludes.h"

#include <QGLWidget>
#include <QApplication>
#include <QKeyEvent>
#include <QWindow>

using namespace std;
using namespace glm;

class GameObject;
class System;
class GameWorld
{
public:
    GameWorld();
    ~GameWorld();
    void addSystem(std::string name, std::shared_ptr<System> system);
    void removeSystem(std::string name);
    System getSystem(std::string name);
    void addObj(std::string name, std::shared_ptr<GameObject> gameObj);
    void removeObj(std::string name);
    GameObject getObj(std::string name);


private:
    std::map<std::string, std::shared_ptr<GameObject>> m_objlist;
    std::map<std::string, std::shared_ptr<System>> m_systemlist;
};

#endif // GAMEWORLD_H
