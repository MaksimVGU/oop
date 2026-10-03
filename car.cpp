#include "car.h"
#include "Engine.h"

car::car () : x(0), y(0)
{
}

void car::set_coordinates(int new_x, int new_y)
{
	this->x=new_x;
	this->y=new_y;
}

void car::update_coordinates(int dx, int dy)
{
	this->x+=dx;
	this->y+=dy;
}
int car::give_coordinates_x()
{
	return this->x;
}
int car::give_coordinates_y()
{
	return this->y;
}

void car::draw()
{
	// Car body
	for (int i = y; i < y + 60 && i < SCREEN_HEIGHT; i++)
	{
		for (int j = x; j < x + 144; j++)
		{
			if (i >= 0 && i < SCREEN_HEIGHT && j >= 0 && j < SCREEN_WIDTH)
			{
				buffer[i][j] = 0xcc2222;
			}
		}
	}
	// Car top (cabin)
	for (int i = y - 30; i < y && i >= 0; i++)
	{
		for (int j = x + 24; j < x + 120; j++)
		{
			if (i >= 0 && i < SCREEN_HEIGHT && j >= 0 && j < SCREEN_WIDTH)
			{
				buffer[i][j] = 0xcc2222;
			}
		}
	}
	// Left window
	for (int i = y - 28; i < y - 5; i++)
	{
		for (int j = x + 30; j < x + 65; j++)
		{
			if (i >= 0 && i < SCREEN_HEIGHT && j >= 0 && j < SCREEN_WIDTH)
			{
				buffer[i][j] = 0x88ccff;
			}
		}
	}
	// Right window
	for (int i = y - 28; i < y - 5; i++)
	{
		for (int j = x + 75; j < x + 114; j++)
		{
			if (i >= 0 && i < SCREEN_HEIGHT && j >= 0 && j < SCREEN_WIDTH)
			{
				buffer[i][j] = 0x88ccff;
			}
		}
	}
	// Wheels
	int wheelY = y + 52;
	int wheelPositions[] = { x + 16, x + 100 };
	for (int w = 0; w < 2; w++)
	{
		for (int i = wheelY; i < wheelY + 28 && i < SCREEN_HEIGHT; i++)
		{
			for (int j = wheelPositions[w]; j < wheelPositions[w] + 24; j++)
			{
				if (i >= 0 && i < SCREEN_HEIGHT && j >= 0 && j < SCREEN_WIDTH)
				{
					buffer[i][j] = 0x111111;
				}
			}
		}
	}
	// Wheel hubs
	int hubPositions[] = { x + 22, x + 106 };
	for (int w = 0; w < 2; w++)
	{
		for (int i = wheelY + 8; i < wheelY + 20; i++)
		{
			for (int j = hubPositions[w]; j < hubPositions[w] + 8; j++)
			{
				if (i >= 0 && i < SCREEN_HEIGHT && j >= 0 && j < SCREEN_WIDTH)
				{
					buffer[i][j] = 0x888888;
				}
			}
		}
	}
	// Headlights
	for (int i = y + 10; i < y + 40; i++)
	{
		for (int j = x + 138; j < x + 144; j++)
		{
			if (i >= 0 && i < SCREEN_HEIGHT && j >= 0 && j < SCREEN_WIDTH)
			{
				buffer[i][j] = 0xffff44;
			}
		}
	}
	// Taillights
	for (int i = y + 10; i < y + 40; i++)
	{
		for (int j = x; j < x + 6; j++)
		{
			if (i >= 0 && i < SCREEN_HEIGHT && j >= 0 && j < SCREEN_WIDTH)
			{
				buffer[i][j] = 0xff4400;
			}
		}
	}
}
