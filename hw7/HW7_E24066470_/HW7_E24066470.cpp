#include<iostream>
using namespace std;

int main()
{
	int n, m ,xx ,yy ,x,y;
	int sum, max;

	max = sum = 0;

	cout << "please input two number to range the array you want:";
	cin >> n;
	cin >> m;

	int**array = new int*[n];
	array[0] = new int[n*m];

	for (int i = 0; i < n; i++)
	{
		array[i] = array[0] + i*m;
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "please input the sequence " << i << " of " << j << " you want:";
			cin >> array[i][j];
		}
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << array[i][j] ;
		}
		cout << endl;
	}

	cout << endl;

	for (int x2 = 1; x2 <= m; x2++)
	{
		for (int x1 = 0; x1 < x2; x1++)
		{
			for (int y2 = 1; y2 <= n; y2++)
			{
				for (int y1 = 0; y1 < y2; y1++)
				{
					sum = 0;
					for (int i = y1; i < y2; i++)
					{
						for (int j = x1; j < x2; j++)
						{
							sum += array[i][j];
							if (sum > max)
							{
								max = sum;
								x = x1;
								y = y1;
								xx = x2;
								yy = y2;
							}
						}
					}
				}
			}
		}
	}

	for (int i = x; i < xx; i++)
	{
		for (int j = y; j < yy; j++)
		{
			cout << i << j << " ";
		}
	}
	
	cout <<"\n\n"<< max;

	system("pause");
	return 0;
}