#include<iostream>
#include<string>
#include "include/input.hpp"
#include<stdlib.h>
#include<unistd.h>

//kogtagorcenq heto
// void XOtimer()
// {
// 	int hour = 0, min = 0, sec = 0;
// 	while(true)
// 	{
// 		system("clear");
// 		std::cout << hour << " : " << min << " : " << sec << std::endl;
// 		sec++;
// 		if(sec == 60 )
// 		{
// 			sec = 0;
// 			min++;
// 			if(min == 60)
// 			{
// 				min = 0;
// 				hour++;
// 			}
// 		}
// 		sleep(1);
		
// 	}
// }

void drawField(){
	for(int n = 0; n < 3; ++n)
	{
		for(int m = 0; m < 3; ++m)
		{
			int step_Y = m*12;
			int step_X = n*24;
			//drawField(j*12,i*24);
			//usleep(500000);
			for (int i = 0; i < 12; i++)
			{
				printf("\033[%d;%dH", 5 + i + step_Y, 8+step_X);
				std::cout << "*                        ";
				if(i % 4 == 0)
				{
					printf("\033[%d;%dH", 5 + i + step_Y, 9+step_X);
					if(i==0){
						std::cout << "***********************";	
					}
					else{
						std::cout << "-----------------------";
					}
				}
				else
				{
					printf("\033[%d;%dH", 5 + i + step_Y, 9+step_X);
					for (int i = 0; i < 2; i++)
					{
				
						std::cout << "       |";
					}	
			
				}
				printf("\033[%d;%dH", 5 + i + step_Y, 80);
				std::cout << "*";
				std::cout << std::endl;
			}
			
		}
		printf("\033[%d;%dH", 41, 8 + 24 * n);
		std::cout << "*************************";	
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
	system("clear");
	std::cout << std::endl << "\t\t\t\t ULTIMATE TIC-TAC-TOE" << std::endl;
	std::string name;
	std::cout << "Your name: ";
	std::cin >> name;
	std::cout << "\t\t\t\t\t\tPLAY WITH   W A S D   +   ENTER" << std::endl;

	// for(int i = 0; i < 3; ++i)
	// {
	// 	for(int j = 0; j < 3; ++j)
	// 	{
	// 		// drawField();
	// 		//usleep(500000);
	// 	}
	// }
	drawField();
	short ***XO_matrix = new short**[9];       //whole matrix
	for (int i = 0; i < 9; ++i){
		XO_matrix[i] = new short*[3];
		for(int j = 0; j < 3; ++j)
		{
			XO_matrix[i][j] = new short[3];
		}
	}
	for (int i = 0; i < 9; ++i){
		for(int j=0; j < 3; ++j){
			for(int k=0; k < 3; ++k){
				XO_matrix[i][j][k] = 3*(i+1)+j;
			}
		}
	}

	short **res_M = new short*[3];             //result matrix
    for (int i = 0; i < 3; ++i)
    {
        res_M[i] = new short[3];
		for(int j=0; j < 3; ++j){
			res_M[i][j] = (i + 1) * 3 + j;
		}
    }

	int X = 12,Y = 7, K = 0;
	int matrix_ind = 0;

	int border_top = 0, border_left = 0;
	int allowed_step = 2;              //then at at first wiill be 8
	short player = 1;     //    X -> 1    O -> 0

	bool WIN = false;	
	

	cbreak();

	while (!WIN) {
		const char key = keypress();
		int key_ASCII = int(key);
		printf("\033[%d;%dH", Y, X);
		switch (key_ASCII) {
		case 10: // ASCII code of ENTER button
			
			allowed_step = 2;
			if(XO_matrix[matrix_ind][K / 3][K % 3] != 0 && XO_matrix[matrix_ind][K / 3][K % 3] != 1){
					
				if(player == 1)
				{
					std::cout << "X"; 
				}
				else
				{
					std::cout << "O";
				}
				
				XO_matrix[matrix_ind][K / 3][K % 3] = player;
				if(check(XO_matrix[matrix_ind]) == 1)
                {
					std::cout<<matrix_ind / 3 << matrix_ind % 3;
                	res_M[matrix_ind / 3][matrix_ind % 3] = player;
                    if( check(res_M) ){
                		WIN = true;
                        printf("\033[%d;%dH", 9, 95);
                        std::cout << "WINNNNNNNN" << std::endl;
						printf("\033[%d;%dH", 11, 86);
                        if(player == 1) std::cout << "X !!!  YOU ARE THE CHAMPION ...";
                        else std::cout << "O !!!  YOU ARE THE CHAMPION ...";
                        //printf("\033[%d;%dH", 25, 30);
                    }
                }
				player = abs(player - 1);
				if(res_M[K / 3][K % 3] != 1 && res_M[K / 3][K % 3] != 0)
				{	
					Y = 11 + 11 * (K / 3) + (K / 3);

					X=20 + 24 * (K % 3) ;

					printf("\033[%d;%dH", Y, X);

					border_top = 1;
					border_left = 1;
					matrix_ind = K;
					K = 4;
				}
			}
			
			
			break;
		case 83: case 115: //bottom    S
			if(border_top != allowed_step){
				Y += 4;
				++border_top;
				K += 3;	
			}
			break;	
		case 68: case 100: //right    D
			if(border_left != allowed_step){
				X += 8;
				++border_left;
				++K;
			}
			break;
		case 87: case 119: //top    W
			if(border_top != 0){
				Y -= 4;
				--border_top;
				K -= 3;	
			}
			break;
		case 65: case 97: //left    A
			if(border_left != 0){
				X -= 8;
				--border_left;
				--K;
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