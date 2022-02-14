#ifndef APPLICATION_H
#define APPLICATION_H

#include "engine/util/CommonIncludes.h"

#include <QGLWidget>

class Graphics;
class Application
{
public:
    Application();
    ~Application();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyRepeatEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    virtual void tick(float seconds) = 0;

    virtual void draw(Graphics *g) = 0;
};

#endif // APPLICATION_H
