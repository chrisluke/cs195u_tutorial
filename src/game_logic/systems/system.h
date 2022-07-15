#ifndef SYSTEM_H
#define SYSTEM_H

#include "engine/util/CommonIncludes.h"

#include <QGLWidget>
#include <QApplication>
#include <QKeyEvent>
#include <QWindow>

using namespace std;
using namespace glm;

class GameObject;
class System
{
public:
    System();

    void addObj(std::shared_ptr<GameObject> gameObj);
    void removeObj();
    std::shared_ptr<GameObject> getObj(int pos);

    std::vector<std::shared_ptr<GameObject>> m_objlist;

};

#endif // SYSTEM_H
