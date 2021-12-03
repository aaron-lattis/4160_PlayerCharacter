
#include "GameObject.h"
#include "Background.h"
#include "TileHandler.h"

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

class GameEngine
{

public:

    GameEngine();

    ~GameEngine();

    void init();

    void handleEvents();

    void updateMechanics();

    void renderer();

    void quit();

    int get_this_start_time();
    int get_fps_counter();
    int get_last_count_start_time();
    int get_this_duration();
    int get_frame_duration();
    int get_fps();

    void set_this_start_time(int x);
    void set_fps_counter(int x);
    void set_last_count_start_time(int x);
    void set_this_duration(int x);
    void set_frame_duration(int x);
    void set_fps(int x);

    bool get_game_is_running();
    void set_game_is_running(bool x);

private:

    GameObject player;

    GameObject cloud1;

    GameObject cloud2;

    GameObject cloud3;

    GameObject cloud4;

    SDL_Rect ground;

    SDL_Rect sky;

    SDL_Window* my_window = NULL;
    SDL_Renderer* my_renderer = NULL;
    SDL_Event input;

    int this_start_time;
    int fps_counter;
    int last_count_start_time;
    //int current_fps;
    int this_duration;
    int frame_duration; 
    int fps;

    bool game_is_running;

    Background bg11;
    Background bg10;
    Background bg9;
    Background bg8;
    Background bg7;
    Background bg6;
    Background bg5;
    Background bg4;
    Background bg3;
    Background bg2;
    Background bg1;

    Map map;

};

#endif