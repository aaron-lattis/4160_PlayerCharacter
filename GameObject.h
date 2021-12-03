
#include <string>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include "Sprite.h"
#include "Background.h"

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
   public:

      GameObject();

      ~GameObject();

      void obj_init(int x, int y, int h, int w, const char* img, SDL_Renderer* renderer);

      void obj_init(int x, int y, int h, int w, SDL_Renderer* renderer, Sprite s);

      void obj_update(Background &bg4, Background &bg3, Background &bg2, Background &bg1);

      void obj_render();

      void obj_quit();

      void set_x_velocity(int v);

      void set_y_velocity(int v);

      int get_x_velocity();

      int get_y_velocity();

      void set_is_jumping(bool j);

      bool get_is_jumping();

      void set_how_many_jumps(int j);

      int get_how_many_jumps();

      void set_need_to_stop(bool s);

      bool get_need_to_stop();

      void set_moving_right(bool r);

      bool get_moving_right();

      void set_moving_left(bool r);

      bool get_moving_left();

      void set_facing_right(bool f);

      void set_facing_left(bool f);

      bool get_facing_right();

      bool get_facing_left();

      void set_counter(int n);

      int get_total_moved();

   private:

      Sprite sprite;

      SDL_Renderer* obj_renderer;

      SDL_Texture* obj_graphic;

      SDL_Rect obj_rect; 
      SDL_Rect src_rect;

      bool needToStop;

      bool isJumping;

      bool movingRight;
      bool movingLeft;

      int howManyJumps; 

      int xVelocity;
      int yVelocity;

      bool facing_right;
      bool facing_left;

      int total_moved;
};
 
#endif

