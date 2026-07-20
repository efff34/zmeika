#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"

int main(void)
{
	srand(time(NULL));
    const int screenWidth = 800;
    const int screenHeight = 450;
    char text[1000];
    int score = 0;
    char color[] = "RED";

    InitWindow(screenWidth, screenHeight, "Move the snake");
    SetTargetFPS(60);
    int radius = 20;
    const float speed = 250.0;
    Vector2 squarePosition = {
        (screenWidth - 30) / 2.0,
        (screenHeight - 30) / 2.0
    };
	int LinesCountX = 16;
	int LinesCountY = 9;
	int cSizeX = screenWidth / LinesCountX;
	int cSizeY = screenHeight / LinesCountY;
        float timer = 0;
	float xf = 2;
	float yf = 2;

	float zmekax[100];
	float zmekay[100];
	zmekax[0] = 0;
	zmekay[0] = 1;
	
	int SnakeCount = 3;	

	int xspeed = 1;
	int yspeed = 0;

	int gameOver = 0;

	float xP = 0;
	float yP = 0;
	float xPe = 50;
	float yPe = 50;
    while (!WindowShouldClose())
    {	
    	float timerL = 0.5;	    
	 int mX = GetMouseX();
	 timer += GetFrameTime();
	// printf("%f\n",timer);
         const float distance = speed * GetFrameTime();
	 int mY = GetMouseY() ;
  //	if(timer > 1.5 && yeBool == 0 )
//	{
	//	xe++;
//		xeB = 3;
//		ye++;
//		timer = 0;
//	}
          if (IsKeyDown(KEY_RIGHT))	{xspeed = 1;  yspeed = 0;}
          if (IsKeyDown(KEY_LEFT))	{xspeed = -1; yspeed = 0;}
          if (IsKeyDown(KEY_DOWN))	{xspeed = 0;  yspeed = 1;}
          if (IsKeyDown(KEY_UP))	{xspeed = 0;  yspeed = -1;}
	int ForceR = 0;   

	if(zmekay[0] > LinesCountY)
	{
		zmekay[0] = 0;
		gameOver = 1;	
	}
	if(zmekay[0] < 0)
	{
		zmekay[0] = 8;
		gameOver = 1;	
	}
	if(zmekax[0] > LinesCountX )
	{
		zmekax[0] = 0;
		gameOver = 1;	
	}
	if(zmekax[0] < 0)
	{
		zmekax[0] = 15;
		gameOver = 1;	
	}
	
	for(int i = 1; i < SnakeCount;i++)
	{
		if(zmekax[0] == zmekax[i] && zmekay[0] == zmekay[i])
		{
			gameOver = 1;
		}
	}
	if(timerL == 1)
	{

	}
	if (timer > timerL) 
	{	
		int newHeadX = zmekax[0] + xspeed;
		int newHeadY = zmekay[0] + yspeed;
		if(newHeadX == xf && newHeadY == yf)
		{
			timerL = 1;
//			printf("%f\n",timerL);
		for(int i = 1; i < SnakeCount;i++)
		{
			if(zmekax[0] == zmekax[i] && zmekay[0] == zmekay[i])
			{
				gameOver = 1;
			}
		}
			if(timerL < 0.2)
			{
				timerL = 0.2;
			}	
		//	printf("IN\n");
			SnakeCount++;
			yf = 1 +  rand() %( 7 - 1 + 1);
			xf = 1 +  rand() % (15 - 1 + 1);

		}
		for(int i = 0;i > SnakeCount; i++)
		{
			if(xf == zmekax[i])
			{
			xf = 1 +  rand() % (15 - 1 + 1);
			}
			if(yf == zmekay[i])
			{
			yf = 1 +  rand() % (7 - 1 + 1);
			}
		}

		for (int i = SnakeCount - 1; i > 0; i--)
		{
			zmekax[i] = zmekax[i - 1];
			zmekay[i] = zmekay[i - 1];
		}
		zmekax[0] = newHeadX;
		zmekay[0] = newHeadY;
		

		timer = 0;

	//	printf("x: %f %f\n",zmekax[0], xf);
	//	printf("y: %f %f\n",zmekay[0], yf);
	//	printf("\n");
	}
	

	BeginDrawing();
        ClearBackground(DARKGREEN);
	for(int i = 0; i < LinesCountX; i++)
	{
       		int x = i * cSizeX;	
        	DrawLine(x, 0, x, screenHeight, GREEN);
	}

	for(int i = 0; i < LinesCountY; i++)
	{
		int y = i * cSizeY;
        	DrawLine(0, y, screenWidth, y, GREEN); 
	}
//	printf("%d\n",score);

//	printf("%d\n",SnakeCount);
//	DrawCircle(squarePosition.x, squarePosition.y,radius, RED);
//	DrawCircle(600, 200,20.0, BLUE);
//	DrawCircle(200, 200,20.0, GREEN);
	int foodX = cSizeX * xf;
	int foodY = cSizeY * yf;
	DrawRectangle(foodX,foodY, 30, 30,RED);
	for(int i = 0;i < SnakeCount;i++ )
	{
	//	xe += 50;
		DrawRectangle(cSizeX * zmekax[i],cSizeY * zmekay[i] ,50 , 50, BLUE);
//		SnakeCount++;
	}
	if(gameOver == 1)
	{
	DrawRectangle(0,0, 900, 500,GRAY);
        DrawText("GAME OVER", 60, 180, 100, BLACK);
        DrawText("press 'space' for already to play", 60, 270, 20, BLACK);
        DrawText("-Is this correct?", 60, 300, 20, BLACK);
        DrawText("-I dont think so", 60, 330, 20, BLACK);
	}
	if(IsKeyDown(KEY_SPACE) && gameOver == 1)
	{
		gameOver = 0;
		SnakeCount = 1;
		zmekax[0] = 0;
		zmekay[0] = 0;
		xspeed = 1;
	      	yspeed = 0;
	}
	EndDrawing();
    }
    CloseWindow();
    return 0;
}
