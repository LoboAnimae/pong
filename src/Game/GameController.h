//
// Created by yagdrassyl on 7/21/22.
//

#ifndef PONGPROJECT_GAMECONTROLLER_H
#define PONGPROJECT_GAMECONTROLLER_H

#include "../Controller/Controller.h"
#include "../Time/Time.h"
#include "../Events/Event.h"
#include "../Screen/Screen.h"
#include "../Error/Error.h"
#include "../Entity/ControllableEntity.h"
#include <vector>

namespace Game {

    struct ScreenParams {
        int screen_width;
        int screen_height;
        const char *title;

        ScreenParams(const char *p_title, int p_width, int p_height) :
                title(p_title), screen_width(p_width), screen_height(p_height) {};
    };


    struct InitParameters {
        int FPS;
        Game::Screen::Screen* screen;
    };

    class Master {
    public:
        explicit Master(InitParameters params);

        ~Master();

        void init();

        void setup();

        bool has_error();

        void run_loop();


    private:
        bool isRunning;
        Game::Time* time_controller;
        Game::Event* event_controller;
        Game::Screen::Screen* screen_controller;
        StandardError *present_error;
    };

}


#endif //PONGPROJECT_GAMECONTROLLER_H
