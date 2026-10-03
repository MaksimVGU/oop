/* MIT License
 * 
 * Copyright (c) 2026 Voronezh State University
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define _DEFAULT_SOURCE

#include "Engine.h"
#include "car.h"

#include <stdlib.h>
#include <memory.h>
#include <sys/time.h>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>
#include <cstdarg>
#include <cstdio>

car player;


// initialize game data
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
    // sky background
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            buffer[i][j] = 0x4477aa;
        }
    }

    // road
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

    // road lines
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
    // draw car
    player.draw();
}

void finalize()
{
}
