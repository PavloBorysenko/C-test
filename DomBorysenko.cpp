#include<iostream>
#include<Windows.h>
#include<conio.h>
#include <time.h>
using namespace std;
 
class koloda{
public:
	int karta [52];
	int count;
	int mast;
	koloda(){
		newcoloda();

	}
	void newcoloda(){
		int c=2;
		int j=0;
		int b=0;
		/*for( int i=0;i<52;i++){
			
				karta[i]=c;
			    j++;
				if(j==4){c++;j=0;}
		if(c>11)c=2;
		}*/
		for(int i=0;i<4;i++){
			c=2;
			for(int j=0;j<13;j++){
			    karta[b]=c;
				b++;
				c++;
				if(c>11)c=2;
			}
		
		}

		count=1;
	}
	int vzyat(int i){
		if(count>=52)newcoloda();
		if(karta[i]==0 ){vzyat(rand()%52);}
		else {
		count++;
		int b=karta[i];
		mast=i;
		karta[i]=0;
		return b;
		}
	}

};
int randon(){
	return rand()%52;
}
bool provOchk(int sum){
	if(sum>21){
	//cout<<"Proigral"<<endl;
	//Sleep(1000);
	return false;
	}
	///*if(sum==21){
	//cout<<"Win!!!!"<<endl;
	//Sleep(1000);
	//return false;*/
	//}
	else {
		/*cout<<"???"<<endl;*/
		return true;
	}
}
bool black(int sum){
	if(sum==21)return true;
	else return false;
}
void stol(int kartuP[8], int kartuC[8], int sum1,int sum2){
	system("cls");
	cout<<"Kartu CPU ";
	for( int i=0;i<8;i++){
		if(kartuC[i]!=0){
	cout<<"|"<< kartuC[i]<< "|  ";
		}
	}
	cout<<endl<<"Suma "<< sum2<<endl;
	cout<<endl;
	cout<<"Kartu Tvoi ";
	for(int i=0;i<8;i++){
		if(kartuP[i]!=0){
	cout<<"|"<< kartuP[i]<<"|  ";
		}
	}
	cout<<endl<<"Suma "<< sum1<<endl;
	cout<<endl;
	cout<<"  ******************************************"<<endl;
	cout<<"  Стрелка  вниз -- взять еще карту  "<<endl;
	cout<<"  Cтрелка вверх -- достаточно карт "<<endl;
	cout<<"  ESC -- выход"<<endl;
	cout<<"  Сильно не спешите с нажатием, работают Sleep-ы"<<endl;
	cout<<"  Масть не высвечивается т.к. в Blackjack не имеет значения"<<endl;
	cout<<"  ******************************************"<<endl;
}
void main(){
 setlocale (LC_ALL,"Russian");	
 srand(time(NULL));
 koloda kol;
 
 char pressKey = '\0';
	int keyInd = 0;
	int keyVal = 0;
 int sum1,sum2;
 for(;;){
	
	 int i=0,j=0;
	 sum1=sum2=0;
	 int cpu[8]={0};
	 int player[8]={0};
 cout<<"Карты CPU  ";
 for( j=0;j<2;j++){
	 cpu[j]=kol.vzyat(randon());
	 sum2+=cpu[j];
 }
	/*stol(cpu,sum1);*/
	/*if (provOchk(sum1)==false)continue;
    if (black(sum))
   */
   
   cout<<" Твии карты   ";
 for( i=0;i<2;i++){
	 player[i]=kol.vzyat(randon());
     sum1+= player[i];	 
 }
 stol(player,cpu,sum1,sum2);
 if(provOchk(sum1)==false){
	 cout<<"Ты проиграл!!! "<<endl;
	 Sleep(2000);
	 continue;
 }
 if(provOchk(sum2)==false){
	 cout<<"СPU проиграл!!! "<<endl;
	 Sleep(2000);
	 continue;
 }
 if(black(sum1)==true){
	 cout<<" 21 Ты выиграл!!! "<<endl;
	 Sleep(2000);
	 continue;
 }
 if(black(sum2)==true){
	 cout<<" 21 CPU выиграл!!! "<<endl;
	 Sleep(2000);
	 continue;
 }
 	while (pressKey != '\r'){
		if (kbhit())
		{
			keyInd = getch();
			if (keyInd == 224)
			{ 
				keyVal = getch();
				
				if(keyVal==80){
					i++;
				player[i]=kol.vzyat(randon());
				sum1+=player[i];
				stol(player,cpu,sum1,sum2);
			    /* if(provOchk(sum1)==false) break;
				 if(provOchk(sum2)==false) break;*/
				if(provOchk(sum1)==false){
	               cout<<"Ты проиграл!!! "<<endl;
				   Sleep(2000);
	               break;
                 }
 
				if(black(sum1)==true){
					cout<<" 21 Ты выиграл!!! "<<endl;
					Sleep(2000);
					 break;
				}

				}
				else break;

			}
			if(GetAsyncKeyState(VK_ESCAPE)){
				exit(1);
			}
                 /*if(provOchk(sum1)==false) continue;
				 if(provOchk(sum2)==false) continue;*/


		}
}
	if(provOchk(sum1)==false)continue;
	if(black(sum1)==true)continue;
	for(;;){
		if(sum2<17){
			j++;
			cpu[j]=kol.vzyat(randon());
			sum2+=cpu[j];
			stol(player,cpu,sum1,sum2);
           /* if(provOchk(sum2)==false) break;*/
			if(provOchk(sum2)==false){
	               cout<<"CPU проиграл!!! "<<endl;
				   Sleep(2000);
	               break;
                 }
			if(black(sum2)==true){
					cout<<" 21 CPU выиграл!!! "<<endl;
					Sleep(2000);
					 break;

				}
		}
		else break;
	}
	   if(provOchk(sum2)==false)continue;
	   if(black(sum2)==true)continue;
	 /*if(provOchk(sum2)==false) continue;*/
	/*Sleep(1000);*/
				if(GetAsyncKeyState(VK_ESCAPE)){
				break;
			}
				if(sum1<22&&sum2<22){
				if(sum1>sum2){
					cout<<"Ты выиграл!!!!!!"<<endl;
				}
				else cout<<"CPU  выиграл!!!!!!"<<endl;
				Sleep(2000);
				}
}
}