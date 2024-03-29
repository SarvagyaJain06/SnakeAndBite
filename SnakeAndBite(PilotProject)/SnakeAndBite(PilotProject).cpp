// SnakeAndBite(PilotProject).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <conio.h>
#include <iostream>

#include <windows.h>

#include <chrono>
#include <thread>
//#include <limits>
#include <vector>


using namespace std;
char playGround[20][20];

void GameBoard(vector<int> snakeCoordinateX, vector<int> snakeCoordinateY,int foodCoordinateX,int foodCoordinateY)
{

   for (int i = 0; i < 20; i++)
   {
      for (int j = 0; j < 20; j++)
      {
        if ((i > 0 && i < 19) && (j == 0 || j == 19))
         {
            playGround[i][j] = '*'; //end columns
         }
         else if (i == 0 || i == 19)
         {
            playGround[i][j] = '*'; //end rows
           
         }
         else if (i == snakeCoordinateX[0] && j == snakeCoordinateY[0])
         {
           playGround[i][j] = '#';
         }

         else if (i == foodCoordinateX && j == foodCoordinateY)
         {
            playGround[i][j] = 'f';
         }
        
         else 
         {
           playGround[i][j] = ' ';
          }
        
        for (int k = 0; k < snakeCoordinateX.size(); k++)
        {
           if (i == snakeCoordinateX[k] && j == snakeCoordinateY[k])
           {
              playGround[i][j] = '#';
          
           }
        }
         cout << playGround[i][j];
      }
      cout << '\n';

   }

}
bool selfDamage(vector<int>snakeCoordinateX,vector<int>snakeCoordinateY) {

   vector<int>::iterator itrX = snakeCoordinateX.begin();
   vector<int>::iterator itrY = snakeCoordinateY.begin();
   int snakeHeadCoordinateX = *itrX;
   int snakeHeadCoordinateY = *itrY;
   for (itrX+1, itrY+1; itrX < snakeCoordinateX.end(); ++itrX,++itrY)
   {
      if ((*itrX== snakeHeadCoordinateX) && (*itrY == snakeHeadCoordinateY))
      {
         return true;
      }
   }
   return false;
}

bool GameOver(vector<int> snakeCoordinateX, vector<int> snakeCoordinateY)
{
   if (snakeCoordinateX[0] == 0 || snakeCoordinateX[0] == 19 || snakeCoordinateY[0] == 0 || snakeCoordinateY[0] == 19)
      return true;
   else if(!selfDamage(snakeCoordinateX,snakeCoordinateY))
   {
      return true;
   }
   else
   return false;
}

int generateSingleFoodCoordinate()
{
   return 1 + rand() % 17;
}

bool isFoodEaten(int snakeHeadCoordinateX, int snakeHeadCoordinateY,int foodCoordinateX,int foodCoordinateY)
{
	if (snakeHeadCoordinateX == foodCoordinateX && snakeHeadCoordinateY == foodCoordinateY)
		return true;
	return false;
}

void IncreaseTail(int direction,vector<int> &snakeCoordinateX,vector<int> &snakeCoordinateY)
{
	switch (direction)
	{
	case VK_LEFT:
	{
		snakeCoordinateX.push_back(snakeCoordinateX[snakeCoordinateX.size() - 1]);
		snakeCoordinateY.push_back(snakeCoordinateY[snakeCoordinateY.size() - 1] += 1);
		break;
	}
	case VK_RIGHT:
	{ snakeCoordinateX.push_back(snakeCoordinateX[snakeCoordinateX.size() - 1]);
	snakeCoordinateY.push_back(snakeCoordinateY[snakeCoordinateY.size() - 1] -= 1);
	break;
	}
	case VK_UP:
	{
		snakeCoordinateX.push_back(snakeCoordinateX[snakeCoordinateX.size() - 1] += 1);
		snakeCoordinateY.push_back(snakeCoordinateX[snakeCoordinateX.size() - 1]);
		break;
	}
	case VK_DOWN:
	{
		snakeCoordinateX.push_back(snakeCoordinateX[snakeCoordinateX.size() - 1] -= 1);
		snakeCoordinateY.push_back(snakeCoordinateY[snakeCoordinateY.size() - 1]);
		break;
	}
	}
}
void snakeMovement(vector<int>&snakeCoordinateX, vector<int>&snakeCoordinateY) {
	vector<int>::iterator itrX,itrY ;
	for (itrX = snakeCoordinateX.end() - 1; itrX > snakeCoordinateX.begin(); --itrX)
	{
		*itrX = *(itrX - 1);
	}
	for (itrY = snakeCoordinateY.end() - 1; itrY > snakeCoordinateY.begin(); --itrY)
	{
		*itrY = *(itrY - 1);
	}
}

int main()
{
	system("color 57");
   int score = -1, direction = 1;
   bool gameOver = false;
   int  foodCoordinateX=5, foodCoordinateY=15;
   vector<int> snakeCoordinateX = {10};
   vector<int> snakeCoordinateY = { 10};
   vector<int>::iterator itr;
   do
   {
	   std::this_thread::sleep_for(std::chrono::milliseconds(10));
      system("cls");
      if (isFoodEaten(snakeCoordinateX[0],snakeCoordinateY[0],foodCoordinateX,foodCoordinateY))
      {
         foodCoordinateX = generateSingleFoodCoordinate();
         foodCoordinateY = generateSingleFoodCoordinate();
         score++;
		 IncreaseTail(direction, snakeCoordinateX, snakeCoordinateY);
      }

      for (int i = 8; i < 256; i++)
      {
         if (GetAsyncKeyState(i) == -32767)
         {
            direction = i;
            std::this_thread::sleep_for(std::chrono::milliseconds(4));
         }
      }

	  snakeMovement(snakeCoordinateX, snakeCoordinateY);
	  
      switch (direction)
      {
        case VK_LEFT:
        {
           snakeCoordinateY[0] -= 1;
        break;
        }
        case VK_RIGHT:
        {
           snakeCoordinateY[0] += 1;
        break;
        }
        case VK_UP:
        {
           snakeCoordinateX[0] -= 1;
         break;
        }
        case VK_DOWN:
        {
           snakeCoordinateX[0] += 1;
         break;
        }
        
      }
      GameBoard(snakeCoordinateX, snakeCoordinateY, foodCoordinateX, foodCoordinateY);
      cout << endl << "score: " << score;
   } while (!GameOver(snakeCoordinateX, snakeCoordinateY));
   cout << endl<<"GAME OVER" <<endl;
   
   cin.ignore();
  
}


