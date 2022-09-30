#include "cprocessing.h"
#include "mainmenu.h"
#include "utils.h"

typedef struct MainCar
{
	float x;
	float y;
	float trianglerotate;
}Car;
Car Car1,Car2,Car3;

typedef struct Vectors
{
	float x;
	float y;
}Vec;
Vec Vec1,vec2,Vec3;

int car_select = 0;


void Car_Level_Init()
{
	CP_System_SetWindowSize(900, 900);
	//Circle x,y
	Car1.x = 100.0f;
	Car1.y = 50.0f;
	Car2.x = 100.0f;
	Car2.y = 150.0f;
	Car3.x = 200.0f;
	Car3.y = 100.0f;
	Car1.trianglerotate = 0.0f;
	Car2.trianglerotate = 0.0f;
	Car3.trianglerotate = 0.0f;
}

void Car_Level_Update()
{
	//return time from last frame
	float currentElapsedTime = CP_System_GetDt();
	float totalElapsedTime = 0;
	totalElapsedTime += currentElapsedTime;
	//velocity
	float accel = CP_Math_LerpFloat(0.0f, 200.0f, totalElapsedTime);


		if (IsCircleClicked(Car1.x, Car1.y, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY()) && (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT)))
		{
				car_select = 1;
		}
		
		if (car_select == 1)
		{
			//move forward
			if (CP_Input_KeyDown(KEY_W))
			{
				CP_Vector Vec1 = AngleToVector(CP_Math_Radians(Car1.trianglerotate)); //original car angle
				Car1.x += accel * Vec1.x + totalElapsedTime;
				Car1.y += accel * Vec1.y + totalElapsedTime;
				//wall collide
				if (Car1.x >= 880)
				{
					Car1.x = 880;
				}
				if (Car1.y >= 880)
				{
					Car1.y = 880;
				}
				if (Car1.x <= 25)
				{
					Car1.x = 25;
				}
				if (Car1.y <= 25)
				{
					Car1.y = 25;
				}
				if (CP_Input_KeyDown(KEY_LEFT_SHIFT))
				{
					Car1.x += Vec1.x + 10;
					Car1.y += Vec1.y + 10;
				}

			}
			// move backward
			if (CP_Input_KeyDown(KEY_S))
			{
				CP_Vector Vec1 = AngleToVector(CP_Math_Radians(Car1.trianglerotate)); //original car angle
				Car1.x -= accel * Vec1.x;
				Car1.y -= accel * Vec1.y;
				//wall collide
				if (Car1.x >= 880)
				{
					Car1.x = 880;
				}
				if (Car1.y >= 880)
				{
					Car1.y = 880;
				}
				if (Car1.x <= 25)
				{
					Car1.x = 25;
				}
				if (Car1.y <= 25)
				{
					Car1.y = 25;
				}
			}
			//rotate clockwise
			if (CP_Input_KeyDown(KEY_D))
			{
				Car1.trianglerotate += 2.5f;

				if (Car1.trianglerotate >= 360)
				{
					Car1.trianglerotate = 0;
				}
			}
			//rotate anti clockwise
			if (CP_Input_KeyDown(KEY_A))
			{
				Car1.trianglerotate -= 2.5f;

				if (Car1.trianglerotate >= 360)
				{
					Car1.trianglerotate = 0;
				}
			}
		}
	
		if (IsCircleClicked(Car2.x, Car2.y, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY()) && (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT)))
		{
			car_select = 2;
		}

		if (car_select == 2)
		{
			//move forward
			if (CP_Input_KeyDown(KEY_W))
			{
				CP_Vector Vec2 = AngleToVector(CP_Math_Radians(Car2.trianglerotate)); //original car angle
				Car2.x += accel * Vec2.x;
				Car2.y += accel * Vec2.y;
				//wall collide
				if (Car2.x >= 880)
				{
					Car2.x = 880;
				}
				if (Car2.y >= 880)
				{
					Car2.y = 880;
				}
				if (Car2.x <= 25)
				{
					Car2.x = 25;
				}
				if (Car2.y <= 25)
				{
					Car2.y = 25;
				}
				if (CP_Input_KeyDown(KEY_LEFT_SHIFT))
				{
					CP_Vector Vec2 = AngleToVector(CP_Math_Radians(Car2.trianglerotate));
					Car2.x += accel * Vec2.x + 10;
					Car2.y += accel * Vec2.y + 10;
				}
			}
			// move backward
			if (CP_Input_KeyDown(KEY_S))
			{
				CP_Vector Vec2 = AngleToVector(CP_Math_Radians(Car2.trianglerotate)); //original car angle
				Car2.x -= accel * Vec2.x;
				Car2.y -= accel * Vec2.y;
				//wall collide
				if (Car2.x >= 880)
				{
					Car2.x = 880;
				}
				if (Car2.y >= 880)
				{
					Car2.y = 880;
				}
				if (Car2.x <= 25)
				{
					Car2.x = 25;
				}
				if (Car2.y <= 25)
				{
					Car2.y = 25;
				}
			}
			//rotate clockwise
			if (CP_Input_KeyDown(KEY_D))
			{
				Car2.trianglerotate += 2.5f;

				if (Car2.trianglerotate >= 360)
				{
					Car2.trianglerotate = 0;
				}
			}
			//rotate anti clockwise
			if (CP_Input_KeyDown(KEY_A))
			{
				Car2.trianglerotate -= 2.5f;

				if (Car2.trianglerotate >= 360)
				{
					Car2.trianglerotate = 0;
				}
			}
		}
	
		if (IsCircleClicked(Car3.x, Car3.y, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY()) && (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT)))
		{
			car_select = 3;
		}

		if (car_select == 3)
		{
			//move forward
			if (CP_Input_KeyDown(KEY_W))
			{
				CP_Vector Vec3 = AngleToVector(CP_Math_Radians(Car3.trianglerotate)); //original car angle
				Car3.x += accel * Vec3.x;
				Car3.y += accel * Vec3.y;
				//wall collide
				if (Car3.x >= 880)
				{
					Car3.x = 880;
				}
				if (Car3.y >= 880)
				{
					Car3.y = 880;
				}
				if (Car3.x <= 25)
				{
					Car3.x = 25;
				}
				if (Car3.y <= 25)
				{
					Car3.y = 25;
				}
				if (CP_Input_KeyDown(KEY_LEFT_SHIFT))
				{
					CP_Vector Vec3 = AngleToVector(CP_Math_Radians(Car3.trianglerotate));
					Car3.x += accel * Vec3.x + 10;
					Car3.y += accel * Vec3.y + 10;
				}
			}
			// move backward
			if (CP_Input_KeyDown(KEY_S))
			{
				CP_Vector Vec3 = AngleToVector(CP_Math_Radians(Car3.trianglerotate)); //original car angle
				Car3.x -= accel * Vec3.x;
				Car3.y -= accel * Vec3.y;
				//wall collide
				if (Car3.x >= 880)
				{
					Car3.x = 880;
				}
				if (Car3.y >= 880)
				{
					Car3.y = 880;
				}
				if (Car3.x <= 25)
				{
					Car3.x = 25;
				}
				if (Car3.y <= 25)
				{
					Car3.y = 25;
				}
			}
			//rotate clockwise
			if (CP_Input_KeyDown(KEY_D))
			{
				Car3.trianglerotate += 2.5f;

				if (Car3.trianglerotate >= 360)
				{
					Car3.trianglerotate = 0;
				}
			}
			//rotate anti clockwise
			if (CP_Input_KeyDown(KEY_A))
			{
				Car3.trianglerotate -= 2.5f;

				if (Car3.trianglerotate >= 360)
				{
					Car3.trianglerotate = 0;
				}
			}
		}


	CP_Color White = CP_Color_CreateHex(0xFFFFFFFF);
	CP_Color Green = CP_Color_CreateHex(0x00FF00FF);
	CP_Color Red = CP_Color_CreateHex(0xFF0000FF);
	CP_Settings_Fill(White);
	CP_Graphics_DrawCircle(Car1.x, Car1.y, 50.0f);
	CP_Settings_Fill(Green);
	CP_Graphics_DrawCircle(Car2.x, Car2.y, 50.0f);
	CP_Settings_Fill(Red);
	CP_Graphics_DrawCircle(Car3.x, Car3.y, 50.0f);
	CP_Settings_Fill(White);
	CP_Graphics_DrawTriangleAdvanced(Car1.x - 15.f, Car1.y - 20.f, Car1.x - 15.f, Car1.y + 20.f, Car1.x + 25, Car1.y , Car1.trianglerotate);
	CP_Settings_Fill(Green);
	CP_Graphics_DrawTriangleAdvanced(Car2.x - 15.f, Car2.y - 20.f, Car2.x - 15.f, Car2.y + 20.f, Car2.x + 25, Car2.y, Car2.trianglerotate);
	CP_Settings_Fill(Red);
	CP_Graphics_DrawTriangleAdvanced(Car3.x - 15.f, Car3.y - 20.f, Car3.x - 15.f, Car3.y + 20.f, Car3.x + 25, Car3.y, Car3.trianglerotate);
	CP_Settings_TextSize(15.f);
	CP_Settings_Fill(White);
	CP_Font_DrawText("Press ESC to go back", 820.f,20.f);
	CP_Graphics_ClearBackground(CP_Color_Create(0, 60, 60, 0));

	if (CP_Input_KeyDown(KEY_ESCAPE))
	{
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
		totalElapsedTime = 0;
	}
}

void Car_Leve_Exit()
{

}