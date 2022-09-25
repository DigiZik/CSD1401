#include "cprocessing.h"
#include "mainmenu.h"

float accel;

void Car_Level_Init()
{
	CP_System_SetWindowSize(900, 900);
	typedef struct MainCar
	{
		int x;
		int y;
	}Car;

	Car Car1;

}

void Car_Level_Update()
{
	//return time from last frame
	float currentElapsedTime = CP_System_GetDt();
	float totalElapsedTime = 0;
	totalElapsedTime += currentElapsedTime;
	//accelerate
	accel = CP_Math_LerpFloat(0.0f, 30.0f, totalElapsedTime);
	CP_Settings_EllipseMode(CP_POSITION_CORNER);
	CP_Graphics_DrawEllipseAdvanced(100.0f, 50.0f, 50.0f, 50.0f, 45.0f);


	CP_Graphics_ClearBackground(CP_Color_Create(0, 60, 60, 0));

}

void Car_Leve_Exit()
{

}