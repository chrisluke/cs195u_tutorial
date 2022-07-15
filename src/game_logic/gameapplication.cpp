#include "gameapplication.h"
#include "engine/screen.h"
#include "game_logic/gamescreen.h"
#include "game_logic/titlescreen.h"

#include "engine/util/CommonIncludes.h"

#include <QGLWidget>

#include "engine/graphics/Graphics.h"
#include "engine/graphics/Camera.h"
#include "engine/graphics/Material.h"
#include "engine/util/CommonIncludes.h"

#include <QGLWidget>
#include <QApplication>
#include <QKeyEvent>
#include <QWindow>

using namespace std;
using namespace glm;

GameApplication::GameApplication(std::shared_ptr<Camera> camera, std::shared_ptr<InputManager> inputManager)
{
    //m_graphics = Graphics::getGlobalInstance();
    m_camera = camera;
    m_gameScreen = std::make_shared<GameScreen>(camera);
    m_titleScreen = std::make_shared<TitleScreen>(camera);
    m_screen_list = {m_titleScreen, m_gameScreen};
    m_activeScreen = m_screen_list[1];
    m_inputManager = inputManager;
}

GameApplication::~GameApplication()
{
}

void GameApplication::mousePressEvent(QMouseEvent *event)
{
    // TODO (Warmup 1): Handle mouse press events
    //ms_activeScreen->mousePressEvent(event);

}

void GameApplication::mouseMoveEvent(int deltaX, int deltaY)
{
    /** SUPPORT CODE START **/
    // TODO (Warmup 1): Handle mouse movements here
    //m_activeScreen->mouseMoveEvent(deltaX, deltaY);
}

void GameApplication::mouseReleaseEvent(QMouseEvent *event)
{
    // TODO (Warmup 1): Handle mouse release here
}

void GameApplication::wheelEvent(QWheelEvent *event)
{
    // TODO (Warmup 1): Handle mouse wheel events here
    //m_activeScreen->wheelEvent(event);
}

void GameApplication::keyPressEvent(QKeyEvent *event)
{
    /** SUPPORT CODE START **/

    // Don't remove this -- helper code for key repeat events
    if(event->isAutoRepeat()) {
        keyRepeatEvent(event);
        return;
    }

    // Feel free to remove this
    if (m_inputManager->m_keyInputs["esc"] == 1) {
        std::cout << "quit" <<std::endl;
        QApplication::quit();
    }

    /** SUPPORT CODE END **/

    // TODO (Lab 1): Handle keyboard presses here
    // strafe movement
    if(event->key() == Qt::Key_1) {
        std::cout << "title switch";
        m_activeScreen = m_screen_list[0];
    }
    if(event->key() == Qt::Key_2) {
        std::cout << "game switch";
        m_activeScreen = m_screen_list[1];
    }
    //m_activeScreen->keyPressEvent(event);

    // TODO (Warmup 1): Handle keyboard presses here
}

void GameApplication::keyRepeatEvent(QKeyEvent *event)
{
    // TODO (Warmup 1): Handle key repeats (happens when holding down keys)
    //m_activeScreen->keyRepeatEvent(event);
}

void GameApplication::keyReleaseEvent(QKeyEvent *event)
{
    /** SUPPORT CODE START **/

    // Don't remove this -- helper code for key repeat events
    if(event->isAutoRepeat()) {
        return;
    }

    /** SUPPORT CODE END **/

    // TODO (Warmup 1): Handle key releases
}

void GameApplication::handleInputs()
{

    if (m_inputManager->m_keyInputs["esc"] == 1) {
        QApplication::quit();
    }
    if(m_inputManager->m_keyInputs["1"] == 1) {
        m_activeScreen = m_screen_list[0];
    }
    if(m_inputManager->m_keyInputs["2"] == 1) {
        m_activeScreen = m_screen_list[1];
    }
}

void GameApplication::draw(Graphics *g)
{
    m_activeScreen->draw(g);
}

void GameApplication::tick(float seconds)
{
    /** SUPPORT CODE START **/

    // TODO (Warmup 1): Implement the game update here
    m_activeScreen->tick(seconds);
    this->handleInputs();
    m_activeScreen->handleInputs(m_inputManager);

    /** SUPPORT CODE START **/

    // Flag this view for repainting (Qt will call paintGL() soon after)


    /** SUPPORT CODE END **/
}

