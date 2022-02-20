#ifndef APPLICATION_H
#define APPLICATION_H

#include "engine/graphics/Camera.h"
#include "engine/graphics/Graphics.h"
#include "engine/util/CommonIncludes.h"

#include <QGLWidget>

class Application
{
public:
    Application();
    virtual ~Application() = 0;

    virtual void mousePressEvent(QMouseEvent *event) = 0;
    virtual void mouseMoveEvent(int deltaX, int deltaY) = 0;
    virtual void mouseReleaseEvent(QMouseEvent *event) = 0;
    virtual void wheelEvent(QWheelEvent *event) = 0;
    virtual void keyPressEvent(QKeyEvent *event) = 0;
    virtual void keyRepeatEvent(QKeyEvent *event) = 0;
    virtual void keyReleaseEvent(QKeyEvent *event) = 0;

    virtual void tick(float seconds) = 0;

    virtual void draw(Graphics *g) = 0;
};

#endif // APPLICATION_H
