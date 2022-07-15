#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "engine/util/CommonIncludes.h"

#include <QGLWidget>
#include <QKeyEvent>

#include "engine/screen.h"

using namespace std;

class InputManager
{
public:
    InputManager();
    std::map<std::string, int> m_keyInputs;
    glm::vec2 m_mouseVec;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(int deltaX, int deltaY);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyRepeatEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // INPUTMANAGER_H
