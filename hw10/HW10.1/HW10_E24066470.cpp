#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <iterator>
#include <map>
#include <algorithm> 
using namespace std;

int gg_count=0;
string X ;
string Y ;
vector<vector<int>> table; // 動態規則表
set<string> lcs_set;      // set保存所有的LCS
vector<int> length_store;
vector<set<string>> individual_lcs;
vector<vector<string>> data_and_length;

int max(int a, int b)
{
	return (a>b) ? a : b;
}

/* 字符串逆序*/
string Reverse(string str)
{
	int low = 0;
	int high = str.length() - 1;
	while (low < high)
	{
		char temp = str[low];
		str[low] = str[high];
		str[high] = temp;
		++low;
		--high;
	}
	return str;
}

/*構造表，並返回X和Y的LCS的長度*/
int lcs(int m, int n)
{
	// 表的大小为(m+1)*(n+1)
	table = vector<vector<int>>(m + 1, vector<int>(n + 1));

	for (int i = 0; i<m + 1; ++i)
	{
		for (int j = 0; j<n + 1; ++j)
		{
			// 第一行和第一列置0
			if (i == 0 || j == 0)
				table[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				table[i][j] = table[i - 1][j - 1] + 1;
			else
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		}
	}
	return table[m][n];
}

/*求出所有的最長公共子序列，並放入set中*/
void traceBack(int i, int j, string store)
{
	while (i>0 && j>0)
	{
		if (X[i - 1] == Y[j - 1])
		{
			store.push_back(X[i - 1]);
			--i;
			--j;
		}
		else
		{
			if (table[i - 1][j] > table[i][j - 1])
				--i;
			else if (table[i - 1][j] < table[i][j - 1])
				--j;
			else   // 相等的情况
			{
				traceBack(i - 1, j, store);
				traceBack(i, j - 1, store);
				return;
			}
		}
	}
	lcs_set.insert(Reverse(store));
}


int main()
{
	string filename;
	string line;
	vector<string> mydata;
	ifstream file;

	//讀檔
	cout << "please input the file name:";
	cin >> filename;
	//filename = "input.txt";
	file.open(filename, ios::in);

	while (!file)
	{
		cout << "read file error !!!" << endl;
		cout << "please input file name again:";
		cin >> filename;
		file.open(filename, ios::in);
	}
	while (getline(file, line))
	{
		mydata.push_back(line);
	}
	/*cout << "Data set:" << endl;
	for (int i = 0; i < mydata.size(); i++)
	{
		cout << mydata[i] << endl;
	}*/

	int counter=0;
	for (std::vector<string>::iterator it=mydata.begin();it!=mydata.end();++it)
	{
		for (std::vector<string>::iterator it1=mydata.begin()++;it1!=mydata.end();++it1)
		{
			X = *it;
			Y = *it1;

			int m = X.length();
			int n = Y.length();
			int length;
			string length1;
			vector<string> vs;

			length = lcs(m, n);
			length1 = to_string(length);
			if (X!=Y)
			{
				//cout << length << " ";
				length_store.push_back(length);//將各個子序列的長度存入length_store
			}
			
			vs.push_back(X);//將比較的string和length都存入data_and_length，方便印出
			vs.push_back(Y);
			data_and_length.push_back(vs);
			data_and_length[counter].push_back(length1);
		
			//cout << "The length of LCS is " << length << endl;
			string store;
			traceBack(m, n, store);
			individual_lcs.push_back(lcs_set);
			// 倒序输出
			//set<string>::iterator it2 = lcs_set.begin();
			//for (it2 = lcs_set.begin(); it2 != lcs_set.end(); ++it2)
				//cout << *it2 << endl;
			store.clear();
			lcs_set.clear();
			counter++;
		}
		//cout << endl;
	}
	
	/*for (int i = 0; i < length_store.size(); i++)
	{
		cout << length_store[i]<<" ";
	}*/
	//system("pause");
	int max=0;//找出最大子序列長度
	for (int i = 0; i < length_store.size()-1; i++)
	{
		if (length_store[i] > length_store[i + 1])
		{
			max = length_store[i];
			length_store[i + 1] = max;
			length_store[i] = length_store[i + 1];
		}
	}
	cout << "\nsize of longest common sequences is : ";
	cout << max <<"\n"<< endl;

	/*for (int i = 0; i < individual_lcs.size(); i++)
	{
		for (set<string>::iterator it = individual_lcs[i].begin(); it != individual_lcs[i].end(); ++it)
		{
			cout << *it<<" ";
		}
		cout << endl;
	}*/
	string max_s;
	max_s = to_string(max);
	for (int i=0;i<data_and_length.size();i++)
	{
		for (int j=0;j<data_and_length[i].size();j++)
		{
			if (data_and_length[i][j] == max_s)
			{
				vector<string> q;
				q = data_and_length[i];
				for (int k = 0; k < q.size()-1; k++)//印出可產生最大子陣列的字串
				{
					cout << q[k];
					cout << ",";
				}
				cout << ":"<<endl;
				
				bool qq = true;
				for (int d = 0; d < individual_lcs.size(); d++)
				{
					//if (qq)
					//{
						//gg_count = 0;
						for (set<string>::iterator it = individual_lcs[d].begin(); it != individual_lcs[d].end(); ++it)
						{
							bool *compare = new bool[max];
							for (int u = 0; u < max; u++)
							{
								compare[u] = false;
							}

							int a = (*it).size();

							if (a == max)
							{
								for (int c = 0; c < q[0].length(); c++)
								{
									for (int g = 0; g < a; g++)
									{
										if (q[0][c] == (*it)[g])
										{
											if (compare[g] && g + 1<max&&q[0][c] == (*it)[g + 1]) {
												compare[g + 1] = true;
											}
											else {
												compare[g] = true;
											}
											break;
										}
									}
								}

								int counter_b = 0;
								bool t1 = false;
								for (int w = 0; w < max; w++)
								{
									if (compare[w] == true)
									{
										counter_b++;
									}
								}
								if (counter_b == max)
								{
									t1 = true;
								}
								if (t1)
								{
									//cout << counter_in << " ";
									cout << *it << " ";
									//gg_count++;
								}
								//cout << gg_count << endl;
								//qq = false;
							}
							
						}
						
					//}
				}
				cout <<"\n"<< endl;
			}
		}
	}

	

	//getchar();
	system("pause");
	return 0;
}