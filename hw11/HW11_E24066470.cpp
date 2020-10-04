#include <iostream>
#include <vector>
using namespace std;

bool isGameover(vector < vector<char> >, int, char); //Examine if this round ends
bool sbWin(vector < vector<char> >, char); //Examine if anyone wins at last move
bool isFull(vector < vector<char> >); //Examine if the board is full
bool legalMove(vector < vector<char> >, int); //Check if the last move is legal
vector < vector<char> > move(vector < vector<char> >, int, char); //Drop a new disc in the board
void output(vector < vector<char> >); //Show the board

int main()
{
	vector<vector<char>> chess_board(6, vector<char>(7, 0));
	vector<vector<char>> tem;//º»Æ…¿x¶schess_board
	char disc[2] = { 'o','x' };//player a=o,player b=x
	int input;
	int full_counter[7] = { 5,5,5,5,5,5,5 };

	cout << "\n   the initial chess board\n" << endl;
	output(chess_board);
	system("pause");
	system("cls");

	cout << "player 1 is \'o\' and player 2 is \'x\'\n" << endl;
	cout << "let's start with player 1 !!!" << endl;
	cout << "please input the line you want to input:" << endl;
	cin >> input;
	tem = chess_board;
	cout << endl;
	if (isGameover(tem, input, disc[1]))
	{
		return 0;
	}
	//tem[full_counter[input]][input] = 'o';
	//full_counter[input]--;
	tem = move(tem, input, disc[0]);
	output(tem);
		
	system("pause");
	system("cls");
	
	while (true)
	{
		cout << "player 1 is \'o\' and player 2 is \'x\'\n" << endl;
		cout << "it's player 2's time !!!" << endl;
		cout << "please input the line you want to input:" << endl;
		cin >> input;
		tem =tem;
		if (isGameover(tem,input,disc[1]))
		{
			break;
		}
		//tem[full_counter[input]][input] = 'x';
		//full_counter[input]--;
		tem = move(tem, input, disc[1]);
		output(tem); 

		system("pause");
		system("cls");

		cout << "player 1 is \'o\' and player 2 is \'x\'\n" << endl;
		cout << "it's player 1's time !!!" << endl;
		cout << "please input the line you want to input:" << endl;
		cin >> input;
		tem = tem;
		if (isGameover(tem, input, disc[0]))
		{
			break;
		}
		//tem[full_counter[input]][input] = 'o';
		//full_counter[input]--;
		tem = move(tem, input, disc[0]);
		output(tem);

		system("pause");
		system("cls");
	}

	//system("pause");
	//return 0;
}

void output(vector < vector<char> > b4) {
	cout << "    0  1  2  3  4  5  6" << endl;
	cout << "   =====================" << endl;
	for (int i = 0; i < 6; i++) {
		cout << "  " << i ;
		for (int j = 0; j < 7; j++) {
			cout << "["<< b4[i][j] << "]";
		}
		cout << endl;
	}
	cout << "   =====================" << endl;
}
bool isGameover(vector < vector<char> > bb, int c, char d) {
	int flag = 0;
	if (c < 0 || c>6) {
		cout << "The column must between 0 to 6" << endl;
		if (d == 'o') {
			cout << "Player2 wins!" << endl;
			//count_win2++;
			system("pause");
		}
		else {
			cout << "Player1 wins!" << endl;
			//count_win1++;
			system("pause");
		}
		return 1;
	}
	if (legalMove(bb, c)) {
		bb = move(bb, c, d);
		if (sbWin(bb, d)) {
			if (d == 'o') {
				output(bb);
				cout << "Player1 wins!" << endl;
				//count_win1++;
				system("pause");
			}
			else {
				output(bb);
				cout << "Player2 wins!" << endl;
				//count_win2++;
				system("pause");
			}
			return 1;
		}
		if (isFull(bb)) {
			return 1;
		}
		return 0;
	}
	else {
		if (d == 'o') {
			cout << "Player2 wins!" << endl;
			//count_win2++;
			system("pause");
		}
		else {
			cout << "Player1 wins!" << endl;
			//count_win1++;
			system("pause");
		}
		return 1;
	}
}
bool sbWin(vector < vector<char> > b1, char d1) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			if (j + 3 < 7) {
				if (b1[i][j] == d1 && b1[i][j + 1] == d1 && b1[i][j + 2] == d1 && b1[i][j + 3] == d1) {
					return 1;
				}
			}
			if (i + 3 < 6) {
				if (b1[i][j] == d1 && b1[i + 1][j] == d1 && b1[i + 2][j] == d1 && b1[i + 3][j] == d1) {
					return 1;
				}
			}
			if ((j + 3 < 7) && (i + 3 < 6)) {
				if (b1[i][j] == d1 && b1[i + 1][j + 1] == d1 && b1[i + 2][j + 2] == d1 && b1[i + 3][j + 3] == d1) {
					return 1;
				}
			}
			if ((j - 3 >= 0) && (i + 3 < 6)) {
				if (b1[i][j] == d1 && b1[i + 1][j - 1] == d1 && b1[i + 2][j - 2] == d1 && b1[i + 3][j - 3] == d1) {
					return 1;
				}
			}
		}
	}
	return 0;
}
bool isFull(vector < vector<char> > b2) {
	int count_empty = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			if (b2[i][j] == '\0') {
				return 0;
			}
			else {
				count_empty++;
			}
		}
	}
	if (count_empty == 42) {
		cout << "Draw Game!" << endl;
		//count_draw++;
		system("pause");
		return 1;
	}
	return 0;
}
bool legalMove(vector < vector<char> > o, int c1) {
	if (o[0][c1] == '\0') {
		return 1;
	}
	else {
		cout << "This column is full" << endl;
		system("pause");
		return 0;
	}
}
vector < vector<char> > move(vector < vector<char> > b3, int c2, char d2) {
	int flag = 0;
	for (int i = 0; i < 5; i++) {
		if (b3[i][c2] == '\0'&&b3[i + 1][c2] != '\0') {
			b3[i][c2] = d2;
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		b3[5][c2] = d2;
	}
	return b3;
}