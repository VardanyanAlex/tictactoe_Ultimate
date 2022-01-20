#ifndef IMPORTANTDETAILS_HPP
#define IMPORTANTDETAILS_HPP

#define RESET "\033[1;0m"
#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define GRAY "\033[1;90m"
#define BLUE "\033[1;94m"
#define BOLDGREEN   "\033[1m\033[32m"  
#define BOLDYELLOW  "\033[1m\033[33m"      


/*
* Brief:  moves cursor to (x,y) 
*/
void gotoxy(int x, int y);

int bringCenterWith_X(int lenOfSmth);

int bringCenterWith_Y(int heightOfSmth);

// Brief:  set default display min size 
void defaultDisplaySize();

/*
* Brief: Initialize new terminal i/o settings 
*/
void initTermios(int echo) ;

/*
* Brief:  Restore old terminal i/o settings
*/
void resetTermios(void) ;

/*
* Brief:  Read 1 character - echo defines echo mode
*/
char getch_(int echo) ;

/*
* Brief:  Read 1 character without echo
*/
char getch(void) ;

/*
* Brief:  Read 1 character with echo
*/
char getche(void) ;


#endif // IMPORTANTDETAILS_HPP
