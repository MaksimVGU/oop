#include<vector>

class car
{
    private:
		int x,y;
	public:
		car();
		void set_coordinates(int x, int y);
		void update_coordinates(int x, int y);
		int give_coordinates_x();
		int give_coordinates_y();
		void draw();
};

