
#include <iostream>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "../include/importantDetails.hpp"



const size_t TERMINAL_SIZE_X = 116;
const size_t TERMINAL_SIZE_Y = 45;

void defaultDisplaySize()
{
  struct winsize w;
	
	//std::cout << "\e[8;36;100t";

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if(w.ws_col<TERMINAL_SIZE_X || w.ws_row<TERMINAL_SIZE_Y) 
	{
		printf("\e[8;%d;%dt", TERMINAL_SIZE_Y, TERMINAL_SIZE_X);
	}
}



void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", y, x);
    //std::cout << std::endl;
}

int bringCenterWith_X(int lenOfSmth)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);    
  //std::cout << w.ws_col;
    return int((w.ws_col - lenOfSmth) / 2);
}

int bringCenterWith_Y(int heightOfSmth)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);    

    //gotoxy(0, (w.ws_row - heightOfSmth) / 2);
    return int((w.ws_row - heightOfSmth) / 2);
}

static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}
