#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "engine/graphics/Graphics.h"
#include "engine/graphics/Camera.h"
#include "engine/application.h"
#include "engine/screen.h"
#include "engine/util/CommonIncludes.h"

class GameScreen : public Screen
{
public:
    GameScreen(std::shared_ptr<Camera> cam);
    ~GameScreen();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(int deltaX, int deltaY) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyRepeatEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    void tick(float seconds) override;

    void draw(Graphics *g) override;

private:
    Application *m_gameApp;
    Graphics *m_graphics;
    //std::shared_ptr<Camera> m_camera;

};

#endif // GAMESCREEN_H
