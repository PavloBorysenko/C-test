#include<iostream>
#include<Windows.h>
#include<conio.h>
#include <time.h>
using namespace std;
class nastole{
public:
	int kar;
	int mas;

	nastole(){
		kar=0;
		mas=0;
	}
	
	
};
char znach(nastole kart){
	char z;
	if(kart.mas==9||kart.mas==22||kart.mas==35||kart.mas==48)return 'T';
	if(kart.mas==10||kart.mas==23||kart.mas==36||kart.mas==49)return 'V';
	if(kart.mas==11||kart.mas==24||kart.mas==37||kart.mas==50)return 'D';
	if(kart.mas==12||kart.mas==25||kart.mas==38||kart.mas==51)return 'K';
	return '_';
	}

char mastK(nastole kart){
	char k;
	if(kart.mas>=0&&kart.mas<=12)return char(03);
	if(kart.mas>=13&&kart.mas<=25)return char(04);
	if(kart.mas>=26&&kart.mas<=38)return char(05);
	if(kart.mas>=39&&kart.mas<=51)return char(06);
	}
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
		cout<<"Мешаем колоду!!!"<<endl;
		Sleep(1500);
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
	
	return false;
	}
	
	else {
		
		return true;
	}
}
bool black(int sum){
	if(sum==21)return true;
	else return false;
}
void stol(nastole kartuP[8], nastole kartuC[8], int sum1,int sum2){
	system("cls");
	cout<<"Kartu CPU ";
	for( int i=0;i<8;i++){
		if(kartuC[i].kar!=0){
	cout<<"|"/*<< kartuC[i].kar*/<< mastK(kartuC[i])<<" "/*<<znach(kartuC[i])<<"|  "*/;
	if(znach(kartuC[i])==84||znach(kartuC[i])==86||znach(kartuC[i])==68||znach(kartuC[i])==75){
	cout<<znach(kartuC[i])<<"|";
	}
	else{ cout<<kartuC[i].kar<<"|";}
		}
	}
	cout<<endl<<"Suma "<< sum2<<endl;
	cout<<endl;
	cout<<"Kartu Tvoi ";
	for(int i=0;i<8;i++){
		if(kartuP[i].kar!=0){
	cout<<"|"/*<< kartuP[i].kar*/<<mastK(kartuP[i])<<" "/*<<znach(kartuP[i])<<"|  "*/;
	if(znach(kartuP[i])==84||znach(kartuP[i])==86||znach(kartuP[i])==68||znach(kartuP[i])==75){
	cout<<znach(kartuP[i])<<"|";
	}
	else{ cout<<kartuP[i].kar<<"|";}
		}
	}
	cout<<endl<<"Suma "<< sum1<<endl;
	cout<<endl;
	cout<<"  ******************************************"<<endl;
	cout<<"  Стрелка  вниз -- взять еще карту  "<<endl;
	cout<<"  Cтрелка вверх -- достаточно карт "<<endl;
	cout<<"  ESC -- выход"<<endl;
	cout<<"  Сильно не спешите с нажатием, работают Sleep-ы"<<endl;
	
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
	 nastole cpu[8];
	 nastole player[8];
 cout<<"Карты CPU  ";
 for( j=0;j<2;j++){
	 cpu[j].kar=kol.vzyat(randon());
	 cpu[j].mas=kol.mast;
	 sum2+=cpu[j].kar;
 }
	
   
   cout<<" Твии карты   ";
 for( i=0;i<2;i++){
	 player[i].kar=kol.vzyat(randon());
	 player[i].mas=kol.mast;
     sum1+= player[i].kar;	 
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
				player[i].kar=kol.vzyat(randon());
				player[i].mas=kol.mast;
				sum1+=player[i].kar;
				stol(player,cpu,sum1,sum2);
			   
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
              


		}
}
	if(provOchk(sum1)==false)continue;
	if(black(sum1)==true)continue;
	for(;;){
		if(sum2<17){
			j++;
			cpu[j].kar=kol.vzyat(randon());
			cpu[j].mas=kol.mast;
			sum2+=cpu[j].kar;
			stol(player,cpu,sum1,sum2);
         
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