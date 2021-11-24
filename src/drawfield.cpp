
#include <iostream>
#include "../include/drawfield.hpp"


void drawField()
{
	for (int n = 0; n < 3; ++n)
	{
		for (int m = 0; m < 3; ++m)
		{
			int step_Y = m * 6;
			int step_X = n * 12;

			for (int i = 0; i < 6; i++)
			{
				printf("\033[%d;%dH", 6 + i + step_Y, 8 + step_X);
				std::cout << "*              ";
				if (i % 2 == 0)
				{
					printf("\033[%d;%dH", 6 + i + step_Y, 9 + step_X);
					if (i == 0)
					{
						std::cout << "***********";
					}
					else
					{
						std::cout << "-----------";
					}
				}
				else
				{
					printf("\033[%d;%dH", 6 + i + step_Y, 9 + step_X);
					for (int i = 0; i < 2; ++i)
					{

						std::cout << "   |";
					}
				}
				printf("\033[%d;%dH", 6 + i + step_Y, 44);
				std::cout << "*";
				std::cout << std::endl;
			}
		}
		printf("\033[%d;%dH", 24, 8 + 12 * n);
		std::cout << "*************";
	}
}

void colourOneField(int y, int x, int whichColour)
{
	printf("\033[%d;%dH", 7 + 1 + y * 6, 9 + x * 12);
	if(whichColour == 1)
	{
		std::cout << "\033[1;31m-----------";
	}
	else
	{
		std::cout << "\033[1;36m-----------";
	}
	for(int i = 1; i < 6; ++i)
	{
		printf("\033[%d;%dH", i + 6 + y * 6, 6 + 6 + x * 12);
		std::cout << "|";
		printf("\033[%d;%dH", i + 6 + y * 6, 6 + 6 + 4 + x * 12);
		std::cout << "|";
	}
	printf("\033[%d;%dH", 7 + 1 + 2 + y * 6, 9 + x * 12);
	std::cout << "-----------\033[1;0m";
}