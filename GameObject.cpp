

#include <iostream>
#include "GameObject.h"
#include "Sprite.h"
#include "ImageHandler.h"


GameObject::GameObject()
{
   
}


GameObject::~GameObject()
{

}


void GameObject::obj_init(int x, int y, int h, int w, const char* img, SDL_Renderer* renderer)
{
   obj_renderer = renderer;

   src_rect.x = 0;
   src_rect.y = 0;
   src_rect.h = 125;
   src_rect.w = 100;

   isJumping = false;
   howManyJumps = 0;
   movingRight = false;
   movingLeft = false;

   facing_right = true;
   facing_left = false;


   xVelocity = 0;
   yVelocity = 0;

   obj_rect.x = x;
   obj_rect.y = y;
   obj_rect.h = h;
   obj_rect.w = w;

   ImageHandler imgHandler = ImageHandler();

   obj_graphic = imgHandler.handle_image(obj_renderer, img);
}

void GameObject::obj_init(int x, int y, int h, int w, SDL_Renderer* renderer, Sprite s)
{
   obj_renderer = renderer;

   sprite = s;

   src_rect.x = 0;
   src_rect.y = 0;
   src_rect.h = 125;
   src_rect.w = 100;

   isJumping = false;
   howManyJumps = 0;
   movingRight = false;
   movingLeft = false;


   xVelocity = 0;
   yVelocity = 0;

   obj_rect.x = x;
   obj_rect.y = y;
   obj_rect.h = h;
   obj_rect.w = w;
}


void GameObject::obj_update(Background &bg4, Background &bg3, Background &bg2, Background &bg1)
{

   total_moved += xVelocity;

   obj_rect.y += yVelocity;

   bg4.set_velocity(xVelocity * 8);
   bg3.set_velocity(xVelocity * 6);
   bg2.set_velocity(xVelocity * 2);
   bg1.set_velocity(xVelocity * 1);

   bg4.update();
   bg3.update();
   bg2.update();
   bg1.update();
}


void GameObject::obj_render()
{
   SDL_RenderCopy(obj_renderer, obj_graphic, &src_rect, &obj_rect);
   
   bool running;

   if (movingRight || movingLeft) { running = true; }
   else { running = false; }

   sprite.sprite_render(obj_rect, running, isJumping, movingRight, movingLeft);
}


void GameObject::obj_quit()
{
   SDL_DestroyRenderer(obj_renderer);
   SDL_DestroyTexture(obj_graphic);
}


void GameObject::set_x_velocity(int v)
{
   xVelocity = v;
}


void GameObject::set_y_velocity(int v)
{
   yVelocity = v;
}


int GameObject::get_x_velocity()
{
   return xVelocity;
}


int GameObject::get_y_velocity()
{
   return yVelocity;
}


void GameObject::set_is_jumping(bool j)
{
   isJumping = j;
}


bool GameObject::get_is_jumping()
{
   return isJumping;
}


void GameObject::set_how_many_jumps(int j)
{
   howManyJumps = j;
}


int GameObject::get_how_many_jumps()
{
   return howManyJumps;
}


void GameObject::set_need_to_stop(bool s)
{
   needToStop = s;
}


bool GameObject::get_need_to_stop()
{
   return needToStop;
}


void GameObject::set_moving_right(bool r)
{
   movingRight = r;
}


bool GameObject::get_moving_right()
{
   return movingRight;
}


void GameObject::set_moving_left(bool l)
{
   movingLeft = l;
}


bool GameObject::get_moving_left()
{
   return movingLeft;
}

void GameObject::set_facing_right(bool f)
{
   facing_right = f;
}

void GameObject::set_facing_left(bool f)
{
   facing_left = f;
}

bool GameObject::get_facing_right()
{
   return facing_right;
}

bool GameObject::get_facing_left()
{
   return facing_left;
} 

int GameObject::get_total_moved()
{
   return total_moved;
}