#include <iostream>
#include <iomanip>

#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "../include/imageOnStart.hpp"
#include "../include/gameTitle.hpp"
#include "../include/importantDetails.hpp"

void startingImage()
{
        system("clear");
        //bringCenterWith_Y(18);
        
        
        int imgDistanceFromLeft = bringCenterWith_X(105);
        gotoxy(imgDistanceFromLeft, bringCenterWith_Y(18));
        std::cout << std::setw(10) << "                                                                  \n";
        std::cout << std::setw(imgDistanceFromLeft) << ' ' <<"\033[1;91m░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n";
        std::cout << std::setw(imgDistanceFromLeft) << ' ' << "\033[1;91m░░░░░░░░░░░░░░░░██╗░░░██╗░██╗░░░░░░████████╗░██╗░███╗░░░███╗░░█████╗░░████████╗░███████╗░░░░░░░░░░░░░░░░\n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "░░░░░░░░░░░░░░░░██║░░░██║░██║░░░░░░╚══██╔══╝░██║░████╗░████║░██╔══██╗░╚══██╔══╝░██╔════╝░░░░░░░░░░░░░░░░\n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "░░░░░░░░░░░░░░░░██║░░░██║░██║░░░░░░░░░██║░░░░██║░██╔████╔██║░███████║░░░░██║░░░░█████╗░░░░░░░░░░░░░░░░░░\n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "░░░░░░░░░░░░░░░░██║░░░██║░██║░░░░░░░░░██║░░░░██║░██║╚██╔╝██║░██╔══██║░░░░██║░░░░██╔══╝░░░░░░░░░░░░░░░░░░\n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "░░░░░░░░░░░░░░░░╚██████╔╝░███████╗░░░░██║░░░░██║░██║░╚═╝░██║░██║░░██║░░░░██║░░░░███████╗░░░░░░░░░░░░░░░░\n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "░░░░░░░░░░░░░░░░░╚═════╝░░╚══════╝░░░░╚═╝░░░░╚═╝░╚═╝░░░░░╚═╝░╚═╝░░╚═╝░░░░╚═╝░░░░╚══════╝░░░░░░░░░░░░░░░░\n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\033[0m \n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "\033[1;96m░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\033[0m \n";

        std::cout << std::setw(imgDistanceFromLeft) << ' ' << "\033[1;96m░░░░░░████████╗░██╗░░█████╗░░░░░░░░░████████╗░░█████╗░░░█████╗░░░░░░░░░████████╗░░█████╗░░███████╗░░░░░░\n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "░░░░░░╚══██╔══╝░██║░██╔══██╗░░░░░░░░╚══██╔══╝░██╔══██╗░██╔══██╗░░░░░░░░╚══██╔══╝░██╔══██╗░██╔════╝░░░░░░\n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "░░░░░░░░░██║░░░░██║░██║░░╚═╝░\033[0m\033[1;91m█████╗\033[0m\033[1;96m░░░░██║░░░░███████║░██║░░╚═╝░\033[0m\033[1;91m█████╗\033[0m\033[1;96m░░░░██║░░░░██║░░██║░█████╗░░░░░░░░\n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "░░░░░░░░░██║░░░░██║░██║░░██╗░\033[0m\033[1;91m╚════╝\033[0m\033[1;96m░░░░██║░░░░██╔══██║░██║░░██╗░\033[0m\033[1;91m╚════╝\033[0m\033[1;96m░░░░██║░░░░██║░░██║░██╔══╝░░░░░░░░\n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "░░░░░░░░░██║░░░░██║░╚█████╔╝░░░░░░░░░░░██║░░░░██║░░██║░╚█████╔╝░░░░░░░░░░░██║░░░░╚█████╔╝░███████╗░░░░░░\n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "░░░░░░░░░╚═╝░░░░╚═╝░░╚════╝░░░░░░░░░░░░╚═╝░░░░╚═╝░░╚═╝░░╚════╝░░░░░░░░░░░░╚═╝░░░░░╚════╝░░╚══════╝░░░░░░\n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n";
                  std::cout << std::setw(imgDistanceFromLeft) << ' ' << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\033[1;0m\n";
        sleep(2);
        system("clear");
}

