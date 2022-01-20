
#include "../include/gameTitle.hpp"
#include "../include/input.hpp"
#include "../include/importantDetails.hpp"
//#include "../include/importantDetails.hpp"

#include <iostream>
#include <string>

const short g_KEY_W = 119;
const short g_KEY_S = 115;
const short g_KEY_ARROW_TOP = 65;
const short g_KEY_ARROW_BOTTOM = 66;

const short g_PLAYER_NAME_MAXSIZE = 8;

int selectDifficulty(int &lvl)
{
	std::string select = "Select difficulty level.";
	std::string easy1 = "  █▀▀ ▄▀█ █▀ █▄█ ";
	std::string easy2 = "  ██▄ █▀█ ▄█  █  ";
	std::string hard1 = "  █ █ ▄▀█ █▀█ █▀▄";
	std::string hard2 = "  █▀█ █▀█ █▀▄ █▄▀"; 

	// int x_cord = bringCenterWith_X(select.length());
	// int y_cord = bringCenterWith_Y(1);
	// gotoxy(x_cord, y_cord);
	// //printf("\033[%d;%dH", (TERMINAL_SIZE_Y / 2) - 4, TERMINAL_SIZE_X / 2 - 10);
	// std::cout << select << std::endl;
	int y_cord = bringCenterWith_Y(1);
	int x_cord = bringCenterWith_X(easy1.length() / 3);
	gotoxy(x_cord, y_cord - 2);
	std::cout << "\033[1;36m" << easy1 ;    
	gotoxy(x_cord-1, y_cord - 1);
	std::cout << "\033[1;31m𝙭\033[1;36m" << easy2 << "\033[1;31m ⓞ\033[1;0m";
	x_cord = bringCenterWith_X(hard1.length() / 3);
	gotoxy(x_cord, y_cord+1);
	std::cout << hard1 ;
	gotoxy(x_cord, y_cord+2);
	std::cout << hard2 ;

	bool difSelected = false;

	while(!difSelected)
	{
		gotoxy(0, 0);
		cbreak();
		const char key = keypress();
		int key_ASCII = int(key);
		//fflush(stdout); //clear buffer's memory
		//gotoxy(80, 80);d
			
		switch (key)
		{
		case 10: // ASCII code of ENTER button
			difSelected = true;
			goto EXIT;
			
			break;
		//case 66:
		case g_KEY_S:
		case g_KEY_ARROW_BOTTOM: 
			if(lvl == 0) 
			{
				lvl = 1;
				gotoxy(x_cord, y_cord-2);
				std::cout << easy1 ;
				gotoxy(x_cord - 1, y_cord-1);
				std::cout << " " << easy2 << "  " ;
				x_cord = bringCenterWith_X(hard1.length() / 3);
				gotoxy(x_cord, y_cord+1);
				std::cout << "\033[1;36m" << hard1 ;
				gotoxy(x_cord - 1, y_cord+2);
				std::cout << "\033[1;31m𝙭\033[1;36m" << hard2 << "\033[1;31m ⓞ\033[1;0m";
			}
			break;
		case g_KEY_W:
		case g_KEY_ARROW_TOP: 
			if(lvl == 1) 
			{
				lvl = 0;
				y_cord = bringCenterWith_Y(1);
				x_cord = bringCenterWith_X(easy1.length() / 3);
				gotoxy(x_cord, y_cord - 2);
				std::cout << "\033[1;36m" << easy1 ;    
				gotoxy(x_cord - 1, y_cord - 1);
				std::cout << "\033[1;31m𝙭\033[1;36m" << easy2 << "\033[1;31m ⓞ\033[1;0m";
				x_cord = bringCenterWith_X(hard1.length() / 3);
				gotoxy(x_cord, y_cord+1);
				std::cout << hard1 ;
				gotoxy(x_cord - 1, y_cord + 2);
				std::cout << " " << hard2 << "  " ;
			}
			break;
		}
		EXIT:
		normal();
	}
	gotoxy(0,5);
	std::cout << "\033[2J";
	return lvl;
}

void gameTitle(std::string &xName, std::string &oName, int &lvl)
{
	std::cout << std::endl << "\t\t\t\t ULTIMATE TIC-TAC-TOE" << std::endl << std::endl;
//	bringCenterWith_Y(1);
	//int distanceFromLeft = bringCenterWith_X(17);

	int playerNameText_length = 10;
	int x_center = bringCenterWith_X(playerNameText_length+15);
	int y_center = bringCenterWith_Y(1);
	gotoxy(x_center + playerNameText_length + 2, y_center-1);
	                      //std::cout <<"░▄▄▄▄▄▄▄▄▄▄◤░";
	gotoxy(x_center, y_center);                                      
	std::cout << "\033[1;31m𝖯𝖫𝖠𝖸𝖤𝖱 𝖷  \033[1;0m             " << "\033[1;32m(𝒎𝒂𝒙 8 𝒅𝒊𝒈𝒊𝒕𝒔)\033[1;0m";
	gotoxy(x_center + playerNameText_length, y_center + 1); 
	std::cout << "▔▔▔▔▔▔▔▔▔▔▔▔";   

	                      //std::cout << "▄▄▄▄▄▄▄▄◤";
	gotoxy(bringCenterWith_X(playerNameText_length) + 4, bringCenterWith_Y(1));
	for(size_t i = 0; i < g_PLAYER_NAME_MAXSIZE; ++i)
	{
		char c = getche();
		if(  (int(c) > 96 && int(c) < 123) || (int(c) > 47 && int(c) < 58) ) 
		{
			xName += c;
		} 
		else if(int(c) == 10) 
		{
			break;
		}	
	}
	//std::cin >> xName;	

				//"░░░░░░░   " 
	gotoxy(x_center, y_center + 2);
	std::cout << "\033[1;36m𝖯𝖫𝖠𝖸𝖤𝖱 𝖮  \033[1;0m             " << "\033[1;32m(𝒎𝒂𝒙 8 𝒅𝒊𝒈𝒊𝒕𝒔)\033[1;0m";
	gotoxy(x_center + playerNameText_length, y_center + 3); 
	std::cout << "▔▔▔▔▔▔▔▔▔▔▔▔"; 
	gotoxy(bringCenterWith_X(playerNameText_length) + 4, bringCenterWith_Y(1) + 2);
	for(size_t i = 0; i < g_PLAYER_NAME_MAXSIZE; ++i)
	{
		char c = getche();
		if( (int(c) > 96 && int(c) < 123) || (int(c) > 47 && int(c) < 58) ) 
		{
			oName += c;
		} 
		else if(int(c) == 10) 
		{
			break;
		}
	}

	system("clear");
	selectDifficulty(lvl);
	system("clear");

	std::cout << "\t\t\t\t\t\t\t  W A S D   +   ENTER" << std::endl;
	std::cout << "\t Player X: \033[1;31m" << xName << "\033[1;0m\t\t\t\t\t\t Player O: \033[1;36m" << oName << "\033[1;0m";
	fflush(stdout);
}
