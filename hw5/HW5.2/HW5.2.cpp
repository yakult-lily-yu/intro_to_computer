#include<iostream>

using namespace std;
void move_statement(char from,char to);

int main()
{
	int i,m,n,input;
	int disk[11];
	char from,to;

	cout << "TOWER OF HONOI !!!\n" << endl;/*初始遊戲畫面*/
	cout << "please input the number of disks you want:";
	cin >> input;
	cout << "\n" << "[A]:";
	for (i = input; i > 0; i--) {
		disk[i] = i;
		cout << disk[i];
	}
	cout << "\n[B]:\n[C]:\n" << endl;

	cout << "from:";
	while (cin >> from) {
		if (from != 'A' || from != 'B' || from != 'C') {
			cout << "please input A or B or C !!" << endl;
			cout << "from:";
			cin >> from;
		}
		cout << "to:";
		cin >> to;
		if (to != 'A' || to != 'B' || to != 'C') {
			cout << "please input A or B or C !!" << endl;
			cin >> to;
		}
		else if (to == from) {
			cout << "please input the other two alphabets !!" << endl;
			cin >> to;
		}
	}


	system("pause");
	return 0;
}

/*void move_statement(char from,char to) {
	if(from!='A'||)
}*/