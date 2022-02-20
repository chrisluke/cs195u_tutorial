#include "gamescreen.h"

#include "engine/graphics/Graphics.h"
#include "engine/graphics/Camera.h"
#include "engine/graphics/Material.h"

#include <QGLWidget>
#include <QApplication>
#include <QKeyEvent>
#include <QWindow>

using namespace std;
using namespace glm;

GameScreen::GameScreen(std::shared_ptr<Camera> cam) : Screen(cam)
{
   // m_camera = cam;
    //m_graphics = Graphics::getGlobalInstance();
}

GameScreen::~GameScreen()
{
}

void GameScreen::mousePressEvent(QMouseEvent *event)
{
    // TODO (Warmup 1): Handle mouse press events
}

void GameScreen::mouseMoveEvent(int deltaX, int deltaY)
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
    m_camera->rotate(-deltaX / 100.f, -deltaY  / 100.f);

    // TODO (Warmup 1): Handle mouse movements here
}

void GameScreen::mouseReleaseEvent(QMouseEvent *event)
{
    // TODO (Warmup 1): Handle mouse release here
}

void GameScreen::wheelEvent(QWheelEvent *event)
{
    // TODO (Warmup 1): Handle mouse wheel events here
}

void GameScreen::keyPressEvent(QKeyEvent *event)
{
    /** SUPPORT CODE START **/


    /** SUPPORT CODE END **/

    // TODO (Lab 1): Handle keyboard presses here
    glm::vec3 look = m_camera->getLook();
    glm::vec3 dir = glm::normalize(glm::vec3(look.x, 0, look.z));
    glm::vec3 perp = glm::vec3(dir.z, 0, -dir.x);
    // strafe movement
    if(event->key() == Qt::Key_W) m_camera->translate(dir);
    if(event->key() == Qt::Key_S) m_camera->translate(-dir);
    if(event->key() == Qt::Key_A) m_camera->translate(perp);
    if(event->key() == Qt::Key_D) m_camera->translate(-perp);

    // TODO (Warmup 1): Handle keyboard presses here
    if (event->key() == Qt::Key_Space)
    {
        glm::vec3 jump = glm::vec3(0, 12.0, 0);
        m_camera->translate(jump);
    }
    std::cout << "game do key " << std::endl;
}

void GameScreen::keyRepeatEvent(QKeyEvent *event)
{
    // TODO (Warmup 1): Handle key repeats (happens when holding down keys)
}

void GameScreen::keyReleaseEvent(QKeyEvent *event)
{
    /** SUPPORT CODE START **/

    // Don't remove this -- helper code for key repeat events
    if(event->isAutoRepeat()) {
        return;
    }

    /** SUPPORT CODE END **/

    // TODO (Warmup 1): Handle key releases
}

void GameScreen::draw(Graphics *g)
{
    g->clearTransform(); g->scale(200);
    g->setMaterial("boringGrass");
    g->drawShape("quad");

    g->clearTransform(); g->setDefaultMaterial();
    g->translate(glm::vec3(1.f,1.f,10.f)); g->scale(5);
    g->drawShape("cylinder");
    std::cout << "game draw";
}

void GameScreen::tick(float seconds)
{
    /** SUPPORT CODE START **/

    // TODO (Warmup 1): Implement the game update here
    glm::vec3 gravity = glm::vec3(0, -0.2, 0);
    if (m_camera->getEye().y > 1.0) {
        m_camera->translate(gravity);
    }
    /** SUPPORT CODE START **/

    // Flag this view for repainting (Qt will call paintGL() soon after)


    /** SUPPORT CODE END **/
}
