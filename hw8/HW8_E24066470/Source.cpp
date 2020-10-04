#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int initial_array[7][7] = { 0 };
	int input_x, input_y;
	int bigger, smaller;
	int dwarf_place[7][7] = { 0 };
	int equal_0[7] = { 0 };
	int dwarf_counter;
	dwarf_counter = 0;

	srand(time(NULL));

	cout << "please input the coordinate x and y you want to put the first dwarf" << endl;

	cout << "x = ";
	cin >> input_x;
	cout << "y = ";
	cin >> input_y;

	while (input_x > 7 || input_y > 7)
	{
		cout << "please input the numbers smaller than 8 ！！！" << endl;
		cin >> input_x >> input_y;
	}
	
	again:
	input_x = input_x;
	input_y = input_y;

	dwarf_counter = 0;//歸零

	for (int i = 0; i < 7; i++)//歸零
	{
		for (int j = 0; j < 7; j++)
		{
			initial_array[i][j] = 0;
			dwarf_place[i][j] = 0;
		}
	}

	for (int i = 0; i < 7; i++)//使input_x行為負一
	{
		if (input_x == 0 && input_y != 0)
		{
			initial_array[i][input_x] = -1;
			initial_array[input_y - 1][i] = -1;
		}
		else if (input_y == 0 && input_x != 0)
		{
			initial_array[i][input_x - 1] = -1;
			initial_array[input_y][i] = -1;
		}
		else if (input_y == 0 && input_x == 0)
		{
			initial_array[i][input_x] = -1;
			initial_array[input_y][i] = -1;
		}
		else
		{
			initial_array[i][input_x - 1] = -1;
			initial_array[input_y - 1][i] = -1;
		}
	}

	if (input_x > input_y && input_y != 0)
	{
		bigger = input_x;
		smaller = input_y;
	}
	else if (input_x < input_y && input_x != 0)
	{
		bigger = input_y;
		smaller = input_x;
	}
	else if (input_x == 0)
	{
		bigger = smaller = input_y;
	}
	else if (input_y == 0)
	{
		bigger = smaller = input_x;
	}
	else if (input_x == input_y)
	{
		bigger = smaller = input_x;
	}

	while (input_x != 0)
	{
		if (input_y == 0)//使左斜上與斜下為負一
		{
			for (int i = 0; i < smaller; i++)
			{
				initial_array[input_y + i][(input_x - 1) - i] = -1;
			}
		}
		else
		{
			for (int i = 0; i < smaller; i++)
			{
				initial_array[(input_y - 1) - i][(input_x - 1) - i] = -1;
				initial_array[(input_y - 1) + i][(input_x - 1) - i] = -1;
			}
		}
		break;
	}

	if (input_y == 0 && input_x!=0)//使右斜上與斜下為負一
	{
		dwarf_place[input_x - 1][input_y] = 2;
		for (int i = 0; i <= (7 - smaller); i++)
		{
			initial_array[input_y + i][(input_x - 1) + i] = -1;
		}
	}
	else if (input_x == 0 && input_y!=0)
	{
		dwarf_place[input_x][input_y - 1] = 2;
		for (int i = 0; i <= bigger; i++)
		{
			initial_array[(input_y - 1) + i][input_x + i] = -1;
			initial_array[(input_y - 1) - i][input_x + i] = -1;
		}
	}
	else if (input_x == 0 && input_y == 0)
	{
		dwarf_place[input_x][input_y] = 2;
		for (int i = 0; i < 7; i++)
		{
			initial_array[input_y + i][input_x + i] = -1;
		}
	}
	else
	{
		for (int i = 0; i <= (7 - bigger); i++)
		{
			initial_array[((input_y - 1) - i)][(input_x - 1) + i] = -1;
			initial_array[((input_y - 1) + i)][(input_x - 1) + i] = -1;
		}
	}

	/*for (int i = 0; i < 7; i++)//印出7*7陣列檢查
	{
		for (int j = 0; j < 7; j++)
		{
			cout << initial_array[i][j];
			cout << "   ";
		}
		cout << endl;
	}*/

	if (input_y == 0 && input_x != 0)
	{
		dwarf_place[input_y][input_x - 1] = 2;
	}
	else if (input_x == 0 && input_y != 0)
	{
		dwarf_place[input_y -1][input_x] = 2;
	}
	else if (input_x == 0 && input_y == 0)
	{
		dwarf_place[input_y][input_x] = 2;
	}
	else if (input_x != 0 && input_y != 0)
	{
		dwarf_place[input_y-1][input_x-1] = 2;
	}
	
	//dwarf_place[input_x - 1][input_y - 1] = 2;

	for (int n = 0; n < 7; n++)
	{
		if (n == (input_y - 1) || (n==input_y && input_y==0))
			continue;
		else if (initial_array[n][0] == -1 && initial_array[n][1] == -1 && initial_array[n][2] == -1 && initial_array[n][3] == -1 && initial_array[n][4] == -1 && initial_array[n][5] == -1 && initial_array[n][6] == -1)
			goto again;

		int m;
		m = rand() % 7;
			
		while (initial_array[n][m] == -1)
		{
			m = rand() % 7;
		}
				
		if (initial_array[n][m] == 0)
		{
			dwarf_place[n][m] = initial_array[n][m] = 2;
			if(dwarf_place[n][m]==2)
				dwarf_counter++;
			equal_0[n] = m;

			for (int i = 0; i < 7; i++)//使input_x行，Y列為負一
			{
				if (m == 0 && n != 0)
				{
					initial_array[i][m] = -1;
					initial_array[n][i] = -1;
				}
				else if (n == 0 && m != 0)
				{
					initial_array[i][m] = -1;
					initial_array[n][i] = -1;
				}
				else if (n == 0 && m == 0)
				{
					initial_array[i][m] = -1;
					initial_array[n][i] = -1;
				}
				else
				{
					initial_array[i][m] = -1;
					initial_array[n][i] = -1;
				}
			}

			if (m > n && n != 0)
			{
				bigger = m + 1;
				smaller = n + 1;
			}
			else if (m < n && m != 0)
			{
				bigger = n + 1;
				smaller = m + 1;
			}
			else if (m == 0)
			{
				bigger = smaller = n + 1;
			}
			else if (n == 0)
			{
				bigger = smaller = m + 1;
			}
			else if (m == n)
			{
				bigger = smaller = m + 1;
			}

			while (m != 0)
			{
				if (n == 0)//使左斜上與斜下為負一
				{
					for (int i = 0; i < smaller; i++)
					{
						initial_array[n + i][m - i] = -1;
					}
				}
				else
				{
					for (int i = 0; i < smaller; i++)
					{
						initial_array[n - i][m - i] = -1;
						initial_array[n + i][m - i] = -1;
					}
				}
				break;
			}

			if (n == 0)//使右斜上與斜下為負一
			{
				for (int i = 0; i <= (7 - smaller); i++)
				{
					initial_array[n + i][m + i] = -1;
				}
			}
			else if (m == 0)
			{
				for (int i = 0; i < 7; i++)
				{
					initial_array[n + i][m + i] = -1;
					initial_array[n - i][m + i] = -1;
				}
			}
			else if (input_x == 0 && input_y == 0)
			{
				for (int i = 0; i < 7; i++)
				{
					initial_array[input_y + i][input_x + i] = -1;
				}
			}
			else
			{
				for (int i = 0; i <= (7 - bigger); i++)
				{
					initial_array[(n - i)][m + i] = -1;
					initial_array[(n + i)][m + i] = -1;
				}
			}
		}
	}

	/*for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (dwarf_place[i][j] == 2)
				cout << i+1 << " " << j+1 << endl;
		}
	}*/

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (dwarf_place[i][j] == 2)
				cout << j+1 << endl;
		}
	}
	

	system("pause");
	return 0;
}