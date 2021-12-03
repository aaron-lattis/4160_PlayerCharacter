
#include <SDL.h>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include "GameObject.h"

#ifndef TEILHANDLER_H
#define TEILHANDLER_H

class Map
{

   public:

      Map(const char* img, SDL_Renderer* renderer);

      Map();

      ~Map();

      void render_map(GameObject player, SDL_Renderer* renderer);

      void update_map(GameObject player);



   private:

      SDL_Renderer* tile_renderer;

      SDL_Texture* tile_sheet;

      int map [20];

      SDL_Rect src;

      SDL_Rect dest;

      bool object_on_screen;

      int last_num;

};
 
#endif

