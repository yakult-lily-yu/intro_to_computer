#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	int players_number, disk, i, j, n, m, k;
	int p, d1, d2, d3, d4 , insert;
	int	in_player[4][9] = { 0 },disk_number[4][3] = { 0 };
	int color[9] = { 9,9,9,9,9,9,9,3,10},pick_card,grade[4];
	char letter, player[4] = {'a','b','c','d'};
	bool nsuccess;
	bool distake[4] ;
	bool exist_ai[4];

	n = m = i = j = k = p = d1 = d2 = d3 = d4 = 0;
	srand(time(NULL));

	cout << "welcome to CHAMELEON\n" << endl;
	cout << "afetr taking all the disks , REMEMBER to input the disk number you want to move to STRAIGHTLY !!!!!!!!!"<<endl;
	cout << "if you want to know the rules,please input R" << endl;
	cout << "if you want to start the game,please input S\n" << endl;
	
	
	cin >> letter;
	switch (letter)
	{
	case'S':
	case's':
		while (n == m || n == i || n == j || m == i || m == j || i == j) /*初始每人隨機分配不同顏色的牌*/
		{
			n = rand() % 7;
			m = rand() % 7;
			i = rand() % 7;
			j = rand() % 7;
		}
		in_player[0][n] = 1;
		in_player[1][m] = 1;
		in_player[2][i] = 1;
		in_player[3][j] = 1;

		cout << " disk 1:" << endl;/*版面*/
		cout << " disk 2:" << endl;
		cout << " disk 3:" << endl;
		cout << " disk 4:\n" << endl;
		
		for (int j = 0; j < 4; j++)
		{
			cout << " player "<<player[j]<<":" << endl;
			cout << " color1  color2  color3  color4  color5  color6  color7  colorful  +2" << endl;
			for (int i = 0; i < 9; i++) 
			{
				cout << "   " << in_player[j][i] << "    ";
			}
			cout << "\n"<<endl;
		}
		cout << "\n" << endl;
		cout << "you are the player d~" << endl;
        break;
	case'R':
	case'r':
		cout << "input P when you want to pick cards" << endl;
		cout << "after input P , please input the disk number you want to put\n" << endl;
		cout << "input T when you want to take disk" << endl;
		cout << "after input T , please input the disk number you want to take\n" << endl;
		cout << "after taking all the disks , remember to input the disk number you want to move to straightly" << endl;
		break;
	default:
		cout << "please input S or R !!!" << endl;
		cin >> letter;
	}

	cout << n << m << i << j<<endl;

	color[m] = 8;
	color[n] = 8;
	color[i] = 8;
	color[j] = 8;/*將初始有用到的顏色減掉*/


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			disk_number[i][j] = 0;
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		exist_ai[i] = false;
	}

	while (color[0] + color[1] + color[2] + color[3] + color[4] + color[5] + color[6] + color[7] + color[8] > 15)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				disk_number[j][i] = 0;
			}
		}
		d1 = 0;
		d2 = 0;
		d3 = 0;
		d4 = 0;

		if (k != 0)
			k = k - 1;

		cout << "let's start with player " << player[k] << " !" << endl;

		if (exist_ai[k]==false)
		{
			if (disk_number[0][2] == 0 || disk_number[1][2] == 0 || disk_number[2][2] == 0 || disk_number[3][2] == 0)
			{
				pick_card = rand() % 9;

				while (color[pick_card] == 0)
				{
					pick_card = rand() % 9;
				}

				int flag = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						if (disk_number[i][j] == 0)
						{
							disk_number[i][j] = pick_card+1;
							if (pick_card != 7 && pick_card != 8)
							{
								cout << "get color " << pick_card + 1 << "\n" << endl;
								color[pick_card]--;
							}
							else if (pick_card == 7)
							{
								cout << "get colorful\n" << endl;
								color[pick_card]--;
							}
							else if (pick_card == 8)
							{
								cout << "get +2\n" << endl;
								color[pick_card]--;
							}
							flag = 1;
							break;
						}
					}
					if (flag == 1)
						break;
				}
			}
			
			for (int i = 0; i < 4; i++)
			{
				cout << "\n disk " << i + 1 << ":";
				for (int j = 0; j < 3; j++)
				{
					cout << disk_number[i][j] << "  ";
				}
			}
			cout << "\n" << endl;

			for (int j = 0; j < 4; j++)
			{
				cout << " player " << player[j] << ":" << endl;
				cout << " color1  color2  color3  color4  color5  color6  color7  colorful  +2" << endl;
				for (int i = 0; i < 9; i++)
				{
					cout << "   " << in_player[j][i] << "    ";
				}
				cout << "\n" << endl;
			}
			cout << "\n" << endl;
		}
		else
		{
			pick_card = rand() % 9;/*從牌推中抽出一張牌*/
			if (pick_card != 7 && pick_card != 8)
			{
				cout << "get color " << pick_card + 1 << "\n" << endl;
				color[pick_card]--;
			}
			else if (pick_card == 7)
			{
				cout << "get colorful\n" << endl;
				color[pick_card]--;
			}
			else if (pick_card == 8)
			{
				cout << "get +2\n" << endl;
				color[pick_card]--;
			}

			cout << "please input the disk you want to move to:";/*將牌移到想要的塔*/
			cin >> disk;

			while (disk != 1 && disk != 2 && disk != 3 && disk != 4)
			{
				cout << "please input 1 or 2 or 3 or 4 !!!" << endl;
				cin >> disk;
			}
			if (disk == 1)
			{
				disk_number[0][d1] = pick_card + 1;
				d1++;
			}
			else if (disk == 2)
			{
				disk_number[1][d2] = pick_card + 1;
				d2++;
			}
			else if (disk == 3)
			{
				disk_number[2][d3] = pick_card + 1;
				d3++;
			}
			else if (disk == 4)
			{
				disk_number[3][d4] = pick_card + 1;
				d4++;
			}

			i = j = n = 0;/*顯示移動後牌堆*/
			for (int i = 0; i < 4; i++)
			{
				cout << "\n disk " << i + 1 << ":";
				for (int j = 0; j < 3; j++)
				{
					cout << disk_number[i][j] << "  ";
				}
			}
			cout << "\n" << endl;

			for (int j = 0; j < 4; j++)
			{
				cout << " player " << player[j] << ":" << endl;
				cout << " color1  color2  color3  color4  color5  color6  color7  colorful  +2" << endl;
				for (int i = 0; i < 9; i++)
				{
					cout << "   " << in_player[j][i] << "    ";
				}
				cout << "\n" << endl;
			}
			cout << "\n" << endl;
		}
		if (color[0] + color[1] + color[2] + color[3] + color[4] + color[5] + color[6] + color[7] + color[8] <= 15)
			break;

		k = k + 1;

		for (int i = 0; i<4; i++) distake[i] = true;

		while (disk_number[0][2] != 'e' || disk_number[1][2] != 'e' || disk_number[2][2] != 'e' || disk_number[3][2] != 'e')
		{
			/*for (int i = 0; i < 9; i++)
			{
				cout << color[i] << " ";
			}*/

			if (distake[k])
			{
				cout << "it's player " << player[k] << "'s turn\n" << endl;

				for (int i = 0; i < 3; i++)exist_ai[i] = false;

				if (exist_ai[k] == false)
				{
					if (disk_number[0][2] == 0 || disk_number[1][2] == 0 || disk_number[2][2] == 0 || disk_number[3][2] == 0)
					{
						pick_card = rand() % 9;

						while (color[pick_card] == 0)
						{
							pick_card = rand() % 9;
						}

						int flag = 0;
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								if (disk_number[i][j] == 0)
								{
									disk_number[i][j] = pick_card + 1;
									if (pick_card != 7 && pick_card != 8)
									{
										cout << "get color " << pick_card + 1 << "\n" << endl;
										color[pick_card]--;
									}
									else if (pick_card == 7)
									{
										cout << "get colorful\n" << endl;
										color[pick_card]--;
									}
									else if (pick_card == 8)
									{
										cout << "get +2\n" << endl;
										color[pick_card]--;
									}
									flag = 1;
									break;
								}
							}
							if (flag == 1)
								break;
						}
					}
					else
					{
						for (int i = 0; i < 4; i++)
						{
							if (disk_number[i][2] != 'e')
							{
								for (int j = 0; j < 3; j++)
								{
									in_player[k][disk_number[i][j]-1]++;
									disk_number[i][j] = 'e';
								}
								break;
							}
						}
						distake[k] = false;
					}

					for (int i = 0; i < 4; i++)
					{
						cout << "\n disk " << i + 1 << ":";
						for (int j = 0; j < 3; j++)
						{
							cout << disk_number[i][j] << "  ";
						}
					}
					cout << "\n" << endl;

					for (int j = 0; j < 4; j++)
					{
						cout << " player " << player[j] << ":" << endl;
						cout << " color1  color2  color3  color4  color5  color6  color7  colorful  +2" << endl;
						for (int i = 0; i < 9; i++)
						{
							cout << "   " << in_player[j][i] << "    ";
						}
						cout << "\n" << endl;
					}
					cout << "\n" << endl;
				}
				else
				{
					cout << "please input P to pick out a sheet of chameleom card's" << endl;
					cout << "please input T to take one of disks" << endl;

					cin >> letter;

					while (letter != 't' && letter != 'T' && letter != 'p' && letter != 'P')
					{
						cout << "please input T or P !!1" << endl;
						cin >> letter;
					}
					nsuccess = true;
					while (nsuccess)
					{
						int remaining = 0;
						int empty = 0;
						int re_empty = 0;
						for (int i = 0; i < 4; i++)
						{
							if (disk_number[i][2] != 'e')
							{
								remaining++;
								if (disk_number[i][0] == 0)
								{
									re_empty++;
								}
							}
						}
						if (remaining == re_empty)
						{
							cout << "you can not choose T while there is nothing in the disks !!!\n" << endl;
							letter = 'p';
							nsuccess = false;

						}
						else if ((letter == 'p' || letter == 'P') && (disk_number[0][2] != 0 && disk_number[1][2] != 0 && disk_number[2][2] != 0 && disk_number[3][2] != 0))
						{
							cout << "you can not pick the cards when the disks are empty or full" << endl;
							letter = 't';
							nsuccess = false;
						}
						else
						{
							nsuccess = false;
						}
					}
					if (letter == 't' || letter == 'T')
					{

						cout << "please input the disk you want to take:";
						cin >> disk;

						while ((disk != 1 && disk != 2 && disk != 3 && disk != 4) || (disk_number[disk - 1][0] == 0 && disk_number[disk - 1][1] == 0 && disk_number[disk - 1][2] == 0) || disk_number[disk - 1][2] == 'e')
						{
							if (disk != 1 && disk != 2 && disk != 3 && disk != 4)
							{
								cout << "please input 1 or 2 or 3 !!!" << endl;
								cin >> disk;
							}
							else if (disk_number[disk - 1][0] == 0 && disk_number[disk - 1][1] == 0 && disk_number[disk - 1][2] == 0)
							{
								cout << "sorry,you can not take this one !" << endl;
								cout << "please input another disk number:";
								cin >> disk;
							}
							else if (disk_number[disk - 1][2] == 'e')
							{
								cout << "sorry,you can not take this one !" << endl;
								cout << "please input another disk number:";
								cin >> disk;
							}
						}

						for (int i = 0; i < 3; i++)
						{
							in_player[k][disk_number[disk - 1][i] - 1]++;
							disk_number[disk-1][i] = 'e';
						}

						for (int i = 0; i < 4; i++)
						{
							cout << "\n disk " << i + 1 << ":";
							for (int j = 0; j < 3; j++)
							{
								cout << disk_number[i][j] << "  ";
							}
						}
						cout << "\n" << endl;

						for (int j = 0; j < 4; j++)
						{
							cout << " player " << player[j] << ":" << endl;
							cout << " color1  color2  color3  color4  color5  color6  color7  colorful  +2" << endl;
							for (int i = 0; i < 9; i++)
							{
								cout << "   " << in_player[j][i] << "    ";
							}
							cout << "\n" << endl;
						}
						cout << "\n" << endl;

						distake[k] = false;
					}
					else if (letter == 'P' || letter == 'p')
					{
						pick_card = rand() % 9;
						while (color[pick_card] == 0)
						{
							pick_card = rand() % 9;
						}

						if (pick_card != 7 && pick_card != 8)
						{
							cout << "get color " << pick_card + 1 << "\n" << endl;
							color[pick_card]--;
						}
						else if (pick_card == 7)
						{
							cout << "get colorful\n" << endl;
							color[pick_card]--;
						}
						else if (pick_card == 8)
						{
							cout << "get +2\n" << endl;
							color[pick_card]--;
						}

						cout << "please input the disk you want to move to:" << endl;
						cin >> disk;

						while ((disk != 1 && disk != 2 && disk != 3 && disk != 4) || (disk_number[0][d1] == 'e'&&disk == 1) || (disk_number[1][d2] == 'e' && disk == 2) || (disk_number[2][d3] == 'e'&&disk == 3) || (disk_number[3][d4] == 'e'&&disk == 4) || disk_number[disk - 1][2] != 0)
						{
							if (disk != 1 && disk != 2 && disk != 3 && disk != 4)
							{
								cout << "please input 1 or 2 or 3 or 4!!!" << endl;
								cin >> disk;
							}
							else if ((disk_number[0][d1] == 'e'&&disk == 1) || (disk_number[1][d2] == 'e' && disk == 2) || (disk_number[2][d3] == 'e'&&disk == 3) || (disk_number[3][d4] == 'e'&&disk == 4))
							{
								cout << "the disk has been took !!!" << endl;
								cout << "please input another disks number:" << endl;
								cin >> disk;
							}
							else if (disk_number[disk - 1][2] != 0)
							{
								cout << "the disk is full now !!!" << endl;
								cout << "please input another disks number:" << endl;
								cin >> disk;
							}
						}

						if (disk == 1)
						{
							disk_number[0][d1] = pick_card + 1;
							d1++;
						}
						else if (disk == 2)
						{
							disk_number[1][d2] = pick_card + 1;
							d2++;
						}
						else if (disk == 3)
						{
							disk_number[2][d3] = pick_card + 1;
							d3++;
						}
						else if (disk == 4)
						{
							disk_number[3][d4] = pick_card + 1;
							d4++;
						}

						for (int j = 0; j < 4; j++)
						{
							cout << "\n disk " << j + 1 << ":";
							for (int i = 0; i < 3; i++)
							{
								cout << disk_number[j][i] << "  ";
							}
						}

						cout << "\n" << endl;

						for (int j = 0; j < 4; j++)
						{
							cout << " player " << player[j] << ":" << endl;
							cout << " color1  color2  color3  color4  color5  color6  color7  colorful  +2" << endl;
							for (int i = 0; i < 9; i++)
							{
								cout << "   " << in_player[j][i] << "    ";
							}
							cout << "\n" << endl;
						}
						cout << "\n" << endl;
					}
				}
				if (color[0] + color[1] + color[2] + color[3] + color[4] + color[5] + color[6] + color[7] + color[8] <= 15)
					break;
			}
			k++;
			if (k > 3)
				k = 0;
		}
	}

	cout << "#########################" << endl;
	cout << "you get the ending card ~" << endl;
	cout << "after picking out most to " << 12 - d1 - d2 - d3 << " cards,the game will end\n" << endl;
	
	for (int i = 0; i < 3; i++)exist_ai[i] = false;

	if (exist_ai[k] == false)
	{
		if (disk_number[0][2] == 0 || disk_number[1][2] == 0 || disk_number[2][2] == 0 || disk_number[3][2] == 0)
		{
			pick_card = rand() % 9;

			while (color[pick_card] == 0)
			{
				pick_card = rand() % 9;
			}

			int flag = 0;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (disk_number[i][j] == 0)
					{
						disk_number[i][j] = pick_card + 1;
						if (pick_card != 7 && pick_card != 8)
						{
							cout << "get color " << pick_card + 1 << "\n" << endl;
							color[pick_card]--;
						}
						else if (pick_card == 7)
						{
							cout << "get colorful\n" << endl;
							color[pick_card]--;
						}
						else if (pick_card == 8)
						{
							cout << "get +2\n" << endl;
							color[pick_card]--;
						}
						flag = 1;
						break;
					}
				}
				if (flag == 1)
					break;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			cout << "\n disk " << i + 1 << ":";
			for (int j = 0; j < 3; j++)
			{
				cout << disk_number[i][j] << "  ";
			}
		}
		cout << "\n" << endl;

		for (int j = 0; j < 4; j++)
		{
			cout << " player " << player[j] << ":" << endl;
			cout << " color1  color2  color3  color4  color5  color6  color7  colorful  +2" << endl;
			for (int i = 0; i < 9; i++)
			{
				cout << "   " << in_player[j][i] << "    ";
			}
			cout << "\n" << endl;
		}
		cout << "\n" << endl;

		distake[k] = false;
	}
	else
	{
		pick_card = rand() % 9;/*從牌推中抽出一張牌*/
		while (color[pick_card] == 0)
		{
			pick_card = rand() % 9;
		}
		if (pick_card != 7 && pick_card != 8)
		{
			cout << "get color " << pick_card + 1 << "\n" << endl;
			color[pick_card]--;
		}
		else if (pick_card == 7)
		{
			cout << "get colorful\n" << endl;
			color[pick_card]--;
		}
		else if (pick_card == 8)
		{
			cout << "get +2\n" << endl;
			color[pick_card]--;
		}

		cout << "please input the disk you want to move to:";/*將牌移到想要的塔*/
		cin >> disk;

		while (disk != 1 && disk != 2 && disk != 3 && disk != 4)
		{
			cout << "please input 1 or 2 or 3 or 4 !!!" << endl;
			cin >> disk;
		}
		if (disk == 1)
		{
			disk_number[0][d1] = pick_card + 1;
			d1++;
		}
		else if (disk == 2)
		{
			disk_number[1][d2] = pick_card + 1;
			d2++;
		}
		else if (disk == 3)
		{
			disk_number[2][d3] = pick_card + 1;
			d3++;
		}
		else if (disk == 4)
		{
			disk_number[3][d4] = pick_card + 1;
			d4++;
		}

		i = j = n = 0;/*顯示移動後牌堆*/
		for (int i = 0; i < 4; i++)
		{
			cout << "\n disk " << i + 1 << ":";
			for (int j = 0; j < 3; j++)
			{
				cout << disk_number[i][j] << "  ";
			}
		}

		cout << "\n" << endl;

		for (int j = 0; j < 4; j++)
		{
			cout << " player " << player[j] << ":" << endl;
			cout << " color1  color2  color3  color4  color5  color6  color7  colorful  +2" << endl;
			for (int i = 0; i < 9; i++)
			{
				cout << "   " << in_player[j][i] << "    ";
			}
			cout << "\n" << endl;
		}
		cout << "\n" << endl;
	}

	if (disk_number[3][2] == 'e')
	{
		for (int i = 0; i<3; i++) distake[i] = true;
	}
	else
	{
		for (int i = 0; i < 4; i++) distake[i] = true;
	}

	k = k + 1;

	goto ending;

	while ((disk_number[0][0] != 'e' && disk_number[0][1] != 'e'&& disk_number[0][2] != 'e') && (disk_number[1][0] != 'e'&& disk_number[1][1] != 'e'
		&&disk_number[1][2] != 'e') && (disk_number[2][0] != 'e'&&disk_number[2][1] != 'e'&&disk_number[2][2] != 'e') && (disk_number[3][0] != 'e'&&disk_number[3][1] != 'e'&&disk_number[3][2] != 'e'))
	{
		ending:
		while ((disk_number[0][0] != 'e' && disk_number[0][1] != 'e'&& disk_number[0][2] != 'e') || (disk_number[1][0] != 'e'&& disk_number[1][1] != 'e'&&disk_number[1][2] != 'e') || (disk_number[2][0] != 'e'&&disk_number[2][1] != 'e'&&disk_number[2][2] != 'e') || (disk_number[3][0] != 'e'&&disk_number[3][1] != 'e'&&disk_number[3][2] != 'e'))
		{
			for (i = 0; i < 3; i++)exist_ai[i] = false;

			cout << "it's player " << player[k] << "'s turn\n" << endl;

			if (distake[k])
			{
				if (exist_ai[k] == false)
				{
					if (disk_number[0][2] == 0 || disk_number[1][2] == 0 || disk_number[2][2] == 0 || disk_number[3][2] == 0)
					{
						pick_card = rand() % 9;

						while (color[pick_card] == 0)
						{
							pick_card = rand() % 9;
						}

						int flag = 0;
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								if (disk_number[i][j] == 0)
								{
									disk_number[i][j] = pick_card + 1;
									if (pick_card != 7 && pick_card != 8)
									{
										cout << "get color " << pick_card + 1 << "\n" << endl;
										color[pick_card]--;
									}
									else if (pick_card == 7)
									{
										cout << "get colorful\n" << endl;
										color[pick_card]--;
									}
									else if (pick_card == 8)
									{
										cout << "get +2\n" << endl;
										color[pick_card]--;
									}
									flag = 1;
									break;
								}
							}
							if (flag == 1)
								break;
						}
					}
					else
					{
						for (int i = 0; i < 4; i++)
						{
							if (disk_number[i][2] != 'e')
							{
								for (int j = 0; j < 3; j++)
								{
									in_player[k][disk_number[i][j]-1]++;
									disk_number[i][j] = 'e';
								}
								break;
							}
						}
						distake[k] = false;
					}

					for (int i = 0; i < 4; i++)
					{
						cout << "\n disk " << i + 1 << ":";
						for (int j = 0; j < 3; j++)
						{
							cout << disk_number[i][j] << "  ";
						}
					}
					cout << "\n" << endl;

					for (int j = 0; j < 4; j++)
					{
						cout << " player " << player[j] << ":" << endl;
						cout << " color1  color2  color3  color4  color5  color6  color7  colorful  +2" << endl;
						for (int i = 0; i < 9; i++)
						{
							cout << "   " << in_player[j][i] << "    ";
						}
						cout << "\n" << endl;
					}
					cout << "\n" << endl;
				}
				else
				{
					cout << "please input P to pick out a sheet of chameleom card's" << endl;
					cout << "please input T to take one of disks" << endl;

					cin >> letter;

					while (letter != 't' && letter != 'T' && letter != 'p' && letter != 'P')
					{
						cout << "please input T or P !!1" << endl;
						cin >> letter;
					}
					nsuccess = true;
					while (nsuccess)
					{
						int remaining = 0;
						int empty = 0;
						int re_empty = 0;
						for (int i = 0; i < 4; i++)
						{
							if (disk_number[i][2] != 'e')
							{
								remaining++;
								if (disk_number[i][0] == 0)
								{
									re_empty++;
								}
							}
						}
						if (remaining == re_empty)
						{
							cout << "you can not choose T while there is nothing in the disks !!!\n" << endl;
							letter = 'p';
							nsuccess = false;

						}
						else if ((letter == 'p' || letter == 'P') && (disk_number[0][2] != 0 && disk_number[1][2] != 0 && disk_number[2][2] != 0 && disk_number[3][2] != 0))
						{
							cout << "you can not pick the cards when the disks are empty or full" << endl;
							letter = 't';
							nsuccess = false;
						}
						else
						{
							nsuccess = false;
						}
					}
					if (letter == 't' || letter == 'T')
					{
						cout << "please input the disk you want to take:";
						cin >> disk;

						while ((disk != 1 && disk != 2 && disk != 3 && disk != 4) || (disk_number[disk - 1][0] == 0 && disk_number[disk - 1][1] == 0 && disk_number[disk - 1][2] == 0))
						{
							if (disk != 1 && disk != 2 && disk != 3 && disk != 4)
							{
								cout << "please input 1 or 2 or 3 !!!" << endl;
								cin >> disk;
							}
							else if (disk_number[disk - 1][0] == 0 && disk_number[disk - 1][1] == 0 && disk_number[disk - 1][2] == 0)
							{
								cout << "sorry,you can not take this one !" << endl;
								cout << "please input another disk number:";
								cin >> disk;
							}
						}

						for (int i = 0; i < 3; i++)
						{
							in_player[k][disk_number[disk - 1][i] - 1]++;
							disk_number[disk - 1][i] = 'e';
						}

						for (int i = 0; i < 4; i++)
						{
							cout << "\n disk " << i + 1 << ":";
							for (int j = 0; j < 3; j++)
							{
								cout << disk_number[i][j] << "  ";
							}
						}

						cout << "\n" << endl;

						for (int j = 0; j < 4; j++)
						{
							cout << " player " << player[j] << ":" << endl;
							cout << " color1  color2  color3  color4  color5  color6  color7  colorful  +2" << endl;
							for (int i = 0; i < 9; i++)
							{
								cout << "   " << in_player[j][i] << "    ";
							}
							cout << "\n" << endl;
						}
						cout << "\n" << endl;

						distake[k] = false;
					}
					else if (letter == 'P' || letter == 'p')
					{
						pick_card = rand() % 9;

						while (color[pick_card] == 0)
						{
							pick_card = rand() % 9;
						}

						if (pick_card != 7 && pick_card != 8)
						{
							cout << "get color " << pick_card + 1 << "\n" << endl;
							color[pick_card]--;
						}
						else if (pick_card == 7)
						{
							cout << "get colorful\n" << endl;
							color[pick_card]--;
						}
						else if (pick_card == 8)
						{
							cout << "get +2\n" << endl;
							color[pick_card]--;
						}

						cout << "please input the disk you want to move to:" << endl;
						cin >> disk;

						while (disk != 1 && disk != 2 && disk != 3 && disk != 4)
						{
							cout << "please input 1 or 2 or 3 or 4!!!" << endl;
							cin >> disk;
						}
						while ((disk_number[0][d1] == 'e'&&disk == 1) || (disk_number[1][d2] == 'e' && disk == 2) || (disk_number[2][d3] == 'e'&&disk == 3) || (disk_number[3][d4] == 'e'&&disk == 4))
						{
							cout << "the disk has been took !!!" << endl;
							cout << "please input other disks number:" << endl;
							cin >> disk;
						}
						if (disk == 1)
						{
							disk_number[0][d1] = pick_card + 1;
							d1++;
						}
						else if (disk == 2)
						{
							disk_number[1][d2] = pick_card + 1;
							d2++;
						}
						else if (disk == 3)
						{
							disk_number[2][d3] = pick_card + 1;
							d3++;
						}
						else if (disk == 4)
						{
							disk_number[3][d4] = pick_card + 1;
							d4++;
						}

						for (int j = 0; j < 4; j++)
						{
							cout << "\n disk " << j + 1 << ":";
							for (int i = 0; i < 3; i++)
							{
								cout << disk_number[j][i] << "  ";
							}
						}

						cout << "\n" << endl;

						for (int j = 0; j < 4; j++)
						{
							cout << " player " << player[j] << ":" << endl;
							cout << " color1  color2  color3  color4  color5  color6  color7  colorful  +2" << endl;
							for (int i = 0; i < 9; i++)
							{
								cout << "   " << in_player[j][i] << "    ";
							}
							cout << "\n" << endl;
						}
						cout << "\n" << endl;
					}
				}
			}
			k = k + 1;

			if (k > 3)
				k = 0;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			insert = in_player[i][j];
			int next = j;
			while ((next > 0) && (in_player[i][next - 1]< insert))
			{
				in_player[i][next] = in_player[i][next - 1];
				next--;
			}
			in_player[i][next] = insert;
			//cout << in_player[i][next]<<" ";
		}
		for (int j = 0; j < 7; j++) cout << in_player[i][j];
		cout << endl;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (in_player[i][j] >= 6)in_player[i][j] = 6;
			while (in_player[i][j]<6 && ( j == 0 || j == 1 || j == 2 )&&(in_player[i][7]>0))
			{
				in_player[i][j]++;
				in_player[i][7]--;
			}
		}
		grade[i] = ((in_player[i][0] + 1)*in_player[i][0]) / 2 + ((in_player[i][1] + 1)*in_player[i][1]) / 2 + ((in_player[i][2] + 1)*in_player[i][2]) / 2 - ((in_player[i][3] + 1)*in_player[i][3]) / 2 - ((in_player[i][4] + 1)*in_player[i][4]) / 2 - ((in_player[i][5] + 1)*in_player[i][5]) / 2- ((in_player[i][6] + 1)*in_player[i][6]) / 2;
		grade[i] = grade[i] + in_player[i][8] * 2;

		cout << "player " << player[i] << "'s grade is " << grade[i] << endl;
	}

	system("pause");
	return 0;
}