#include "inputmanager.h"

InputManager::InputManager()
{
    m_keyInputs = {};
    m_keyInputs["esc"] = 0;
    m_keyInputs["1"] = 0;
    m_keyInputs["2"] = 0;
    m_keyInputs["W"] = 0;
    m_keyInputs["A"] = 0;
    m_keyInputs["S"] = 0;
    m_keyInputs["D"] = 0;
    m_keyInputs["left"] = 0;
    m_keyInputs["right"] = 0;
    m_mouseVec = glm::vec2(0.0, 0.0);
}

void InputManager::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        m_keyInputs["left"] = 1;
    }
    if(event->button() == Qt::RightButton) {
        m_keyInputs["right"] = 1;
    }
}


void InputManager::mouseMoveEvent(int deltaX, int deltaY)
{
    /** SUPPORT CODE START **/
    // TODO (Warmup 1): Handle mouse movements here
    m_mouseVec = glm::vec2(deltaX, deltaY);
}

void InputManager::mouseReleaseEvent(QMouseEvent *event)
{
    // TODO (Warmup 1): Handle mouse release here
    if(event->button() == Qt::LeftButton) {
        m_keyInputs["left"] = 0;
    }
    if(event->button() == Qt::RightButton) {
        m_keyInputs["right"] = 0;
    }
}

void InputManager::wheelEvent(QWheelEvent *event)
{
    // TODO (Warmup 1): Handle mouse wheel events here
}

void InputManager::keyPressEvent(QKeyEvent *event)
{
    /** SUPPORT CODE START **/

    // Don't remove this -- helper code for key repeat events
    if(event->isAutoRepeat()) {
        keyRepeatEvent(event);
        return;
    }

    // Feel free to remove this
    if (event->key() == Qt::Key_Escape) {
        m_keyInputs["esc"] = 1;
        std::cout << "esc press" <<std::endl;
        std::cout <<  m_keyInputs["esc"]  <<std::endl;
    }

    /** SUPPORT CODE END **/

    // TODO (Lab 1): Handle keyboard presses here
    // strafe movement
    if(event->key() == Qt::Key_1) {
        m_keyInputs["1"] = 1;
        std::cout << "1 press" <<std::endl;
    }
    if(event->key() == Qt::Key_2) {
        m_keyInputs["2"] = 1;
    }
    if(event->key() == Qt::Key_W) {
        m_keyInputs["W"] = 1;
    }
    if(event->key() == Qt::Key_A) {
        m_keyInputs["A"] = 1;
    }
    if(event->key() == Qt::Key_S) {
        m_keyInputs["S"] = 1;
    }
    if(event->key() == Qt::Key_D) {
        m_keyInputs["D"] = 1;
    }

    //m_activeScreen->keyPressEvent(event);

    // TODO (Warmup 1): Handle keyboard presses here

}

void InputManager::keyRepeatEvent(QKeyEvent *event)
{
    // TODO (Warmup 1): Handle key repeats (happens when holding down keys)
    //m_activeScreen->keyRepeatEvent(event);
}

void InputManager::keyReleaseEvent(QKeyEvent *event)
{
    /** SUPPORT CODE START **/

    // Don't remove this -- helper code for key repeat events
    if(event->isAutoRepeat()) {
        return;
    }

    /** SUPPORT CODE END **/

    // TODO (Warmup 1): Handle key releases
    if(event->key() == Qt::Key_1) {
        m_keyInputs["1"] = 0;
        std::cout << "1 release" <<std::endl;
    }
    if(event->key() == Qt::Key_2) {
        m_keyInputs["2"] = 0;
    }
    if(event->key() == Qt::Key_W) {
        m_keyInputs["W"] = 0;
    }
    if(event->key() == Qt::Key_A) {
        m_keyInputs["A"] = 0;
    }
    if(event->key() == Qt::Key_S) {
        m_keyInputs["S"] = 0;
    }
    if(event->key() == Qt::Key_D) {
        m_keyInputs["D"] = 0;
    }


}
