#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "engine/graphics/Graphics.h"
#include "engine/graphics/Camera.h"
#include "engine/application.h"
#include "engine/screen.h"

class TitleScreen : public Screen
{
public:
    TitleScreen(std::shared_ptr<Camera> cam);
    ~TitleScreen() override;

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
    //std::shared_ptr<Camera> m_camera;
};

#endif // TITLESCREEN_H
