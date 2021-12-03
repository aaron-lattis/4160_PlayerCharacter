
#include <iostream>
#include "Sprite.h"
#include "ImageHandler.h"

Sprite::Sprite(int h, int w, const char* img, SDL_Renderer* ren, int frame_d, int frames)
{
    img_h = h;
    img_w = w;

    frame_duration = frame_d;
    frame_count = frames;

    game_renderer = ren;

    ImageHandler imgHandler = ImageHandler();

    full_graphic = imgHandler.handle_image(game_renderer, img);
}

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}

SDL_Rect Sprite::sprite_update(bool run, bool jump)
{

    SDL_Rect rect; 

    if (jump)
    {
        int frame = (int)((SDL_GetTicks() / 80) % 7);

        int x = frame * img_w;
        int y = img_h * 3;

        rect.x = x;
        rect.y = y;
        rect.h = img_h;
        rect.w = img_w;

        return rect;
    }
    else if (run)
    {
        int frame = (int)((SDL_GetTicks() / 80) % 9);

        int x = frame * img_w;
        int y = img_h * 1;

        if (frame == 8)
        {
          y = img_h * 2;
          x = 0;
        }

        rect.x = x;
        rect.y = y;
        rect.h = img_h;
        rect.w = img_w;

        return rect;

    }
    else
    {
        int frame = (int)((SDL_GetTicks() / 80) % 8);

        int x = frame * img_w;

        rect.x = x;
        rect.y = 0;
        rect.h = img_h;
        rect.w = img_w;

        return rect;
        
    }
}

void Sprite::sprite_render(SDL_Rect dest, bool run, bool jump, bool r, bool l)
{

   SDL_Rect rect = sprite_update(run, jump);

    if (r) 
    { 
        SDL_RenderCopy(game_renderer, full_graphic, &rect, &dest); 
    }
    else if (l)
    {
        SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

        SDL_RenderCopyEx(game_renderer, full_graphic, &rect, &dest, 0, NULL, flip);
    }
    else
    {
        SDL_RenderCopy(game_renderer, full_graphic, &rect, &dest); 
    }    
}

void sprite_quit()
{

}

void Sprite::set_img_height(int h)
{
    img_h = h;
}

void Sprite::set_img_width(int w)
{
    img_w = w;
}

int Sprite::get_img_height()
{
    return img_h;
}

int Sprite::get_img_width()
{
    return img_w;
}

void Sprite::set_full_graphic(const char* img)
{
   
   ImageHandler imgHandler = ImageHandler();

   full_graphic = imgHandler.handle_image(game_renderer, img);
   
}