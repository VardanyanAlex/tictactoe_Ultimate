#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>
#include <mutex>

#include "../include/drawfield.hpp"
#include "../include/input.hpp"
#include "../include/gameplay.hpp"
#include "../include/checkWin.hpp"
#include "../include/importantDetails.hpp"
#include "../include/youWin.hpp"
#include "../include/scriptCalls.hpp"

extern bool WIN;

constexpr short g_KEY_ARROW_LEFT = 68;
constexpr short g_KEY_ARROW_RIGHT = 67;
constexpr short g_KEY_ARROW_TOP = 65;
constexpr short g_KEY_ARROW_BOTTOM = 66;
constexpr short g_KEY_a = 97;
constexpr short g_KEY_d = 100;
constexpr short g_KEY_w = 119;
constexpr short g_KEY_s = 115;
constexpr short g_KEY_ENTER = 10;
constexpr short g_KEY_u = 117;

bool sound = true;

std::recursive_mutex g_ThreadAccess ;
std::mutex g_time_access ;
	
void XOtimer()
{

	short hour = 0, min = 0, sec = 0;
	
	g_ThreadAccess.lock();
	{
		gotoxy(95, 8);
		std::cout << "T I M E";
	}
	g_ThreadAccess.unlock();
	do
	{		
		
		g_time_access.lock();
		{
			gotoxy(94, 10);
			//std::cout << hour << " : " << min << " : " << sec << "  "  << std::endl;
		}
		g_time_access.unlock();

		++sec;
		if (sec == 60)
		{
			sec = 0;
			++min;
			if (min == 60)
			{
				min = 0;
				++hour;
			}
		}

		sleep(1);
		
	}while (!WIN);

}



void movement(int key, int& X, int& Y, int& matrix_ind, int& K, int& border_top, int& border_left,const int allowed_step,const int moveStepY, const int moveStepX)
{
	switch(key)
	{
	case g_KEY_ARROW_BOTTOM:
		case g_KEY_s: //bottom    S
			if (border_top != allowed_step)
			{
				Y += moveStepY;
				++border_top;
				if (K >= 6)
				{
					K -= 6;
					matrix_ind += 3;
				}
				else
				{
					K += 3;
				}
			}
			break;
		case g_KEY_ARROW_RIGHT:
		case g_KEY_d: //right    D
			if (border_left != allowed_step)
			{
				X += moveStepX;
				++border_left;
				if ((K + 1) % 3 == 0)
				{
					K -= 2;
					++matrix_ind;
				}
				else
				{
					++K;
				}
			}
			break;
		case g_KEY_ARROW_TOP:
		case g_KEY_w: //top    W
			if (border_top != 0)
			{
				Y -= moveStepY;
				--border_top;
				if (K <= 2)
				{
					K += 6;
					matrix_ind -= 3;
				}
				else
				{
					K -= 3;
				}
			}
			break;
		case g_KEY_ARROW_LEFT:
		case g_KEY_a: //left    A
			if (border_left != 0)
			{
				X -= moveStepX;
				--border_left;
				if ((K % 3) == 0)
				{
					K += 2;
					--matrix_ind;
				}
				else
				{
					--K;
				}
			}
			break;
	}
}


void hardGamePlay(std::string &xName, std::string &oName)
{
	std::thread time(XOtimer);
	short ***XO_matrix = new short **[9]; //whole matrix
	for (int i = 0; i < 9; ++i)
	{
		XO_matrix[i] = new short *[3];
		for (int j = 0; j < 3; ++j)
		{
			XO_matrix[i][j] = new short[3];
		}
	}
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				XO_matrix[i][j][k] = -10;
			}
		}
	}

	short **res_M = new short *[3]; //result matrix
	for (int i = 0; i < 3; ++i)
	{
		res_M[i] = new short[3];
		for (int j = 0; j < 3; ++j)
		{
			res_M[i][j] = (i + 1) * 3 + j;
		}
	}
	const int startingX = 12;
	const int startingY = 7;
	
	const int moveStepX = 8;
	const int moveStepY = 4;
	int X = 12, Y = 7, K = 0;
	int matrix_ind = 0;

	int border_top = 0, border_left = 0;
	int allowed_step = 8; 
		//    X -> 1    O -> 0

	cbreak();
	short player = 1;
	while (!WIN)
	{
		fflush(stdout);
		gotoxy(X, Y);		
		const char key = keypress();
		int key_ASCII = int(key);
		fflush(stdout); //clear buffer's memory

		switch (key_ASCII)
		{
		case g_KEY_ENTER: // ASCII code of ENTER button
			if (XO_matrix[matrix_ind][K / 3][K % 3] != 0 && XO_matrix[matrix_ind][K / 3][K % 3] != 1 && res_M[matrix_ind / 3][matrix_ind % 3] != 0 && res_M[matrix_ind / 3][matrix_ind % 3] != 1)
			{
				allowed_step = 2;
				colourizeField(X - 3, Y - 1, player);

				XO_matrix[matrix_ind][K / 3][K % 3] = player;
				if (check(XO_matrix[matrix_ind]) == 1)
				{
					res_M[matrix_ind / 3][matrix_ind % 3] = player;
					fillOneBox((startingX + (matrix_ind % 3) * 24) - 3, (matrix_ind / 3)*12 + startingY -1, player);
					gotoxy(90, 8);

					if (check(res_M))
					{
						WIN = true;
					
						gotoxy(95, 9);
						std::cout << "WINNNNNNNN" << std::endl;
					
						gotoxy(86, 11);
						if (player == 1)
						{
							youWin(player);
						}
						else
						{
							youWin(player);
						}
						time.join();
					}
				}
				player = abs(player - 1);
		
				if (res_M[K / 3][K % 3] != 1 && res_M[K / 3][K % 3] != 0)
				{
					Y = (startingY + moveStepY) + (moveStepY * 3) * (K / 3) ;

					X = (startingX + moveStepX) + (moveStepX * 3) * (K % 3);

					border_top = 1;
					border_left = 1;
					matrix_ind = K;
					K = 4;
				}
				else
				{
					allowed_step = 8;
					border_top = ((Y - 7) / 4) ;
					border_left = ((X - 12) / 8) ;
				}
			}
			break;
		case g_KEY_u: // ASCII code of u
			if(sound == true)
			{
				sound = false;
				
				soundOFF();
			}

		break;	
		case 'q':
			std::cout << "q pressed. Quitting." << std::endl;
			goto EXIT;
		}
		movement(key_ASCII, X, Y, matrix_ind, K, border_top, border_left, allowed_step, moveStepY, moveStepX);
		
	}
	EXIT:
		normal();
}




