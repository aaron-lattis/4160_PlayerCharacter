
#include <string>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

class Sprite
{

public:

    Sprite(int h, int w, const char* img, SDL_Renderer* ren, int frame_duration, int frames);

    Sprite();

    ~Sprite();

    SDL_Rect sprite_update(bool jump, bool run);

    void sprite_render(SDL_Rect dest, bool jump, bool run, bool r, bool l);

    void sprite_quit();

    void set_img_height(int h);

    void set_img_width(int w);

    int get_img_height();

    int get_img_width();

    void set_full_graphic(const char* img);

private:

    int img_h;
    int img_w;

    int frame_duration;
    int frame_count;

    SDL_Texture* full_graphic;

    SDL_Renderer* game_renderer;

};

#endif