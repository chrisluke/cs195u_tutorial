#include "collisioncomponent.h"



CollisionComponent::CollisionComponent(float radius, float height, GameObject *gameObj)
{
    m_radius = radius;
    m_height = height;
    m_gameObj = gameObj;
}

CollisionComponent::~CollisionComponent()
{

}

glm::vec3 CollisionComponent::calcInterval(float blue_pos, float blue_height, float red_pos, float red_height)
{
    float aRight = (blue_pos + blue_height) - red_pos;
    float aLeft = (red_pos + red_height) - blue_pos;
    if (aRight < aLeft)
    {
        return glm::vec3(0, aRight, 0);
    }
    else
    {
        return glm::vec3(0, -aLeft, 0);
    }
}

void CollisionComponent::checkCollision(CollisionComponent otherObj)
{
    glm::vec3 circle_mtv = glm::vec3(std::numeric_limits<float>::infinity(), 0, 0);
    glm::vec3 height_mtv = glm::vec3(std::numeric_limits<float>::infinity(), 0, 0);
    glm::vec3 blue_posCircle = glm::vec3(m_gameObj->m_pos.x, 0, m_gameObj->m_pos.z);
    glm::vec3 red_posCircle = glm::vec3(otherObj.m_gameObj->m_pos.x, 0, otherObj.m_gameObj->m_pos.z);
    float blue_posLine = m_gameObj->m_pos.y;
    float red_posLine = otherObj.m_gameObj->m_pos.y;
    float pos_distance = glm::distance(blue_posCircle, red_posCircle);
    if (pow(pos_distance, 2.0) < pow(m_radius + otherObj.m_radius, 2.0))
    {
        circle_mtv = (red_posCircle - blue_posCircle)/pos_distance * (m_radius + otherObj.m_radius - pos_distance);
    }
    if (blue_posLine < red_posLine + otherObj.m_height && red_posLine < blue_posLine + m_height)
    {
        height_mtv = calcInterval(blue_posLine, m_height, red_posLine, otherObj.m_height);
    }
    if (glm::length(circle_mtv) < glm::length(height_mtv))
    {
        return;
    }
    else if (glm::length(circle_mtv) > glm::length(height_mtv))
    {
        return;
    }
}




