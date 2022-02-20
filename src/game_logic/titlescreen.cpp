#include "titlescreen.h"

#include "engine/graphics/Graphics.h"
#include "engine/graphics/Camera.h"
#include "engine/graphics/Material.h"

#include <QGLWidget>
#include <QApplication>
#include <QKeyEvent>
#include <QWindow>

TitleScreen::TitleScreen(std::shared_ptr<Camera> cam) : Screen(cam)
{
    //m_camera = cam;
    //m_graphics = Graphics::getGlobalInstance();
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::mousePressEvent(QMouseEvent *event)
{
    // TODO (Warmup 1): Handle mouse press events
}

void TitleScreen::mouseMoveEvent(int deltaX, int deltaY)
{
    /** SUPPORT CODE START **/

    // This starter code implements mouse capture, which gives the change in
    // mouse position since the last mouse movement. The mouse needs to be
    // recentered after every movement because it might otherwise run into
    // the edge of the screen, which would stop the user from moving further
    // in that direction. Note that it is important to check that deltaX and
    // deltaY are not zero before recentering the mouse, otherwise there will
    // be an infinite loop of mouse move events.

    // TODO (Lab 1): Handle mouse movements here

    // TODO (Warmup 1): Handle mouse movements here
}

void TitleScreen::mouseReleaseEvent(QMouseEvent *event)
{
    // TODO (Warmup 1): Handle mouse release here
}

void TitleScreen::wheelEvent(QWheelEvent *event)
{
    // TODO (Warmup 1): Handle mouse wheel events here
}

void TitleScreen::keyPressEvent(QKeyEvent *event)
{
    /** SUPPORT CODE START **/

    // Don't remove this -- helper code for key repeat event

    // Feel free to remove this

    /** SUPPORT CODE END **/


    // TODO (Warmup 1): Handle keyboard presses here
}

void TitleScreen::keyRepeatEvent(QKeyEvent *event)
{
    // TODO (Warmup 1): Handle key repeats (happens when holding down keys)
}

void TitleScreen::keyReleaseEvent(QKeyEvent *event)
{
    /** SUPPORT CODE START **/

    // Don't remove this -- helper code for key repeat events


    /** SUPPORT CODE END **/

    // TODO (Warmup 1): Handle key releases
}

void TitleScreen::draw(Graphics *g)
{
    g->setClearColor(glm::vec3(1, 0, 0));
    g->clearScreen(Graphics::CLEAR_FLAG::ALL);
    g->clearShader();
    g->setDefaultMaterial();
    //std::cout << "title draw";
}

void TitleScreen::tick(float seconds)
{
    /** SUPPORT CODE START **/

    // TODO (Warmup 1): Implement the game update here

    /** SUPPORT CODE START **/

    // Flag this view for repainting (Qt will call paintGL() soon after)


    /** SUPPORT CODE END **/
}
