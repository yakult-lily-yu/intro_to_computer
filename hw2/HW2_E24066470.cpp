#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int input;
	
	cout<<"請輸入0~5:\n"<<endl;
	cin>>input;	
	while(input<0||input>5){
			cout<<"超出範圍了> <"<<endl;
			cout<<"輸入正確範圍啦!!!"<<endl;
			cin>>input; 
	}
	while(0<=input<=5){
		if(input==0){
		cout<<"================================="<<endl;
		cout<<"|        NAME: 余采蓴 ^ ^        |"<<endl;
		cout<<"|        GENDER: male            |"<<endl;
		cout<<"|        BIRTHDAY: 88/03/17      |"<<endl;
		cout<<"|        PHONE: 0936756715       |"<<endl;
		cout<<"| MAIL: lilyshow.10204@gmail.com |"<<endl;
		cout<<"|                                |"<<endl;
		cout<<"|      NICE TO MEET YOU > <      |"<<endl;
		cout<<"================================="<<endl;
		}else if(input==1){
			cout<<"*"<<endl;
		}else if(input==2){
			cout<<"**"<<endl;
		}else if(input==3){
			cout<<"***"<<endl;
		}else if(input==4){
			cout<<"****"<<endl;
		}else if(input==5){
			cout<<"*****"<<endl;
		}
		cout<<"請輸入0~5:"<<endl;
		cin>>input;
		
		while(input<0||input>5){
			cout<<"超出範圍了> <"<<endl;
			cout<<"輸入正確範圍啦!!!"<<endl;
			cin>>input; 
		}
	}
	
	
	
	system("pause");
	return 0;
}
