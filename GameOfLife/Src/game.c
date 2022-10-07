#include <stdio.h>
#include "cprocessing.h"

#define GOL_GRID_COLS 30
#define GOL_GRID_ROWS 30
#define GOL_GRID_BUFFERS 2

#define GOL_ALIVE 1
#define GOL_DEAD 0

#define TRUE 1
#define FALSE 0

int gIsPaused;
int gGrids[GOL_GRID_BUFFERS][GOL_GRID_ROWS][GOL_GRID_COLS];

/* Feel free to declare your own variables here */
float cell_size;
float grid_posx;
float grid_posy;
int reference_grid;
int display_grid;
int neighbour_alive;
int yrow;
int xcol;
int mousex;
int mousey;
CP_Vector grid_position;
CP_Vector grid_extents;


void game_init(void)
{
    /* Set every grids' cells as 'dead' */
    for (int row = 0; row < GOL_GRID_ROWS; ++row) {
        for (int col = 0; col < GOL_GRID_COLS; ++col) {
            for (int i = 0; i < GOL_GRID_BUFFERS; ++i) {
                gGrids[i][row][col] = GOL_DEAD;
            }
        }
    }

    /*********************************************************
    *  Let's start with gGrids[0] as the 'reference grid'
    *  and gGrids[1] as the 'displaying grid'.
    *
    *  We initialize gGrids[0] with a simple 'glider'.
    *********************************************************/

    gGrids[0][1][2] = GOL_ALIVE;
    gGrids[0][2][3] = GOL_ALIVE;
    gGrids[0][3][1] = GOL_ALIVE;
    gGrids[0][3][2] = GOL_ALIVE;
    gGrids[0][3][3] = GOL_ALIVE;

    /* We start unpaused */
    gIsPaused = FALSE;

    /* Initialization of your other variables here */
    CP_System_SetWindowSize(600, 600);
    cell_size = 20.f;
    grid_posx = 0.f;
    grid_posy = 0.f;
    neighbour_alive = 0;
    reference_grid = 0;
    display_grid = 1;
    mousex = 0;
    mousey = 0;
    //float ref_grid = gGrids;
}

void game_update(void)
{
    /* set framerate to 2 fps (slow)*/
    CP_System_SetFrameRate(20.0f);

    /* get dt, time elapsed from last frame*/
    float currentElapsedTime = CP_System_GetDt();

    /*updating total elapsed time*/
    static float totalElapsedTime = 0;
    totalElapsedTime += currentElapsedTime;

    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));
    // check reference grid
    if (gIsPaused == 0);
    {
        for (int yrow = 0; yrow < GOL_GRID_ROWS; ++yrow)
        {
            for (int xcol = 0; xcol < GOL_GRID_COLS; ++xcol)
            {
                neighbour_alive = 0;
                for (int ycheck = yrow - 1, i = 0; i < 3; ++ycheck, ++i) //loop through current grid x
                {
                    for (int xcheck = xcol - 1, j = 0; j < 3; ++xcheck, ++j) //loop through current grid y
                    {

                        if (ycheck == yrow && xcheck == xcol)
                        {
                            continue;
                        }
                        else if ((gGrids[reference_grid][ycheck][xcheck]) == GOL_ALIVE)
                        {
                            ++neighbour_alive;
                        }
                    }
                }
                //logic
                if (gGrids[reference_grid][yrow][xcol] == GOL_ALIVE)
                {
                    if (2 > neighbour_alive || neighbour_alive > 3)
                    {
                        gGrids[display_grid][yrow][xcol] = GOL_DEAD;
                    }
                    else
                    {
                        gGrids[display_grid][yrow][xcol] = GOL_ALIVE;
                    }

                }
                else
                {
                    if (neighbour_alive == 3)
                    {
                        gGrids[display_grid][yrow][xcol] = GOL_ALIVE;
                    }
                    else
                        gGrids[display_grid][yrow][xcol] = GOL_DEAD;
                }
            }
        }
    }
    
    //display grid
    for (int y = 0 ; y < GOL_GRID_ROWS; ++y)
    {
        for (int x = 0 ; x < GOL_GRID_COLS; ++x)
        {
            if (gGrids[display_grid][y][x] == GOL_ALIVE)
            {
                CP_Settings_Fill(CP_Color_Create(15, 255, 80, 255));
                CP_Graphics_DrawRect(grid_posy + y * cell_size, grid_posy + x * cell_size, cell_size, cell_size);
            }
            else 
            CP_Settings_Fill(CP_Color_Create(102, 102, 102, 255));
            CP_Graphics_DrawRect(grid_posy + y * cell_size, grid_posy + x * cell_size, cell_size, cell_size);
        }
    }
   
    int grid_x = (CP_Input_GetMouseX() - 0) / cell_size;
    int grid_y = (CP_Input_GetMouseY() - 0) / cell_size;
    int relative_posx = CP_Input_GetMouseX() - grid_x;
    int relative_posy = CP_Input_GetMouseY() - grid_y;
    //grid_position(relative_posx,);


    if (CP_Input_KeyTriggered(KEY_ANY))
    {
        gIsPaused = !gIsPaused;
    }
    if (!gIsPaused)
    {
        reference_grid = !reference_grid;
        display_grid = !display_grid;
    }

    
}

void game_exit(void)
{

}
