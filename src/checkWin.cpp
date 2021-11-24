#include "../include/checkWin.hpp"

short int check(short **p)
{
	//check columns and rows
	for (int i = 0; i < 3; ++i)
	{
		if (p[i][0] == p[i][1] && p[i][1] == p[i][2] && (p[i][1] == 1 || p[i][1] == 0))
		{
			return 1;
		}
		else if (p[0][i] == p[1][i] && p[1][i] == p[2][i] && (p[1][i] == 1 || p[1][i] == 0))
		{
			return 1;
		}
	}
	//check diagonals
	short int s_g = 0, s_s = 0;
	for (int i = 0; i < 3; ++i)
	{
		s_g += p[i][i];
		s_s += p[i][2 - i];
	}
	if (s_g == 3 || s_s == 3 || (s_g * s_s) == 0)
		return 1;
	return 0;
}
