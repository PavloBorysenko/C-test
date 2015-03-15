#include<iostream>
#include<Windows.h>
#include<conio.h>
#include <time.h>
using namespace std;

class Baraban {
	public:
	int Bar[16];

Baraban(){
	  Bar[0]=Bar[5]=Bar[9]=Bar[2]=01;
	  Bar[4]=Bar[7]=Bar[11]=Bar[15]=02;
	  Bar[1]=Bar[6]=Bar[13]=03;
	  Bar[8]=Bar[14]=5;
	  Bar[3]=Bar[10]=14;
	  Bar[12]=15;
}

void Roll(){
	int temp=Bar[0];
	for(int i=1;i<16;i++){
		Bar[i-1]=Bar[i];
	}
	Bar[15]=temp;
	}
};
int prov(Baraban bar1, Baraban bar2, Baraban bar3){
	if(bar1.Bar[0]==bar2.Bar[0]&&bar1.Bar[0]==bar3.Bar[0]){
	if(bar1.Bar[0]==01) {
		
		cout<<"You WIN!!!  30 $"<<endl; 
		return 30;
	}
	if(bar1.Bar[0]==02){
	
	cout<<"You WIN!!!  50 $"<<endl;
	return 50;
	}
	if(bar1.Bar[0]==03){
	
	cout<<"You WIN!!!  100 $"<<endl;
	return 100;
	}
	if(bar1.Bar[0]==10){
	
	cout<<"You WIN!!!   150 $"<<endl;
	return 150;
	}
	if(bar1.Bar[0]==14){

	cout<<"You WIN!!!  200$"<<endl;
	return 200;
	}
	if(bar1.Bar[0]==15){
	
	cout<<"You WIN!!!  ДжеКПОТ!!! $"<<endl;
	return 1000;
	}
	}
	else if(bar1.Bar[0]==bar2.Bar[0]){
	cout<<"You WIN!!!  10 $"<<endl;
	return 10;
	}
	else return 0;
}
void Showbar(Baraban *bar1, Baraban *bar2, Baraban *bar3, int *m){
	system("cls");
	cout<<"  |"<<char(bar1->Bar[1])<<"| |"<<char(bar2->Bar[1])<<"| |"<<char(bar3->Bar[1])<<"|"<<endl;
	cout<<"->|"<<char(bar1->Bar[0])<<"| |"<<char(bar2->Bar[0])<<"| |"<<char(bar3->Bar[0])<<"|<-"<<endl;
	cout<<"  |"<<char(bar1->Bar[15])<<"| |"<<char(bar2->Bar[15])<<"| |"<<char(bar3->Bar[15])<<"|"<<endl;

	cout<<endl<<endl<<" YOU MANY  "<<*m<<" $"<<endl;
	Sleep(250);
    
}
void rollbar(Baraban *bar1, Baraban *bar2, Baraban *bar3, int *m){
	int n1=rand()%30+15;
	int n2=rand()%30+15;
	int n3=rand()%30+15;
	
	for(;;){
		if(n1>0){
			bar1->Roll();
			n1--;
		}
		if(n2>0){
			bar2->Roll();
			n2--;
		}
		if(n3>0){
			bar3->Roll();
			n3--;
		}
		Showbar( bar1,  bar2,  bar3, m);
		if(n1==0&&n2==0&&n3==0)break;
	}
	
}

void main(){
 setlocale (LC_ALL,"Russian");	
 srand(time(NULL));
 int many;
 Baraban br1;
 Baraban br2;
 Baraban br3;
 cout<<"Введите сумму каторую готовы проиграть"<<endl;
 cin>>many;
 Showbar(&br1,&br2,&br3,&many);
 for(;;){
	 getch();
	 if(GetAsyncKeyState(VK_RETURN)){
	 many-=5;
	 rollbar(&br1,&br2,&br3,&many);
	 }
	many+=prov(br1,br2,br3); 
	
	if(many<5){
		cout<<"Если хотите продолжить пришлите SMS* на номер 455 655 4336 67 "<<endl<<endl<<endl;
		cout<<"Стоимость SMS 10000000000 $";
		break;}
 if(GetAsyncKeyState(VK_ESCAPE)){
				exit(1);
			}
 }

}