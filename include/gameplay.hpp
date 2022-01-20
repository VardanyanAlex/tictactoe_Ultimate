#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include <string>

/*
* Brief: timer that works in another thread  
*/
void XOtimer();

/*
* Brief: organizes all movement actions of the game
* Pre-condition: X, Y and matrix_ind are valid integers 
*/
void movement(int key, int& X, int& Y, int& matrix_ind, int& K, int& border_top, int& border_left,const int allowed_step,const int moveStepY, const int moveStepX);

/*
* Brief: gaming and main logic of the game with mode HARD
*/
void hardGamePlay(std::string &xName, std::string &oName);

/*
* Brief: gaming and main logic of the game with mode EASY
*/
void easyGamePlay(std::string &xName, std::string &oName);

#endif // GAMEPLAY_HPP
