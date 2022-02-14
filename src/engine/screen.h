#ifndef SCREEN_H
#define SCREEN_H

#include "engine/util/CommonIncludes.h"

#include <QGLWidget>

class Graphics;
class Screen
{
public:
    Screen();
    ~Screen();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyRepeatEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    virtual void tick() = 0;

    virtual void draw(Graphics *g) = 0;
};

#endif // SCREEN_H
