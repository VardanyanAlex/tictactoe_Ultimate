#include <iostream>
#include <string>
#include <thread>
#include <mutex>

#include "include/input.hpp"
#include "include/drawfield.hpp"
#include "include/imageOnStart.hpp"
//#include "include/checkWin.hpp"
#include "include/gameTitle.hpp"
#include "include/gameplay.hpp"
#include "include/importantDetails.hpp"
#include "include/youWin.hpp"
#include "include/scriptCalls.hpp"


bool WIN = false;



int main()
{
	defaultDisplaySize();	
  
	startingImage();
	std::string xName, oName;
	int difficulty = 0;  // 0 -> EASY   |   1 -> HARD
	system("clear"); 
	gameTitle(xName, oName, difficulty);
	
	drawField(difficulty);
	sidebar(xName, oName);
	std::thread music(soundON);
	
	(difficulty == 0) ? easyGamePlay(xName, oName) : hardGamePlay(xName, oName);
	music.join();

	return 0;
}
