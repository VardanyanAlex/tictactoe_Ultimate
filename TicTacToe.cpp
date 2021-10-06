#include<iostream>
#include<string>
#include "include/input.hpp"
#include<stdlib.h>
#include<unistd.h>
//#include<conio.h>
//#include<Windows.h>

//#define tc_move_cursor(X, Y) scanf("\033[%d;%dH", Y, X)

//kogtagorcenq heto
void XOtimer()
{
	int hour = 0, min = 0, sec = 0;
	while(true)
	{
		system("clear");
		std::cout << hour << " : " << min << " : " << sec << std::endl;
		sec++;
		if(sec == 60 )
		{
			sec = 0;
			min++;
			if(min == 60)
			{
				min = 0;
				hour++;
			}
		}
		sleep(1);
		
	}
}

void drawField(int step_Y,int step_X){
	for (int i = 0; i <= 12; i++)
	{
		printf("\033[%d;%dH", 4 + i + step_Y, 8+step_X);
		std::cout << "*                       *";
		if(i % 4 == 0)
		{
			printf("\033[%d;%dH", 4 + i + step_Y, 9+step_X);
			std::cout << "-----------------------";
		}
		else
		{
			printf("\033[%d;%dH", 4 + i + step_Y, 9+step_X);
			for (int i = 0; i < 2; i++)
			{
				
				std::cout << "       |";
			}
			
		}
		std::cout << std::endl;
	}
}

short int check(short** p)
{
	//check columns and rows
	for(int i = 0; i < 3; ++i)
	{
		if(p[i][0] == p[i][1] && p[i][1] == p[i][2] && (p[i][1]==1 || p[i][1]==0) )
		{
			return 1;
		}
		else if(p[0][i] == p[1][i] && p[1][i] == p[2][i] && (p[1][i]==1 || p[1][i]==0) )
		{
			return 1;
		}
	}
	//check diagonals
	short int s_g = 0, s_s = 0;
	for(int i = 0; i < 3; ++i)
	{
		s_g += p[i][i];
		s_s += p[i][2-i];
	}
	if( s_g == 3 || s_s == 3 || (s_g * s_s) == 0) return 1;
	return 0;
}

int main()
{

	std::string name;
	std::cout << "Your name: ";
	std::cin >> name;
	std::cout << "Press 'w' or 'q'. " << std::endl;

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 2; j >= 0; --j)
		{
			drawField(j*13,i*25);
			//usleep(500000);
		}
	}

	short **XO_matrix = new short*[3];
	for (int i = 0; i < 3; ++i){
		XO_matrix[i] = new short[3];
	}
	for (int i = 0; i < 3; ++i){
		for(int j=0; j < 3; ++j){
			XO_matrix[i][j] = 3*(i+1)+j;
		}
	}
	int X = 12,Y = 6;
	int border_top = 0, border_left = 0;
	short player = 1;
	bool win = false;	
	cbreak();

	while (!win) {
		const char key = keypress();
		int key_ASCII = int(key);
		printf("\033[%d;%dH", Y, X);
		switch (key_ASCII) {
		case 10: // ASCII code of ENTER button
			if(XO_matrix[(Y-6)/4][(X-12)/8] != 0 && XO_matrix[(Y-6)/4][(X-12)/8] != 1){
				if(player == 1)
				{
					std::cout << "X"; //<< (X-12)/8 << (Y-6)/4 << std::endl;
					//printf("\033[%d;%dH", Y+1, X);
				}
				else
				{
					std::cout << "O";
				}
				XO_matrix[(Y-6)/4][(X-12)/8] = player;
				if(check(XO_matrix) == 1)
				{
					printf("\033[%d;%dH", 9, 40);
					if(player == 1) std::cout << "X !!!  YOU ARE THE CHAMPION ...";
					else std::cout << "O !!!  YOU ARE THE CHAMPION ...";
					win = true;
					printf("\033[%d;%dH", 25, 30);
				}
				//std::cout<<Y;
				Y = ((Y - 6) / 4) * 17 + 6;
				X = ((X-12) / 8) * 33 + 12;
				printf("\033[%d;%dH", Y, X);
				player = abs(player - 1);
			}
			
			
			break;
		case 83: case 115: //bottom    S
			if(border_top != 2){
				Y += 4;
				++border_top;	
			}
			break;	
		case 68: case 100: //right    D
			if(border_left != 2){
				X += 8;
				++border_left;
			}
			break;
		case 87: case 119: //top    W
			if(border_top != 0){
				Y -= 4;
				--border_top;	
			}
			break;
		case 65: case 97: //left    A
			if(border_left != 0){
				X -= 8;
				--border_left;
			}
			break;
		case 'q':
			std::cout << "q pressed. Quitting." << std::endl;
			goto EXIT;
		}
	}
EXIT:
	normal();

	std::cout << "By, " << name << '!' << std::endl;
	return 0;
}