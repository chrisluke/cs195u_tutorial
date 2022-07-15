#include "drawcomponent.h"

DrawComponent::DrawComponent()
{

}

DrawComponent::~DrawComponent()
{

}

void DrawComponent::draw(Graphics *g)
{
    g->clearTransform(); g->scale(200);
    g->setMaterial("boringGrass");
    g->drawShape("quad");

    g->clearTransform(); g->setDefaultMaterial();
    g->translate(glm::vec3(1.f,1.f,10.f)); g->scale(5);
    g->drawShape("cylinder");
}
