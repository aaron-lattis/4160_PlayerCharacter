

#include "TileHandler.h"
#include <iostream>
#include "GameEngine.h"
#include "Sprite.h"
#include "Background.h"
#include "ImageHandler.h"


Map::Map(const char* img, SDL_Renderer* renderer)
{

    tile_renderer = renderer;

    ImageHandler imgHandler = ImageHandler();

    tile_sheet = imgHandler.handle_image(tile_renderer, img);
    

    map[0] = 0;
    map[1] = 2;
    map[2] = 3;
    map[3] = 1;
    map[4] = 1;
    map[5] = 2;
    map[6] = 2;
    map[7] = 3;
    map[8] = 1;
    map[9] = 3;
    map[10] = 3;
    map[11] = 2;
    map[12] = 3;
    map[13] = 1;
    map[14] = 2;
    map[15] = 1;
    map[16] = 3;
    map[17] = 2;
    map[18] = 2;
    map[19] = 1;

    dest.x = 640;
    dest.y = 340;
    dest.h = 110;
    dest.w = 105;

    object_on_screen = false;
    last_num = -1;

}

Map::~Map()
{

}

Map::Map()
{

}

void Map::render_map(GameObject player, SDL_Renderer* renderer)
{

    int whereOnMap = (int)(player.get_total_moved() / 110 );

    if(player.get_moving_right())
    {
        if (!object_on_screen && whereOnMap != last_num) 
        {
            if (map[whereOnMap] == 3)
            {   

                src.x = 385;
                src.y = 289;
                src.h = 95;
                src.w = 143;

                dest.x = 640;
                dest.y = 340;
                dest.h = 110;
                dest.w = 105;

                SDL_RenderCopy(renderer, tile_sheet, &src, &dest);
                object_on_screen = true;
            }
            else if (map[whereOnMap] == 2)
            {   

                src.x = 385;
                src.y = 384;
                src.h = 95;
                src.w = 143;


                dest.x = 640;
                dest.y = 340;
                dest.h = 110;
                dest.w = 105;

                SDL_RenderCopy(renderer, tile_sheet, &src, &dest);
                object_on_screen = true;
            }
            else if (map[whereOnMap] == 1)
            {   

                src.x = 35;
                src.y = 450;
                src.h = 170;
                src.w = 175;

                dest.x = 640;
                dest.y = 340;
                dest.h = 110;
                dest.w = 105;

                SDL_RenderCopy(renderer, tile_sheet, &src, &dest);
                object_on_screen = true;
            }
            else
            {
                SDL_RenderCopy(tile_renderer, tile_sheet, &src, &dest);   
            }

        }
        else
        {
            SDL_RenderCopy(tile_renderer, tile_sheet, &src, &dest);   
        }
        

    }
    else if(player.get_moving_left())
    {
        if (!object_on_screen && whereOnMap != last_num) 
        {
            if (map[whereOnMap] == 3)
            {   

                src.x = 385;
                src.y = 289;
                src.h = 95;
                src.w = 143;

                dest.x = -105;
                dest.y = 340;
                dest.h = 110;
                dest.w = 105;

                SDL_RenderCopy(renderer, tile_sheet, &src, &dest);
                object_on_screen = true;
            }
            else if (map[whereOnMap] == 2)
            {   

                src.x = 385;
                src.y = 384;
                src.h = 95;
                src.w = 143;


                dest.x = -105;
                dest.y = 340;
                dest.h = 110;
                dest.w = 105;

                SDL_RenderCopy(renderer, tile_sheet, &src, &dest);
                object_on_screen = true;
            }
            else if (map[whereOnMap] == 1)
            {   

                src.x = 35;
                src.y = 450;
                src.h = 170;
                src.w = 175;

                dest.x = -105;
                dest.y = 340;
                dest.h = 110;
                dest.w = 105;

                SDL_RenderCopy(renderer, tile_sheet, &src, &dest);
                object_on_screen = true;
            }
            else
            {
                SDL_RenderCopy(tile_renderer, tile_sheet, &src, &dest);   
            }
        }
        else
        {
            SDL_RenderCopy(tile_renderer, tile_sheet, &src, &dest);   
        }
    }
    else
    {
        SDL_RenderCopy(tile_renderer, tile_sheet, &src, &dest);   
    }
    
    last_num = whereOnMap;
}

void Map::update_map(GameObject player)
{

    if (object_on_screen)
    {
        dest.x = dest.x - player.get_x_velocity() * 8;

        if (dest.x < -105 || dest.x > 640) { object_on_screen = false; }
    }
}


