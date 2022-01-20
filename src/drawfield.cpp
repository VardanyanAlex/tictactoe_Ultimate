
#include <iostream>
#include <unistd.h>


#include "../include/drawfield.hpp"
#include "../include/importantDetails.hpp"

void colourizeField(int posX, int posY, int whichPlayer)
{
	for (size_t i = 0; i < 3; ++i)
	{
		gotoxy(posX, posY + i);
		if(whichPlayer == 1)
		{
			std::cout << RED << "███████";
		}
		else
		{
			std::cout << CYAN << "███████";
		}
	}
	gotoxy(posX + 2, posY + 1);
	std::cout << RESET <<( (whichPlayer == 1) ? " x " : " ᴏ ") ;
}

void fillOneBox(int posX, int posY, int whichPlayer)
{
	for (size_t i = 0; i < 12; i += 4)
	{
		for (size_t j = 0; j < 24; j += 8)
		{
			colourizeField(posX + j, posY + i, whichPlayer);

		}
	}
	
}

void fieldPartofHardGameplay();

void colourOneField(int y, int x, int whichColour)
{
	printf("\033[%d;%dH", 8 + 1 + y * 12, 9 + x * 24);
	std::cout << BLUE;
	if(whichColour == 1)
	{
		std::cout << "-----------------------";
	}
	else
	{
		std::cout << GRAY << "-----------------------";
	}
	for(int i = 0; i < 11; ++i)
	{
		printf("\033[%d;%dH", i + 6 + y * 12, 8 + 8 + x * 24);
		std::cout << "|";
		printf("\033[%d;%dH", i + 6 + y * 12, 8 + 8 + 8 + x * 24);
		std::cout << "|";
	}
	printf("\033[%d;%dH", 8 + 1 + 4 + y * 12, 9 + x * 24);
	std::cout << "-----------------------" << RESET;
}


void sidebar(const std::string& xName, const std::string& oName)
{
	std::cout << BLUE;
	for(size_t i = 0; i < 37; ++i)
	{
		gotoxy(116, 5 + i);
		std::cout << "■";
	}
	gotoxy(81, 5);
	std::cout << " ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■";
	gotoxy(83, 6);
	std::cout << BOLDGREEN << "■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■";
	for(size_t i = 0; i < 33; ++i)
	{
		gotoxy(82, 7 + i);
		std::cout << "■                               ■";
		//usleep(500000);
	}

	gotoxy(84, 14);
	std::cout << GRAY <<       "-----------------------------" << RESET;
	gotoxy(97, 16);
	std::cout << "🎮";
	gotoxy(90, 18);
	std::cout << BOLDYELLOW << "𝚆 𝙰 𝚂 𝙳   ⬅ ⬆ ⬇ ➡";
	gotoxy(96, 19);
	std::cout << BOLDYELLOW << "𝙴𝙽𝚃𝙴𝚁"; 
	gotoxy(84, 22);
	std::cout << GRAY <<       "-----------------------------" << RESET;
	gotoxy(95, 24);
	std::cout << BLUE << "𝙿𝙻𝙰𝚈𝙴𝚁𝚂";
	gotoxy(90, 26);
	std::cout << RESET << "𝙿𝙻𝙰𝚈𝙴𝚁 𝗫   " << RED << xName;
	gotoxy(90, 28);
	std::cout << RESET << "𝙿𝙻𝙰𝚈𝙴𝚁 𝗢   " << CYAN << oName << RESET;
	gotoxy(84, 30);
	std::cout << GRAY <<       "-----------------------------" << RESET;
	gotoxy(90, 32);
	std::cout << "𝖲𝗈𝗎𝗇𝖽 𝖮𝖿𝖿 🔇 :" << BOLDYELLOW << " 🅄" << RESET;
	gotoxy(96, 39);
	std::cout << GRAY  << "Ⓒ 2021" << RESET;
	gotoxy(83, 40);           
	std::cout << BOLDGREEN << "■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■";
	gotoxy(81, 41);
	std::cout << BLUE << " ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■";
	std::cout << RESET;
}



void drawField(const int& difficultyLvl){
	system("clear");
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
				std::cout << BLUE << "■" << RESET << "                        ";
				if(i % 4 == 0)         //░░░░░░░░░░                        
				{
					printf("\033[%d;%dH", 5 + i + step_Y, 9+step_X);
					if(i==0){
						std::cout << BLUE << " ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■";	
					}             //  ■■■■■■■■■■■■■■■■■■■■■■■ ◩◩◩◩◩◩◩◩◩◩◩◩
					// else{
					// 	std::cout << "-----------------------";
					// }
				}
				else
				{
					// printf("\033[%d;%dH", 5 + i + step_Y, 9+step_X);
					// for (int i = 0; i < 2; i++)
					// {
				
					// 	std::cout << "       |";
					// }	
			
				}
				printf("\033[%d;%dH", 5 + i + step_Y, 80);
				std::cout << BLUE << "■";
				std::cout << RESET << std::endl;
			}
			
		}
		printf("\033[%d;%dH", 41, 8 + 24 * n);
		std::cout << BLUE << "■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■", RESET;
		//	          █████████████████████████
	}

	if (difficultyLvl == 1)
	{
		fieldPartofHardGameplay();
	}
	std::cout << RESET;
}

void fieldPartofHardGameplay()
{
	for(int n = 0; n < 3; ++n)
	{
		for(int m = 0; m < 3; ++m)
		{
			size_t step_Y = m*12;
			size_t step_X = n*24;

			for (int i = 1; i < 12; ++i)
			{
				if(i % 4 == 0 && i != 0)         //░░░░░░░░░░░░░░░░░░░░░░░░  
				{
					printf("\033[%d;%dH", 5 + i + step_Y, 9+step_X);
					std::cout << GRAY << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬";
				}                         //▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬
				else
				{
					printf("\033[%d;%dH", 5 + i + step_Y, 9+step_X);
					for (int i = 0; i < 2; i++)
					{
		
					std::cout << RESET << "       " << GRAY << "┃" << RESET;
					}                              
				}	
			
			}
		}
	}
	
}
