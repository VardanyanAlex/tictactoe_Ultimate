
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <thread>

#include "../include/importantDetails.hpp"
#include "../include/scriptCalls.hpp"


void printXorO( const int& PlayerPosX, const int& PlayerPosY, const int& whichPlayer)
{
    if(whichPlayer == 1)
    {
        gotoxy(PlayerPosX, PlayerPosY);
        std::cout << "\033[1;31m██╗░░██╗"; 
		gotoxy(PlayerPosX, PlayerPosY + 1);
		std::cout << "╚██╗██╔╝";           
		gotoxy(PlayerPosX, PlayerPosY + 2);
		std::cout << "░╚███╔╝░";           
		gotoxy(PlayerPosX, PlayerPosY + 3);
		std::cout << "░██╔██╗░";           
		gotoxy(PlayerPosX, PlayerPosY + 4);
		std::cout << "██╔╝╚██╗";           
		gotoxy(PlayerPosX, PlayerPosY + 5);
		std::cout << "╚═╝░░╚═╝\033[1;0m";  
    }
    else
    {
        gotoxy(PlayerPosX, PlayerPosY);
        std::cout << "\033[1;36m░█████╗░";
		gotoxy(PlayerPosX, PlayerPosY + 1);
		std::cout << "██╔══██╗";
		gotoxy(PlayerPosX, PlayerPosY + 2);
		std::cout << "██║░░██║";
		gotoxy(PlayerPosX, PlayerPosY + 3);
		std::cout << "██║░░██║";
		gotoxy(PlayerPosX, PlayerPosY + 4);
		std::cout << "╚█████╔╝";
		gotoxy(PlayerPosX, PlayerPosY + 5);
		std::cout << "░╚════╝░\033[1;0m";
    }
}

void youWin(short& whichPlayer)
{

    soundOFF();
    fflush(stdout);
    fflush(stdout);
    sleep(2);
    std::thread victoryEffect(victorySound);
    const int imgDistanceFromLeft = bringCenterWith_X(50)+160;
    const int PlayerPosX = bringCenterWith_X(10);
    const int PlayerPosY = bringCenterWith_Y(18);
    for (int i = 0; i < 3; ++i)
    {
        
        system("clear");
        usleep(500000);
        fflush(stdout);
        //gotoxy(0, bringCenterWith_Y(10));


        printXorO(PlayerPosX, PlayerPosY, whichPlayer);

        gotoxy(imgDistanceFromLeft, PlayerPosY + 7);

        std::cout << std::fixed << std::setw(imgDistanceFromLeft) << BOLDGREEN << " ██╗░░░██╗░█████╗░██╗░░░██╗ ░██╗░░░░░░░██╗██╗███╗░░██╗" << std::endl;
        std::cout << std::fixed << std::setw(imgDistanceFromLeft) << BOLDGREEN << "╚██╗░██╔╝██╔══██╗██║░░░██║ ░██║░░██╗░░██║██║████╗░██║" << std::endl;
        std::cout << std::fixed << std::setw(imgDistanceFromLeft) << BOLDGREEN << "░╚████╔╝░██║░░██║██║░░░██║ ░╚██╗████╗██╔╝██║██╔██╗██║" << std::endl;
        std::cout << std::fixed << std::setw(imgDistanceFromLeft) << BOLDGREEN << "░░╚██╔╝░░██║░░██║██║░░░██║ ░░████╔═████║░██║██║╚████║" << std::endl;
        std::cout << std::fixed << std::setw(imgDistanceFromLeft) << BOLDGREEN << "░░░██║░░░╚█████╔╝╚██████╔╝ ░░╚██╔╝░╚██╔╝░██║██║░╚███║" << std::endl;
 
        usleep(500000);
        //system("clear");
        fflush(stdout);
    }
    victoryEffect.join();
    victorySound();
}                                                                       