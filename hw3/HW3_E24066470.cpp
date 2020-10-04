#include <iostream>
using namespace std; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int i,n,n1,n2,input;
	
	n1=0;
	n2=1;
	
	cout<<"請輸入任一正整數:" <<endl; 
	cin>>input;
	cout<<"\n"<<endl;
	
	if(input==1){
		cout<<"0"<<endl;
	}else{
		cout<<"0"<<endl;
		for (i=2; i<=input; i++){	
	        n= n1 + n2;
	        n2=n1;
	        n1=n;
	        cout<<n<<endl;
	    }
	}
    
	system("pause");
	return 0;
}
