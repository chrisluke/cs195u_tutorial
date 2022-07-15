#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H

#include "component.h"
#include "game_logic/gameobject.h"
#include "engine/util/CommonIncludes.h"

using namespace std;
using namespace glm;

class GameObject;
class CollisionComponent : public Component
{
public:
    CollisionComponent(float radius, float height, GameObject *gameObj);
    ~CollisionComponent() override;
    float m_radius;
    float m_height;
    GameObject *m_gameObj;
    void checkCollision(CollisionComponent otherObj);
    glm::vec3 calcInterval(float blue_pos, float blue_height, float red_pos, float red_height);

    void tick(float seconds);
};

#endif // COLLISIONCOMPONENT_H
