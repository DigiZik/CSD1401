#include "cprocessing.h"

float textsize;
float Play;
float rectx;
float recty;

void Main_Menu_Init()
{
	textsize = 50.0f;
	CP_Settings_TextSize(textsize);
	CP_System_SetWindowSize(900, 900);
	rectx = CP_System_GetWindowWidth() / 2;
	recty = CP_System_GetWindowHeight() / 2;
}

void Main_Menu_Update()
{
	CP_Color Red = CP_Color_Create(255, 40, 100, 255);
	CP_Graphics_DrawRect(rectx, recty, 200.0f, 50.0f);
	CP_Font_DrawText("Play", rectx, recty+40);
	CP_Graphics_ClearBackground(CP_Color_Create(0, 60, 60, 0));
}

void Main_Menu_Exit()
{

}