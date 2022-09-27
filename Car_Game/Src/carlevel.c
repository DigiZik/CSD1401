#include "cprocessing.h"
#include "mainmenu.h"
#include "utils.h"

typedef struct MainCar
{
	float x;
	float y;
	float trianglex1;
	float trianglex2;
	float trianglex3;
	float triangley1;
	float triangley2;
	float triangley3;
	float trianglerotate;
	float angle;
}Car;
Car Car1;

typedef struct Vectors
{
	float x;
	float y;
}Vec;
Vec Vec1;

int car_select = 0;


void Car_Level_Init()
{
	CP_System_SetWindowSize(900, 900);
	//Circle x,y
	Car1.x = 100.0f;
	Car1.y = 50.0f;
	Car1.trianglerotate = 0.0f;
}

void Car_Level_Update()
{
	//return time from last frame
	float currentElapsedTime = CP_System_GetDt();
	float totalElapsedTime = 0;
	totalElapsedTime += currentElapsedTime;
	//velocity
	float accel = CP_Math_LerpFloat(0.0f, 50.0f, totalElapsedTime);
	//Car1.angle = 0;


		if (IsCircleClicked(Car1.x, Car1.y, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
		{
			if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
			{
				car_select = 1;

			}		
		}
		
		if (car_select == 1)
		{
			
			
			//move forward
			if (CP_Input_KeyDown(KEY_W))
			{
				CP_Vector Vec1 = AngleToVector(CP_Math_Radians(Car1.trianglerotate)); //original car angle
				Car1.x += accel * Vec1.x;
				Car1.y += accel * Vec1.y;

				if (Car1.x >= 900)
				{
					Car1.x = 900;
				}
			}
			if (CP_Input_KeyDown(KEY_LEFT_SHIFT))
			{
				CP_Vector Vec1 = AngleToVector(CP_Math_Radians(Car1.trianglerotate));
				Car1.x += accel * Vec1.x + 10;
				Car1.y += accel * Vec1.y + 10;
			}
			
			if (CP_Input_KeyDown(KEY_S))
			{
				CP_Vector Vec1 = AngleToVector(CP_Math_Radians(Car1.trianglerotate)); //original car angle
				Car1.x -= accel * Vec1.x;
				Car1.y -= accel * Vec1.y;
				
				if (Car1.x <= 5)
				{
					Car1.x = 5;
				}
			}

			//rotate clockwise
			if (CP_Input_KeyDown(KEY_D))
			{
				//float rotation = CP_Vector_Angle(Car1.x, Vec1.y);
				//float currentElapsedTime = CP_System_GetDt();
				//rotation += currentElapsedTime;
				Car1.trianglerotate += 2.5f;
				
				if (Car1.trianglerotate >= 360)
				{
					Car1.trianglerotate = 0;
				}
			}

			//rotate anti clockwise
			if (CP_Input_KeyDown(KEY_A))
			{
				//float rotation = CP_Vector_Angle(Car1.x, Vec1.y);
				//float currentElapsedTime = CP_System_GetDt();
				//rotation += currentElapsedTime;
				Car1.trianglerotate -= 2.5f;

				if (Car1.trianglerotate >= 360)
				{
					Car1.trianglerotate = 0;
				}
			}
		}
		else car_select = 0;
	
	
	
	CP_Graphics_DrawCircle(Car1.x, Car1.y, 50.0f);
	//CP_Graphics_DrawTriangleAdvanced(Car1.x - 20.f, Car1.y - 20.f, Car1.x + 20.f, Car1.y - 20.f, Car1.x, Car1.y + 20.f, Car1.trianglerotate);
	CP_Graphics_DrawTriangleAdvanced(Car1.x - 15.f, Car1.y - 20.f, Car1.x - 15.f, Car1.y + 20.f, Car1.x + 25, Car1.y , Car1.trianglerotate);
	CP_Settings_TextSize(10.f);
	CP_Font_DrawText("Press ESC to go back", 850.f,20.f);
	CP_Graphics_ClearBackground(CP_Color_Create(0, 60, 60, 0));

	if (CP_Input_KeyDown(KEY_ESCAPE))
	{
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}

void Car_Leve_Exit()
{

}