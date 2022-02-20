#include "screen.h"

Screen::Screen(std::shared_ptr<Camera> camera)
{
    m_camera = camera;
}

Screen::~Screen()
{

}