void easyGamePlay(std::string &xName, std::string &oName)
{
	std::thread time(XOtimer);
	
	short **res_M = new short *[3]; //result matrix
	for (int i = 0; i < 3; ++i)
	{
		res_M[i] = new short[3];
		for (int j = 0; j < 3; ++j)
		{
			res_M[i][j] = (i + 1) * 3 + j;
		}
	}
	const int startingX = 16;
	const int startingY = 9;
	
	const int moveStepX = 24;
	const int moveStepY = 12;
	int X = 16, Y = 9, K = 0;
	int matrix_ind = 0;

	int border_top = 0, border_left = 0;
	const int allowed_step = 2; 
		//    X -> 1    O -> 0

	cbreak();
	short player = 1;
	while (!WIN)
	{
		fflush(stdout);
		gotoxy(X, Y);		
		const char key = keypress();
		int key_ASCII = int(key);
		fflush(stdout); //clear buffer's memory

		if(key_ASCII != 113)
		switch (key_ASCII)
		{
		case  g_KEY_ENTER:
			if (res_M[K / 3][K % 3] != 0 && res_M[K / 3][K % 3] != 1 )
			{
				if (player == 1)
				{

					std::cout << "\033[1;31m██╗░░██╗"; 
					gotoxy(X, Y + 1);
					std::cout << "╚██╗██╔╝";           
					gotoxy(X, Y + 2);
					std::cout << "░╚███╔╝░";           
					gotoxy(X, Y + 3);
					std::cout << "░██╔██╗░";           
					gotoxy(X, Y + 4);
					std::cout << "██╔╝╚██╗";           
					gotoxy(X, Y + 5);
					std::cout << "╚═╝░░╚═╝\033[1;0m";  
					gotoxy(X, Y);
					
				}
				else
				{
					std::cout << "\033[1;36m░█████╗░";
					gotoxy(X, Y + 1);
					std::cout << "██╔══██╗";
					gotoxy(X, Y + 2);
					std::cout << "██║░░██║";
					gotoxy(X, Y + 3);
					std::cout << "██║░░██║";
					gotoxy(X, Y + 4);
					std::cout << "╚█████╔╝";
					gotoxy(X, Y + 5);
					std::cout << "░╚════╝░\033[1;0m";
				}

				res_M[K / 3][K % 3] = player;
				if (check(res_M))
				{
					WIN = true;
					//printf("\033[%d;%dH", 9, 95);
					gotoxy(95, 9);
					std::cout << "WINNNNNNNN" << std::endl;
					//printf("\033[%d;%dH", 11, 86);
					gotoxy(86, 11);
					if (player == 1)
					{
						youWin(player);
					}
					else
					{
						youWin(player);
					}
					time.join();
					system("clear");
				}
				player = abs(player - 1);
		
				Y = startingY + moveStepY ;

				X = startingX + moveStepX ;

					border_top = 1;
					border_left = 1;
					K = 4;	
			}
		break;
		case g_KEY_u: // ASCII code of u
			if(sound == true)
			{
				sound = false;
				
				soundOFF();
			}

		break;
		}
		movement(key_ASCII, X, Y, matrix_ind, K, border_top, border_left, allowed_step, moveStepY, moveStepX);

	}

	EXIT:
		normal();
}
