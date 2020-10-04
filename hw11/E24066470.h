#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int E12345678(const vector < vector<char> > &, char, char);

int E12345678(const vector < vector<char> > &b, char mydisc, char yourdisc) {
	static const char me = mydisc; //Record the disc type main function assigns for this AI. It never changes once assigned
	static const char opponent = yourdisc; //Record the disc type main function assigns for another AI. It never changes once assigned
	int column = -1;
	//Write your AI here
	vector<vector<char>> tem;
	int possible[7];

	tem = b;
	srand(time(NULL));

	for (int i = 0; i < 7; i++)
	{
		for (int j = 5; j >= 0; j--)
		{
			if (tem[j][i] != me && tem[j][i] != opponent)
			{
				possible[i] = j;
				break;
			}
		}
	}

	for (int i = 0; i < 7; i++)
	{
		int l_place;
		int c_place;
		c_place = i;
		l_place = possible[i];
		if (c_place>2 && l_place<3 && (tem[0][column] != me && tem[0][column] != opponent))
		{
			if (tem[l_place + 1][c_place - 1] == opponent && tem[l_place + 2][c_place - 2] == opponent && tem[l_place + 3][c_place - 3] == opponent)
			{
				column = c_place;
			}
		}
		else if (c_place < 4 && l_place < 3 && (tem[0][column] != me && tem[0][column] != opponent))
		{
			if (tem[l_place + 1][c_place + 1] == opponent && tem[l_place + 2][c_place + 2] == opponent && tem[l_place + 3][c_place + 3] == opponent)
			{
				column = c_place;
			}
		}
		else
		{
			column = rand() % 7;
			while (tem[0][column] == me || tem[0][column] == opponent)
			{
				column = rand() % 7;
			}
		}
	}
	//Write your AI here

	return column;
}
