#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "engine/util/CommonIncludes.h"
#include "engine/util/TypeMap.h"
#include "components/component.h"

#include <QGLWidget>
#include <QApplication>
#include <QKeyEvent>
#include <QWindow>

using namespace std;
using namespace glm;

class GameObject
{
public:
    GameObject():
        m_componentlist(TypeMap<std::shared_ptr<Component>>())
    {

    }

    ~GameObject()
    {

    }

    template<typename Component>
    void addComponent(std::shared_ptr<Component> &&c){
        m_componentlist.put<Component>(std::forward<std::shared_ptr<Component>>(c));
    };

    template<typename Component>
    void removeComponent(){
        m_componentlist.remove<Component>();
    }

    template<typename Component>
    std::shared_ptr<Component> getComponent(){
        auto it = m_componentlist.find<Component>();
        return std::static_pointer_cast<Component>(it->second);
    }

    glm::vec3 m_pos;

protected:
    TypeMap<std::shared_ptr<Component>> m_componentlist;

};

#endif // GAMEOBJECT_H
