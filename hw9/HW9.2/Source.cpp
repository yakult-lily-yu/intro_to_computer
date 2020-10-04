#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <list>         
#include <algorithm> 
#include <cstdlib>
#include <iterator> 
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;

vector<set<string>> readfile(string filename);
set<string> find_L1(vector<set<string>> Data_tuple);

int main()
{
	set<string> L1;
	vector<set<string>> mydata;
	vector<map<set<string>,int>> suit_support;
	string file_name;
	map<string, int>map_item;
	map<set<string>, int>map_count;
	double support_scale, confidence_scale, support_num;
	int com_count = 1;

	cout << "please input the file name:" << endl;
	cin >> file_name;

	mydata = readfile(file_name);
	L1 = find_L1(mydata);

	cout << "\nplease input minimum support:";
	cin >> support_scale;

	support_num = support_scale*mydata.size();

	cout << "\nplease input minimum confidence:";
	cin >> confidence_scale;
	cout << endl;

	for (int i = 0; i < mydata.size(); i++)//т虫縒じ籔ㄤ瞷Ω计
	{
		for (std::set<std::string>::iterator it = mydata[i].begin(); it != mydata[i].end(); ++it)
		{
			string s;
			s = *it;
			std::map<string, int>::iterator it1;
			it1 = map_item.find(s);
			if (it1 != map_item.end())
			{
				map_item[(*it)]++;
			}
			else
			{
				map_item[(*it)] = 1;
			}
		}
	}

	std::map<string, int>::iterator it;//埃瞷Ω计support_num计
	for (it = map_item.begin(); it != map_item.end(); ++it)
	{
		set<string> s;
		s.insert(it->first);
		if (it->second >= support_num) {
			map_count[s] = it->second;
		}
	}
	suit_support.push_back(map_count);//盢才狥狥崩suit_support纗
	/*for (int i = 0; i < suit_support.size(); i++)//cout代刚
	{
		std::map<std::set<string>, int>::iterator it1;
		for (it1 = suit_support[i].begin(); it1 != suit_support[i].end(); it1++)
		{
			std::set<string>::iterator it2;
			for (it2 = it1->first.begin(); it2 != it1->first.end(); it2++)
			{
				cout << (*it2) << " "<<it1->second ;
			}
			cout << endl;
		}
	}*/
	bool state = false;
	while (state == false)
	{
		map<set<string>, int> subset;

		for (std::map<set<string>, int>::iterator it1 = map_count.begin(); it1 != map_count.end(); ++it1)//逼舱
		{
			for (std::map<set<string>, int>::iterator it2 = map_count.begin()++; it2 != map_count.end(); ++it2)
			{
				set<string> set0;
				set0.insert(it1->first.begin(), it1->first.end());
				set0.insert(it2->first.begin(), it2->first.end());
				if (set0.size() == (com_count + 1))
					subset[set0] = 0;
			}
		}

		/*for (std::map<std::set<string>, int>::iterator it1 = subset.begin(); it1 != subset.end(); it1++)//cout代刚
		{
			for (std::set<string>::iterator it2 = it1->first.begin(); it2 != it1->first.end(); it2++)
			{
				cout << (*it2) <<  ",";
			}
			cout << ": " << it1->second;
			cout << endl;
		}*/

		for (int i = 0; i < mydata.size(); i++)//璸计
		{
			for (map<set<string>, int>::iterator it1 = subset.begin(); it1 != subset.end(); it1++)
			{
				if (std::includes(mydata[i].begin(),mydata[i].end(),it1->first.begin(),it1->first.end()))
				{
					if (it1!=subset.end())
					{
						subset[(it1->first)]++;
					}
					else
					{
						subset[(it1->first)] = 1;
					}
				}
			}
		}
		/*for (std::map<std::set<string>, int>::iterator it1 = subset.begin(); it1 != subset.end(); it1++)//cout代刚
		{
			for (std::set<string>::iterator it2 = it1->first.begin(); it2 != it1->first.end(); it2++)
			{
				cout << (*it2) << ",";
			}
			cout << ": " << it1->second;
			cout << endl;
		}*/

		map_count.clear();
		for (std::map<set<string>, int>::iterator it1 = subset.begin(); it1 != subset.end(); ++it1)//籔support_numゑ耕才map_count
		{
			if (it1->second >= support_num) {
				map_count[(it1->first)] = it1->second;
			}
		}

		if (map_count.empty())
			state = true;

		suit_support.push_back(map_count);
		/*for (int i = 0; i < suit_support.size(); i++)//cout代刚
		{
			std::map<std::set<string>, int>::iterator it1;
			for (it1 = suit_support[i].begin(); it1 != suit_support[i].end(); it1++)
			{
				std::set<string>::iterator it2;
				for (it2 = it1->first.begin(); it2 != it1->first.end(); it2++)
				{
					cout << (*it2) << ",";
				}
				cout <<":"<< it1->second;
				cout << endl;
			}
		}*/
		com_count++;
	}

	cout << "the items suit mininum supprot and the times it appeared:" << endl;
	for (int i = 0; i < suit_support.size(); i++)//才support
	{
		std::map<std::set<string>, int>::iterator it1;
		for (it1 = suit_support[i].begin(); it1 != suit_support[i].end(); it1++)
		{
			std::set<string>::iterator it2;
			for (it2 = it1->first.begin(); it2 != it1->first.end(); it2++)
			{
				cout << (*it2) ;
			}
			cout << ":" << it1->second;
			cout << endl;
		}
	}

	cout << "\nthe items suit mininum confidence and it's proportion:" << endl;
	for (int i = 0; i < suit_support.size() - 1; i++)//才confidence
	{
		for (int j = i + 1; j < suit_support.size() - 1; j++)
		{
			std::map<set<string>, int>::iterator it2, it3;
			for (it2 = suit_support[i].begin(); it2 != suit_support[i].end(); it2++)
			{
				for (it3 = suit_support[j].begin(); it3 != suit_support[j].end(); it3++)
				{
					if (std::includes(it3->first.begin(), it3->first.end(), it2->first.begin(), it2->first.end()))
					{
						if ((double)it3->second / (double)it2->second >= confidence_scale)
						{
							//double min_confidence;
							//min_confidence = (double)it3->second / (double)it2->second;

							std::set<string>::iterator it4, it5;
							for (it4 = it2->first.begin(); it4 != it2->first.end(); it4++) 
							{
								cout << *it4 << " ";
							}
							cout << "-> ";
							for (it5 = it3->first.begin(); it5 != it3->first.end(); it5++)
							{
								cout << *it5 << " ";
							}
							cout << ": \"" << (double)it3->second / (double)it2->second <<" \""<< endl;
						}
					}
				}
			}
		}
	}


	system("pause");
	return 0;
}
vector<set<string>> readfile(string filename)
{
	vector <set <string>> Data_tuple;
	ifstream file(filename, ifstream::in);
	int line_counter;

	if (!file.good())
	{
		cout << "read file error" << endl;
		system("pause");
		exit(0);
	}
	while (file.good())
	{
		std::string line;
		getline(file, line);
		if (line.empty())
		{
			continue;
		}
		char *temp_char = new char[line.length() + 1];
		strcpy(temp_char, line.c_str());
		char *pch;
		set<string> tuple;
		pch = strtok(temp_char, ",");
		tuple.insert(pch);
		while ((pch = strtok(NULL, ",")))
		{
			tuple.insert(pch);
		}
		Data_tuple.push_back(tuple);
	}
	return Data_tuple;
}
set<string> find_L1(vector< set<string>> Data_tuple)
{
	set<string> L1;
	for (vector< std::set<std::string>>::iterator it1 = Data_tuple.begin(); it1 != Data_tuple.end(); ++it1)
		copy((*it1).begin(), (*it1).end(), inserter(L1, L1.end()));
	return L1;
}





