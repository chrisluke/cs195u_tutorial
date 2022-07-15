#ifndef GAMEAPPLICATION_H
#define GAMEAPPLICATION_H

#include "engine/graphics/Camera.h"
#include "engine/screen.h"
#include "game_logic/gamescreen.h"
#include "game_logic/titlescreen.h"
#include "engine/inputmanager.h"

class GameApplication : public Application
{
public:
    GameApplication(std::shared_ptr<Camera> camera, std::shared_ptr<InputManager> inputManager);
    ~GameApplication() override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(int deltaX, int deltaY) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyRepeatEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    void handleInputs();

    void tick(float seconds) override;

    void draw(Graphics *g) override;

private:
    std::shared_ptr<TitleScreen> m_titleScreen;
    std::shared_ptr<GameScreen> m_gameScreen;
    std::shared_ptr<Camera> m_camera;
    std::vector<std::shared_ptr<Screen>> m_screen_list;
    std::shared_ptr<Screen> m_activeScreen;
    std::shared_ptr<InputManager> m_inputManager;
};

#endif // GAMEAPPLICATION_H
