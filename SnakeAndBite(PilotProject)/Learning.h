//

//#include <ctime>    // For time()
//#include <stdlib.h>  // For random Number()
//#include <time.h>*/
//#include <SFML/Graphics.hpp>

//
//bool GameOver(int snakeCoordinateX, int snakeCoordinateY)
//{
//   if (snakeCoordinateX == 0 || snakeCoordinateX == 19 || snakeCoordinateY == 0 || snakeCoordinateY == 19)
//      return true;
//   return false;
//}
//void UserChoicesShow()
//{
//   int userDirction;
//   cout << "1. Up"<<endl;
//   cout << "2. Down" << endl;
//   cout << "3. Left" << endl;
//   cout << "4. Right" << endl;
//   cout << "Let's Play" <<endl;
//   
//}
//
//enum move {
//   /*WM_KEYUP =1 ,
//   WM_KEYDOWN,
//   VK_LEFT,
//   VK_RIGHT*/
//   UP = 1,
//   DOWN,
//   LEFT,
//   RIGHT
//};
//void increaseSnakeLength(int snakeCoordinateX[], int snakeCoordinateY[],int foodCoordinateX,int foodCoordinateY,int snakeLength,int userInput)
//{
//
//   SetUp(snakeCoordinateX, snakeCoordinateY, foodCoordinateX, foodCoordinateY,snakeLength,userInput);
//   
//}
//
//int generateRandomCoordinate()
//{
//   int randomNumber =1 + rand() % 17;
//   return randomNumber;
//}
//
//LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
//{
//   PKBDLLHOOKSTRUCT hook = (PKBDLLHOOKSTRUCT)lParam;
//   if (nCode >= 0)
//   {
//      if (wParam == WM_KEYDOWN)
//      {
//         switch (hook->vkCode)
//         {
//         case /*UP*/VK_UP:
//         {
//            return 1;// snakeCoordinateX[0] -= 1;
//           // break;     //  GetKeyState(VK_UP) == false;
//         }
//         case /*DOWN*/VK_DOWN:
//         {
//            return 2;// snakeCoordinateX[0] += 1;
//            //break;
//            // GetKeyState(VK_DOWN) == false;
//         }
//         case /*LEFT*/VK_LEFT:
//         {
//            return 3; //  snakeCoordinateY[0] -= 1;
//           // break;
//            // GetKeyState(VK_LEFT) == false;
//         }
//         case /*RIGHT*/VK_RIGHT:
//         {
//            return 4;//snakeCoordinateY[0] += 1;
//         //   break; //  GetKeyState(VK_RIGHT) == false;
//         }
//         }
//      }
//   }
//}

//WPARAM GetKeyPressMessage()
//{
//   MSG msg;
//   HHOOK keyboardhook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);
//
//   while (GetMessage(&msg, NULL, 0, 0));
//   {
//      TranslateMessage(&msg);
//      DispatchMessage(&msg);
//   }
//   return msg.wParam;
//}
//void snakeMove(int key)
//{
//   switch (key)
//   {
//   case VK_LEFT:
//   {std::cout << "yes";
//   break;
//   }
//   }
//
//}

   //int userInput = 0;
   //int score = 0;
   //int snakeLength = 1;
   //bool foodEaten = false;
   // std::cout << "\tHello World, Welcome into Game!\n";
   // int foodCoordinateX = generateRandomCoordinate();
   // int foodCoordinateY = generateRandomCoordinate();
   // int snakeCoordinateX[10] = { 10 }, snakeCoordinateY[10] = { 10 };
   // SetUp(snakeCoordinateX, snakeCoordinateY, foodCoordinateX, foodCoordinateY, snakeLength, 0);
   // UserChoicesShow();
   // 
   // do {
   // 
   //    std::this_thread::sleep_for(std::chrono::seconds(1));
   //    system("cls");
   //    UserChoicesShow();
   //   
   //    if (snakeCoordinateX[0] == foodCoordinateX && snakeCoordinateY[0] == foodCoordinateY)
   //    {
   //        foodCoordinateX = generateRandomCoordinate();
   //        foodCoordinateY = generateRandomCoordinate();
   //        foodEaten = false;
   //        increaseSnakeLength(snakeCoordinateX, snakeCoordinateY,foodCoordinateX, foodCoordinateY, snakeLength,userInput);
   //        score++;
   //    }
   //   
   //       SetUp(snakeCoordinateX, snakeCoordinateY, foodCoordinateX, foodCoordinateY,snakeLength,0);//need


   //       
        /*  {
             MSG msg;
             HHOOK keyboardhook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);

             while (GetMessage(&msg, NULL, 0, 0));
             {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
             }
             return msg.wParam
          }*/



          /*  if(!GetMessage(&msg, hwnd, 0, 0))
            {
               msg.wParam;
            }*/




            // cin >> userInput;
           //  moveSnake
              /*  if (userInput == 1)
                {
                   snakeCoordinateX[0] -= 1;
                }
             if (userInput == 2)
             {
                snakeCoordinateX[0] += 1;
             }
             if (userInput == 3)
             {
                snakeCoordinateY[0] -= 1;
             }
             if (userInput == 4)
             {
                snakeCoordinateY[0] += 1;
             }
             keybd_event(VK_LEFT, 0x25, 0, 0);*/
             /* if (snakeCoordinateX[0] == foodCoordinateX && snakeCoordinateY[0] == foodCoordinateY)
              {
                 foodEaten == true;
              }*/

              //switch (UP/*msg.wParam*/)
              //   {
              //   case UP/*VK_UP*/:
              //   {
              //      snakeCoordinateX[0] -= 1;
              //      break;     //  GetKeyState(VK_UP) == false;
              //   }
              //   case DOWN/*VK_DOWN*/:
              //   {
              //      snakeCoordinateX[0] += 1;
              //      break;
              //      // GetKeyState(VK_DOWN) == false;
              //   }
              //   case LEFT/*VK_LEFT*/:
              //   {
              //      snakeCoordinateY[0] -= 1;
              //      break;
              //      // GetKeyState(VK_LEFT) == false;
              //   }
              //   case RIGHT/*VK_RIGHT*/:
              //   {
              //      snakeCoordinateY[0] += 1;
              //      break; //  GetKeyState(VK_RIGHT) == false;
              //   }

             //    }

             /* } while (!keybd_event);


              cout << "score : " << score << endl;

           } while (!GameOver(snakeCoordinateX[0], snakeCoordinateY[0]));
           cout <<endl<< "GAME OVER";*/

           //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//  CONSOLE_CURSOR_INFO ConCurInf;
//ConCurInf.bVisible = false;
  //   ShowCursor(false);