#include "cprocessing.h"
#include "carlevel.h"
#include "utils.h"

float textsize;
float rectx;
float recty;


void Main_Menu_Init()
{
	textsize = 50.0f;
	CP_Settings_TextSize(textsize);
	CP_System_SetWindowSize(900, 900);
	rectx = CP_System_GetWindowWidth() / 2.0f;
	recty = CP_System_GetWindowHeight() / 2.0f;

}

void Main_Menu_Update()
{
	CP_TEXT_ALIGN_HORIZONTAL horizontal = rectx;
	CP_TEXT_ALIGN_VERTICAL vertical = recty;
	float mousex = CP_Input_GetMouseX();
	float mousey = CP_Input_GetMouseY();
	CP_Color Red = CP_Color_CreateHex(0xFF0000FF);
	CP_Color White = CP_Color_CreateHex(0xFFFFFFFF);
	CP_Color Green = CP_Color_CreateHex(0x00FF00FF);
	
	
	

	//Play button
	CP_Settings_Fill(Green);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Graphics_DrawRect(rectx, recty, 200.0f, 50.0f);
	//Play text c
	CP_Settings_Fill(White);
	CP_Settings_TextAlignment(horizontal, vertical);
	CP_Font_DrawText("Play", rectx, recty + 10);
	//Exit button
	CP_Settings_Fill(Red);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Graphics_DrawRect(rectx , recty + 100, 200.0f, 50.0f);
	//Exit play
	CP_Settings_Fill(White);
	CP_Settings_TextAlignment(horizontal, vertical);
	CP_Font_DrawText("Exit", rectx, recty + 110);
	CP_Graphics_ClearBackground(CP_Color_Create(0, 60, 60, 0));
	// start button collider
	if (CP_Input_MouseClicked())
	{
		if (IsAreaClicked(rectx, recty, 200.0f, 50.0f, mousex, mousey))
		{
			CP_Engine_SetNextGameState(Car_Level_Init, Car_Level_Update, NULL);
		}
		
	}
	// exit button collider
	if (CP_Input_MouseClicked())
	{
		if (IsAreaClicked(rectx, recty + 100, 200.0f, 50.0f, mousex, mousey))
		{
			CP_Engine_Terminate();
		}

	}
	
}

void Main_Menu_Exit()
{

}