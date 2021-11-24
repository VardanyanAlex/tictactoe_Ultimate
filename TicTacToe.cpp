#include <iostream>
#include <string>

#include "include/input.hpp"
#include "include/drawfield.hpp"
#include "include/imageOnStart.hpp"
#include "include/checkWin.hpp"
#include "include/gameTitle.hpp"

#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>
//#include <SDL2/SDL.h>
#include <pthread.h>

extern const size_t TERMINAL_SIZE_X = 100;
extern const size_t TERMINAL_SIZE_Y = 36;
static bool WIN = false;



const short KEY_A = 65;
const short KEY_a = 97;
//int fd[2];


void* XOtimer(void* arg)
{
	short hour = 0, min = 0, sec = 0;
	printf("\033[%d;%dH", 4, 90);
	std::cout << "T I M E";
	//using namespace std::literals::chrono_literals;
	while (!WIN)
	{		
		
		printf("\033[%d;%dH", 5, 89);
		std::cout.setf(std::ios::unitbuf);
		std::cout << hour << " : " << min << " : " << sec << " " ;
		fflush(stdout);
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
		fflush(stdout);
		sleep(1);
		fflush(stdout);
		//std::this_thread::sleep_for(1s);
	}
	return NULL;
}

/*
void playerNameBlinker(std::string &xName, std::string &oName){
	short switcher = 1;

    if(pipe(fd) == -1) 
    {
        printf("error with pipe(), pls check descriptors array and system file capacity ! ");
        exit(1);
    }
	int fork_ID = fork();
	
	if (fork_ID == 0)
	{
		int player1 = 1;
		fflush(stdout);
		while(!WIN)
		{
			close(fd[1]);
			read(fd[0], &player1, 4);
			
			fflush(stdout);
			printf("\033[%d;%dH", 5, 8);
			if (player1 == 1)
			{
				if (switcher == 1)
				{
					std::cout << "\t Player X: \033[1;31m" << xName << "\033[1;0m\t\t\t\t\t\t Player O: \033[1;36m" << oName << "\033[1;0m";
					switcher = 0;
				}
				else
				{
					std::cout << "\t           \033[1;31m" << xName << "\033[1;0m\t\t\t\t\t\t Player O: \033[1;36m" << oName << "\033[1;0m";
					switcher = 1;
				}
				fflush(stdout);
				sleep(1);
			}
			else
			{
				if (switcher == 1)
				{
					std::cout << "\t Player X: \033[1;31m" << xName << "\033[1;0m\t\t\t\t\t\t Player O: \033[1;36m" << oName <<player1<< "\033[1;0m";
					switcher = 0;
				}
				else
				{                                                                                        
					std::cout << "\t Player X: \033[1;31m" << xName << "\033[1;0m\t\t\t\t\t\t                    \033[1;0m";
					switcher = 1;
				}
				fflush(stdout);
				sleep(1);
			}
			close(fd[0]);
			fflush(stdout);
		}
		
	}
}
*/
void gamePlay(std::string &xName, std::string &oName)
{
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
	const int startingX = 10;
	const int startingY = 7;
	
	const int moveStepX = 4;
	const int moveStepY = 2;
	int X = 10, Y = 7, K = 0;
	int matrix_ind = 0;

	int border_top = 0, border_left = 0;
	int allowed_step = 8; 
		//    X -> 1    O -> 0

	cbreak();
	short player = 1;
	while (!WIN)
	{
		fflush(stdout);
		printf("\033[%d;%dH", Y, X);		
		const char key = keypress();
		int key_ASCII = int(key);
		fflush(stdout); //clear buffer's memory

		switch (key_ASCII)
		{
		case 10: // ASCII code of ENTER button

			if (XO_matrix[matrix_ind][K / 3][K % 3] != 0 && XO_matrix[matrix_ind][K / 3][K % 3] != 1 && res_M[matrix_ind / 3][matrix_ind % 3] != 0 && res_M[matrix_ind / 3][matrix_ind % 3] != 1)
			{
				allowed_step = 2;
				if (player == 1)
				{
					std::cout << "\033[1;31mX\033[1;0m"; //red X
				}
				else
				{
					std::cout << "\033[1;36mO\033[1;0m"; ///blue O
				}

				XO_matrix[matrix_ind][K / 3][K % 3] = player;
				if (check(XO_matrix[matrix_ind]) == 1)
				{
					//std::cout<<matrix_ind / 3 << matrix_ind % 3;
					res_M[matrix_ind / 3][matrix_ind % 3] = player;
					colourOneField(matrix_ind / 3, matrix_ind % 3, player);
					if (check(res_M))
					{
						WIN = true;
						printf("\033[%d;%dH", 9, 95);
						std::cout << "WINNNNNNNN" << std::endl;
						printf("\033[%d;%dH", 11, 86);
						if (player == 1)
							std::cout << xName << " !!!  YOU ARE THE CHAMPION ...";
						else
							std::cout << oName << " !!!  YOU ARE THE CHAMPION ...";
						//printf("\033[%d;%dH", 25, 30);
					}
				}
				player = abs(player - 1);
				// close(fd[0]);
				// write(fd[1], &player, 4);
				// close(fd[1]);				
				if (res_M[K / 3][K % 3] != 1 && res_M[K / 3][K % 3] != 0)
				{
					Y = (startingY + 2) + (moveStepY * 3) * (K / 3) ;

					X = (startingX + 4) + (moveStepX * 3) * (K % 3);


					border_top = 1;
					border_left = 1;
					matrix_ind = K;
					K = 4;
				}
				else
				{
					allowed_step = 8;
					border_top = ((Y - 7) / 2) ;
					border_left = ((X - 10) / 4) ;
				}
			}
			break;
		case 83:
		case 115: //bottom    S
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
		case 68:
		case 100: //right    D
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
		case 87:
		case 119: //top    W
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
		case KEY_A:
		case KEY_a: //left    A
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
		case 'q':
			std::cout << "q pressed. Quitting." << std::endl;
			goto EXIT;
		}

	}
EXIT:
	normal();
}


int main()
{
	//struct winsize w;
	printf("\e[8;%d;%dt", TERMINAL_SIZE_Y, TERMINAL_SIZE_X);
	//std::cout << "\e[8;36;100t";
	// w.ws_xpixel=1000;
	// w.ws_ypixel = 900;
	// ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	
    // printf ("lines %d\n", w.ws_row);
    // printf ("columns %d\n", w.ws_col);
	startingImage();
	std::string xName, oName;
	system("clear");
	gameTitle(xName, oName);
	//std::thread ttimer(XOtimer);
	drawField();
	//pthread_t xoTimer;
	//pthread_create(&xoTimer, NULL, XOtimer, NULL);
	gamePlay(xName, oName);
	//pthread_join(xoTimer, NULL);
	//ttimer.join();
	// int fork_ID = fork();
	// if (fork_ID == 0)
	// {
	// 	XOtimer();
	// }
	// else
	// {
	// 	drawField();
	// 	gamePlay(xName, oName);
	// }

	return 0;
}