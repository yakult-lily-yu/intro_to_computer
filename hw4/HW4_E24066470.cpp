#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void input_func(int input[]){
		int i,in;
		cin>>in;
		if(in<1000||in>10000){
			cout<<"森七七!!遵守遊戲規則啦!!"<<endl; 
			cout<<"請輸入四個相異數字~"<<endl;
			input_func(input);
		}else{
			for(i=3;i>=0;i--){
				input[i]=in%10;
				in=in/10;
			}
		}
	}

int main(int argc, char** argv) 
{
	srand(time(0));
	int ans[4]={1+rand()%9,1+rand()%9,1+rand()%9,1+rand()%9};
	int i,n,in,input[4];
	int A=0,B=0;
	
	while(ans[0]==ans[1]||ans[0]==ans[2]||ans[0]==ans[3]||ans[1]==ans[2]||ans[1]==ans[3]||ans[2]==ans[3]){
		ans[0]=1+rand()%9;
		ans[1]=1+rand()%9;
		ans[2]=1+rand()%9;
		ans[3]=1+rand()%9;
		}
	//cout<<ans[0]<<ans[1]<<ans[2]<<ans[3]<<endl;	
	while(1){
		cout<<"請輸入四個相異數字~\n"<<endl;
		input_func(input);
		while(input[0]==input[1]||input[0]==input[2]||input[0]==input[3]||input[1]==input[2]||input[1]==input[3]||input[2]==input[3]){
			cout<<"森七七!!遵守遊戲規則啦!!"<<endl; 
			cout<<"請輸入四個相異數字~"<<endl;
			input_func(input);
		}
		A=0;
		B=0;	
		
		for(i=0;i<4;i++){
			for(n=0;n<4;n++){
				if(i==n){
					if(input[i]==ans[n]){
						A=A+1;
					}
				}
				else if(i!=n){
					if(input[i]==ans[n]){
						B=B+1;
					}
				}
			}
		}
		cout<<A<<"A"<<B<<"B"<<endl;

		if(A==4){
			cout<<"你贏了~灑花~"<<endl;
			break;
		}	
	}

	system("pause");
	return 0;
}
