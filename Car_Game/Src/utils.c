#include "cprocessing.h"
#include "math.h"

int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y)
{
	double x1 = area_center_x - area_width / 2;
	double y1 = area_center_y - area_height / 2;
	double x2 = area_center_x + area_width / 2;
	double y2 = area_center_y + area_height / 2;

	if (click_x > x1 && click_y > y1 && click_x < x2 && click_y < y2)
	{
		return 1;
	}
	else return 0;
}

int IsCircleClicked(float circle_center_x, float circle_center_y, float diameter, float click_x, float click_y)
{
	float radius = diameter / 2;
	float pythagorasD = CP_Math_Square(click_x - circle_center_x) + CP_Math_Square(click_y - circle_center_y);
	int D = sqrt(pythagorasD);
	//check if distance < radius
		if (D < radius)
		{
			return 1;
		}
		else return 0;
}

// angle to radians
CP_Vector AngleToVector(float radian_angle)
{
	//compute vector when angle is changed 
    CP_Vector Vec1 = CP_Vector_Set(cos(radian_angle),sin(radian_angle));
	//Returns the vectors to struct .x and .y
    return Vec1; 
} 