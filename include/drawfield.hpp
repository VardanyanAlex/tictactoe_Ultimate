#ifndef DRAWFIELD_HPP
#define DRAWFIELD_HPP

/*
* Brief: fills one box Red(X) or CYAN(O)
* Pre-condition: (X)whichPlayer=1 or (O)whichPlayer=0 
*/
void fillOneBox(int posX, int posY, int whichPlayer);

void colourizeField(int posX, int posY, int whichPlayer);

/*
* Brief: prints sidebar on the right side of game field
*/
void sidebar(const std::string& xName, const std::string& oName);

/*
* Brief: draws the whole XO field 
* Pre-condition: difficultyLvl=1 (Hard level) or difficultyLvl=0 (Easy level)
*/
void drawField(const int& difficultyLvl);

/*
* Brief: in console we'll have 9X9 matrix 
*/
void fieldPartofHardGameplay();

/*
* Brief: colours ONE XO field  
*/
//void colourOneField(int y, int x, int whichColour);

#endif // DRAWFIELD_HPP
