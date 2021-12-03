
#include <iostream>
#include "GameEngine.h"
#include "Sprite.h"
#include "Background.h"
#include <SDL.h>
#include "TileHandler.h"


GameEngine::GameEngine()
{

}


GameEngine::~GameEngine()
{

}


void GameEngine::init()
{

   fps = 60;
   frame_duration = 1000 / fps;

   //Screen dimension
   const int SCREEN_WIDTH = 640;
   const int SCREEN_HEIGHT = 480;

   if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
   { 
      std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl; 
   }

   //Enable gpu_enhanced textures
   IMG_Init(IMG_INIT_PNG);
  
   my_window = SDL_CreateWindow("my_game", 
			       SDL_WINDOWPOS_CENTERED, 
			       SDL_WINDOWPOS_CENTERED, 
			       SCREEN_WIDTH,
			       SCREEN_HEIGHT, 0);
   my_renderer = SDL_CreateRenderer(my_window,-1,0);

   Sprite player1 = Sprite(125, 120, "spriteSheet.png", my_renderer, frame_duration, 8);

   
   player.obj_init(265, 340, 110, 105, my_renderer, player1);

   
   this_start_time = 0;
   fps_counter = 0;
   last_count_start_time = 0;
   //current_fps = 0;
   this_duration = 0;
   //frame_duration = 0; 
   game_is_running = true;


   bg11 = Background("11.png", my_renderer);
   bg10 = Background("10.png", my_renderer);
   bg6 = Background("6.png", my_renderer);
   bg4 = Background("4.png", my_renderer);
   bg2 = Background("2.png", my_renderer);

   map = Map("tilesheet.png", my_renderer);

}
   

void GameEngine::handleEvents()
{
   SDL_Event game_event;
   SDL_PollEvent(&game_event);


   if (game_event.type == SDL_QUIT) { game_is_running = false; }

   if(player.get_is_jumping())
   {
      player.set_how_many_jumps(player.get_how_many_jumps() + 1);

      if(player.get_how_many_jumps() == 15) { player.set_y_velocity(3); }

      if(player.get_how_many_jumps() == 30) 
      { 
         player.set_y_velocity(0);

         player.set_is_jumping(false);
      }

      if (game_event.type == SDL_KEYUP)
      {
         switch (game_event.key.keysym.sym)
         {
            case SDLK_a: 
               player.set_need_to_stop(true);
               break;

            case SDLK_d: 
               player.set_need_to_stop(true);
               break;
         }
      }
   }
   else if(player.get_need_to_stop())
   {
      player.set_x_velocity(0);
      player.set_need_to_stop(false);
      player.set_moving_left(false);
      player.set_moving_right(false);
   }
   else if (game_event.type == SDL_KEYDOWN)
   {

      switch (game_event.key.keysym.sym)
      {
         
         case SDLK_a: 
            if(!player.get_moving_right()) { player.set_x_velocity(-1); player.set_moving_left(true); }
            break; 

         case SDLK_d: 
            if(!player.get_moving_left()) { player.set_x_velocity(1); player.set_moving_right(true); }
            break;

         case SDLK_SPACE: 
            player.set_y_velocity(-3);
            player.set_how_many_jumps(0);
            player.set_is_jumping(true);
            break;
      }
   }

   else if (game_event.type == SDL_KEYUP)
   {
      switch (game_event.key.keysym.sym)
      {
         
         case SDLK_a: 
            if(player.get_moving_left()) { player.set_x_velocity(0); player.set_moving_left(false); }
            break;

         case SDLK_d: 
            if(player.get_moving_right()) { player.set_x_velocity(0); player.set_moving_right(false); }
            break;

      }  
   }
}
   

void GameEngine::updateMechanics()
{
   player.obj_update(bg2, bg4, bg6, bg10);

   map.update_map(player);
}  

void GameEngine::renderer()
{
   SDL_RenderClear(my_renderer);

   bg11.render_bg(my_renderer);
   bg10.render_bg(my_renderer);
   bg6.render_bg(my_renderer);
   bg4.render_bg(my_renderer);
   bg2.render_bg(my_renderer);

   map.render_map(player, my_renderer);

   player.obj_render();

   SDL_RenderPresent(my_renderer);
}
   

void GameEngine::quit()
{
   SDL_DestroyRenderer(my_renderer);
   SDL_DestroyWindow(my_window);

   IMG_Quit();
   SDL_Quit();

   player.obj_quit();
   cloud1.obj_quit();
   cloud2.obj_quit();
   cloud3.obj_quit();
   cloud4.obj_quit();
}


int GameEngine::get_this_start_time()
{
   return this_start_time;
}

int GameEngine::get_fps_counter()
{
   return fps_counter;
}

int GameEngine::get_last_count_start_time()
{
   return last_count_start_time;
}

int GameEngine::get_this_duration()
{
   return this_duration;
}

int GameEngine::get_frame_duration()
{
   return frame_duration;
}

int GameEngine::get_fps()
{
   return fps;
}

void GameEngine::set_this_start_time(int x)
{
   this_start_time = x;
}

void GameEngine::set_fps_counter(int x)
{
   fps_counter = x;
}

void GameEngine::set_last_count_start_time(int x)
{
   last_count_start_time = x;
}

void GameEngine::set_this_duration(int x)
{
   this_duration = x;
}

void GameEngine::set_frame_duration(int x)
{
   frame_duration = x;
}

void GameEngine::set_fps(int x)
{
   fps = x;
}

bool GameEngine::get_game_is_running()
{
   return game_is_running;
}

void GameEngine::set_game_is_running(bool x)
{
   game_is_running = x;
}