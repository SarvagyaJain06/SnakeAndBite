// SnakeAndBite(PilotProject).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <conio.h>
#include <iostream>

#include <windows.h>

#include <chrono>
#include <thread>
#include <limits>
#include <vector>


using namespace std;
char playGround[20][20];

void GameBoard(vector<int> snakeCoordinateX, vector<int> snakeCoordinateY,int foodCoordinateX,int foodCoordinateY,int snakeLength)
{
   vector<int>::iterator itrXbegin = snakeCoordinateX.begin();
   vector<int>::iterator itrYbegin = snakeCoordinateY.begin();
   vector<int>::iterator itrXend = snakeCoordinateX.end();
   vector<int>::iterator itrYend = snakeCoordinateY.end();

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
        
         else {
           playGround[i][j] = ' ';
               
         }
        for (int k = 1; k < snakeCoordinateX.size(); k++)
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

bool GameOver(vector<int>/*int*/ snakeCoordinateX, vector<int>/* int*/ snakeCoordinateY)
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

int main()
{
   int snakeLength = 1, score = -1, direction = 1;
   bool gameOver = false, foodEaten = false;
   int snakeHeadCoordinateX=10, snakeHeadCoordinateY =10, foodCoordinateX=10, foodCoordinateY=10;
   vector<int> snakeCoordinateX = {10,10,10 };
   vector<int> snakeCoordinateY = { 10,11,12};
   vector<int>::iterator itr;
   do
   {
      system("cls");
      if (snakeCoordinateX[0] == foodCoordinateX && snakeCoordinateY[0] == foodCoordinateY)
      {
         foodCoordinateX = generateSingleFoodCoordinate();
         foodCoordinateY = generateSingleFoodCoordinate();
         foodEaten = false;
         score++;
         switch (direction)
         {
         case VK_LEFT:
         {
            snakeCoordinateX.push_back(snakeCoordinateX[snakeCoordinateX.size() -1]);
            snakeCoordinateY.push_back(snakeCoordinateY[snakeCoordinateY.size() - 1] += 1);
            break;
         }
         case VK_RIGHT:
         { snakeCoordinateX.push_back(snakeCoordinateX[snakeCoordinateX.size() - 1]);
            snakeCoordinateY.push_back(snakeCoordinateY[snakeCoordinateY.size() - 1]-= 1);
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
         snakeLength++;
      }

      for (int i = 8; i < 256; i++)
      {
         if (GetAsyncKeyState(i) == -32767)
         {
            direction = i;
            std::this_thread::sleep_for(std::chrono::milliseconds(4));
         }
      }

      switch (direction)
      {
        case VK_LEFT:
        {
           for (itr = snakeCoordinateX.end() - 1; itr > snakeCoordinateX.begin(); --itr)
           {
              *itr = *(itr - 1);
           }
           for (itr = snakeCoordinateY.end() - 1; itr > snakeCoordinateY.begin(); --itr)
           {
              *itr = *(itr - 1);
           }
           snakeCoordinateY[0] -= 1;
        break;
        }
        case VK_RIGHT:
        {
           for (itr = snakeCoordinateX.end() - 1; itr > snakeCoordinateX.begin(); --itr)
           {
              *itr = *(itr - 1);
           }
           for (itr = snakeCoordinateY.end() - 1; itr > snakeCoordinateY.begin(); --itr)
           {
              *itr = *(itr - 1);
           }
           snakeCoordinateY[0] += 1;
        break;
        }
        case VK_UP:
        {
           for (itr = snakeCoordinateX.end() - 1; itr > snakeCoordinateX.begin(); --itr)
           {
              *itr = *(itr - 1);
           }
           for (itr = snakeCoordinateY.end() - 1; itr > snakeCoordinateY.begin(); --itr)
           {
              *itr = *(itr - 1);
           }
           snakeCoordinateX[0] -= 1;
         break;
        }
        case VK_DOWN:
        {
           for (itr = snakeCoordinateX.end() - 1; itr > snakeCoordinateX.begin(); --itr)
           {
              *itr = *(itr - 1);
           }
           for (itr = snakeCoordinateY.end() - 1; itr > snakeCoordinateY.begin(); --itr)
           {
              *itr = *(itr - 1);
           }
           snakeCoordinateX[0] += 1;
         break;
        }
        
      }
      GameBoard(snakeCoordinateX, snakeCoordinateY, foodCoordinateX, foodCoordinateY, snakeLength);
      cout << endl << "score: " << score;
   } while (!GameOver(snakeCoordinateX, snakeCoordinateY));
   cout << endl<<"GAME OVER" <<endl;
   
   cin.ignore();
  
}


         

       
    
  


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
