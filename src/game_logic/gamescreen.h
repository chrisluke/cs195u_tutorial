#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "engine/graphics/Graphics.h"
#include "engine/graphics/Camera.h"
#include "engine/application.h"
#include "engine/screen.h"
#include "engine/util/CommonIncludes.h"

#include"gameobject.h"

class GameScreen : public Screen
{
public:
    GameScreen(std::shared_ptr<Camera> cam);
    ~GameScreen();

//    void mousePressEvent(QMouseEvent *event) override;
//    void mouseMoveEvent(int deltaX, int deltaY) override;
//    void mouseReleaseEvent(QMouseEvent *event) override;
//    void wheelEvent(QWheelEvent *event) override;
//    void keyPressEvent(QKeyEvent *event) override;
//    void keyRepeatEvent(QKeyEvent *event) override;
//    void keyReleaseEvent(QKeyEvent *event) override;

    void handleInputs(std::shared_ptr<InputManager>) override;

    void tick(float seconds) override;

    void draw(Graphics *g) override;

private:
    Application *m_gameApp;
    Graphics *m_graphics;
    bool jumping;
    std::unique_ptr<GameObject> m_player;

};

#endif // GAMESCREEN_H
