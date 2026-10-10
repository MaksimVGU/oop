#include "Engine.h"
#include "car.h"
#include "Sky.h"

car player;
Sky sky;

void initialize()
{
    player.set_coordinates(440, 540);
}

void act(float dt)
{
    (void)dt;

    if (is_key_pressed(VK_RIGHT))
    {
        player.update_coordinates(5, 0);
    }

    if (is_key_pressed(VK_LEFT))
    {
        player.update_coordinates(-5, 0);
    }
}

void draw()
{
    sky.draw();

    int roadY = 580;

    for (int j = 0; j < SCREEN_WIDTH; j++)
    {
        for (int i = roadY; i < roadY + 120; i++)
        {
            if (i < SCREEN_HEIGHT)
            {
                buffer[i][j] = 0x555555;
            }
        }
    }

    for (int j = 0; j < SCREEN_WIDTH; j += 80)
    {
        for (int dj = 0; dj < 40; dj++)
        {
            if (j + dj < SCREEN_WIDTH)
            {
                buffer[roadY + 60][j + dj] = 0xffffff;
            }
        }
    }

    player.draw();
}

void finalize()
{
}
