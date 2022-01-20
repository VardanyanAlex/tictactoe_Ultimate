
#include <iostream> 

#include "../include/scriptCalls.hpp"

void soundON()
{
	system("./scripts/soundOn.sh");
}

void soundOFF()
{
	system("./scripts/soundOff.sh");
}

void victorySound()
{
	system("./scripts/victorySoundOn.sh");
	//std::cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";	
}
