
#include "../include/gameTitle.hpp"

#include <iostream>
#include <string>

void gameTitle(std::string &xName, std::string &oName)
{
	std::cout << std::endl << "\t\t\t\t ULTIMATE TIC-TAC-TOE" << std::endl << std::endl;
	printf("\033[%d;%dH", (TERMINAL_SIZE_Y / 2) - 3, TERMINAL_SIZE_X / 2 - 10);
	std::cout << "Player1(X) name: ";
	std::cin >> xName;
	printf("\033[%d;%dH", (TERMINAL_SIZE_Y / 2) - 2, TERMINAL_SIZE_X / 2 - 10);
	std::cout << "Player2(O) name: ";
	std::cin >> oName;

	system("clear");

	std::cout << "\t\t\t\t\t\t\t  W A S D   +   ENTER" << std::endl;
	std::cout << "\t Player X: \033[1;31m" << xName << "\033[1;0m\t\t\t\t\t\t Player O: \033[1;36m" << oName << "\033[1;0m";
	fflush(stdout);
}
