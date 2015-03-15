#include<iostream>
#include<string>
#include<list>
#include <time.h>
#include <stdio.h>
#include<Windows.h>
#include<conio.h>
#include <io.h>
using namespace std;

HANDLE hConsole;
string spis[]={"Голубой кит", "Авианосец","Торпедный катер","Флагман врага","Подводная лодка","Дед мазай","Линкор","Эсминец","Минный трал","Крейсер"};
void PrintCombat(int val,string N)
{
	
	system("cls");
	val == 0 ? cout << "->" << "Боевой радар" : cout <<"  "<< "Боевой радар";
	cout << endl;
	val == 1 ? cout << "->" << "Зарядить порпеду" : cout << "  "<<"Зарядить порпеду";
	cout << endl;
	val == 2? cout << "->" << "Огонь" : cout << "  "<<"Огонь";
	cout << endl<< endl;
	
	cout<<"Текущая цель:  "<<N<<endl<<endl;
	cout<<"  To exit, press [TAB]"<<endl;
	cout<<"Для активации выбраного пункта меню нажми [SPACE]"<<endl;
	
}


void PrintKey(int val)
{
	
	system("cls");
	val == 0 ? cout << "->" << "Информация" : cout <<"  "<< "Информация";
	cout << endl;
	val == 1 ? cout << "->" << "Режим хода" : cout << "  "<<"Режим хода";
	cout << endl;
	val == 2? cout << "->" << "Боевой режим" : cout << "  "<<"Боевой режим";
	cout << endl<< endl;
	
	
	cout<<"  To exit, press [Esc]"<<endl;
	cout<<"Для активации выбраного пункта меню нажми [SPACE]"<<endl;
	
}
class submar{
public:
	string name;
	int Torp;
	int Disel;
	bool zar;
	int hit;
	submar(){
		name="Красный октябрь";
		Torp=20;
		Disel=100;
		zar=false;
		hit=0;
	}
	void ShowSub(){
		cout<<endl<<endl;
		cout<<"Название лодки:    "<<name<<endl;
		cout<<"Уровень топлива:   "<<Disel<<" %"<<endl;
		cout<<"Количество торпед: "<<Torp<<" ед."<<endl;
		cout<<"\n\nНа счету  "<<hit<<" вражеских едениц!!!!\n";
	}
	void regXod(){
		char press='/0';
		int Otl=0;
		int Knop=0;
		system("cls");
		Anim();
		while(press!='/r'){
			if(kbhit()){
				Otl=getch();
				if(Otl=224){
					Knop=getch();
					if(Knop==77){
						
						drive(2);
					}
					if(Knop==75){
						
						drive(1);
					}
					if(Knop==80){
						cout<<"Стоим!!!"<<endl;
					}
					if(Knop==72){
						cout<<"Всплываем, и на дозаправку!"<<endl;
						reload();
					}
				}
			if(GetAsyncKeyState(VK_TAB)){PrintKey(1); return;}
			}
		}
		PrintKey(0);
	}

	void reload(){
		Torp=20;
		Disel=100;
		zar= false;
		cout<<"Под завязку!!!"<<endl;
	}
	void drive(int c){ 
			system("cls");
		for(;;){
			if(kbhit()){if(GetAsyncKeyState(VK_DOWN)){
				
                Anim();
				return;}}
			try{
				if(Disel<=0)
					throw Disel;
				Disel-=3;
			}
			catch(int){
			cout<<"!!!ТОПЛИВО КОНЧИЛОСЬ. Надо всплывать на дозаправку!!!!"<<endl;
			Anim();
			return;
			}
			

			if(c==1){
				for(int i=0; i<4;i++){
				   

					Anim();

					for(int j=0;j<i;j++){
						cout<<"   ";
					}
					cout<<"*            *                *               *                   *    "<<endl;
					
					Sleep(100);
					system("cls");
					
				}
		
			}
			 if(c==2){ 
				for(int i=4; i>=0;i--){
				    Anim();
					for(int j=0;j<=i;j++){
						cout<<"   ";
					}
					cout<<"*            *                *               *                   *  "<<endl;
					
					Sleep(100);
					system("cls");
					
				}
			
			}
			
			
			
					
		}
		
	}
	void Anim(){
	 cout<<" [->] Ход вперед. [<-] Ход назад."<<endl;
	 cout<<"Cтрелка вверх всплытие для дозаправки"<<endl;
	 cout<<"Стрелка вниз  полная остановка(ОБЯЗАТЕЛЬНО ДЛЯ СМЕНЫ НАПРАВЛЕНИЯ)"<<endl;
	 cout <<"Для выхода из режима движения [TAB]"<<endl<<endl;
	 cout<<"Толиво:";
	 for(int i=0;i<=100;i++){
		 if(i<Disel){cout<<"|";}
		/* else cout<<" ";*/
	 }
	 cout<<endl<<endl;
					cout<<"                                        Г "<<endl;
					cout<<"                                        #"<<endl;
					cout<<"                                   <#o##o##o##>"<<endl;
	
	}

	void Zar(){
		try{
			if(Torp<=0)
				throw Torp;
			Torp-=1;
			zar=true;
			cout<<"Торпеда заряжена!!!"<<endl;
		}
		catch(int){
			cout<<"Нет  торпед. Рекомендую всплыть для дозаправки"<<endl;
		}
	}
	void Otvetka(string A){
		cout<<endl<<endl<<endl<<"           "<<A<<" нас заметил!!!! Готовит ответный удар!!! "<<endl;
		Sleep(1500);
		cout<<endl<<"        Уходим от удара!!! Моневрируем!!!!";
		Sleep(1500);
		if(rand()%4==0){
			system("cls");
			cout<<"\n\n\n\n        БАБАХ!!!!!! \n\n\n          SOS.....SOS.....SOS....SOS....SOS\n";
			cout<<"         ИДЕМ НА КОРМ КРАБАМ!!!!\n\n\n\n";
			cout<<"   Подбил "<<hit<<" вражеских ед. \n\n";
			exit(1);
		}
		else cout<<"\n\n\n     Еле ушли!!! Было близко. Надо ответить или уходить!\n\n";
		}
	bool Fire(string N){
		if(zar==true){
		   cout<<"Запуск торпеды!!!"<<endl;
		   zar=false;
		   for(int i=500;i>=0;i-=100){
		   cout<<endl<<endl<<endl<<"          До цели  осталось "<<i<<" метров"<<endl;
		   Sleep(500);
		   system("cls");
		}
		if(rand()%4!=0){
			cout<<endl<<"        цель:  "<<N<<", УНИЧТОЖИНА!!!"<<endl;
			hit++;
			return true;
			}
		else cout<<"Противник маневрировал и торпеда прошла МИМО!!!"<<endl;
			Otvetka(N);
		}
		else{ 
			cout<<"      Торпеда не заряжена!!!"<<endl;
			return false;
		}
	}

};
class Celi{
public:
	
	string Name;
	int key;
	list<string>Cel;
	list< string>::iterator it;
	list< string>::iterator temp;
	Celi(){
		
		key=0;
		Name="Нет";
	}

	void creatList(){
		int z=0;
		int c=rand()%6;
		for(int i=0; i<c;i++){
			z=rand()%10;
			Cel.push_back(spis[z]);
			
		}
	
	}


	void printCeli(int val){  
		system("cls");
if(Cel.empty()==false){
	 int z=0;
		for(it=Cel.begin();it!=Cel.end(); it++){
			if(z==val){
				cout<<"-->"<<"Цель: "<<(*it)<<endl;
				temp=it;
			}
			else {
				cout<<"   "<<"Цель: "<<(*it)<<endl;
			}
		z++;
		}
		cout << endl<< endl;
}
else {
	cout<<"                  В радиусе действия радара враг НЕ ОБНАРУЖЕН!!!"<<endl<<"          Поищи в другом месте!"<<endl<<endl<<endl<<endl;
}
	
	
	cout<<"  To exit, press [TAB]"<<endl;
	cout<<"Для активации выбраного пункта меню нажми [SPACE]"<<endl;
	}

	void MenyCel(){
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    SetConsoleTextAttribute(hConsole, (WORD)((1 << 4) | 10));
	
	    cout << endl;
		char press='/0';
		int Ind=0;
		int KVal=0;
		int Val=0;
		printCeli(Val);
		while(press='/r'){
			if(kbhit()){
				Ind=getch();
				if(Ind==224){
				   KVal=getch();
				   KVal==80?Val++:Val--;
				   if(Val<0)Val=Cel.size()-1;
				   if(Val>Cel.size()-1)Val=0;
				   printCeli( Val);
				}
			
			if(GetAsyncKeyState(VK_SPACE)){
				if(Cel.empty()==true){PrintCombat(0,Name);return;}
					
					/*auto rez*/  
				/*key=rez;*/
				Name=(*temp);
				cout<<"Цель "<<(*temp)<<" захвачена."<<endl;
				Sleep(1000);
				PrintCombat(0,Name);
				return;

		}
			if(GetAsyncKeyState(VK_TAB)){Name="НЕТ";PrintKey(0); return;}
			}
	} 
	}
	void DelCel(){
	Cel.erase(temp);
	Name="НЕТ";
    /*(*temp)="-1";*/
	}
	void DelAll(){
	Cel.clear();
	}
};
void main(){
setlocale (LC_ALL,"Russian");
srand(time(NULL));
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((1 << 4) | 10));
	submar SUB;
	Celi obj;
	cout << endl;
	char pressKey = '\0';
	int keyInd = 0;
	int keyVal = 0;
	int val=0;
	PrintKey( val);
	while (pressKey != '\r'){
		if (kbhit())
		{
			keyInd = getch();
			if (keyInd == 224)
			{ 
				keyVal = getch();
			
				keyVal==80?val++:val--;
				if(val<0)val=2;
				if(val>2)val=0;
				
				PrintKey(val);
					
			
			}
			if(GetAsyncKeyState(VK_SPACE)){
				switch(val){
				case 0:
					{
						SUB.ShowSub();
					break;}
				case 1 :	
					{
						SUB.regXod();
					
					break;}
				case 2:
				{	
					
					obj.creatList();
					cout << endl;
					char pressKey = '\0';
					int keyInd = 0;
					int keyVal = 0;
					int val=0;
					PrintCombat( val,"НЕТ");
					while (pressKey != '\r'){
						if (kbhit())
						{
							keyInd = getch();
							if (keyInd == 224)
							{ 
							keyVal = getch();
			
							keyVal==80?val++:val--;
							if(val<0)val=2;
							if(val>2)val=0;
				
							PrintCombat(val,obj.Name);
							
			
							}
							if(GetAsyncKeyState(VK_SPACE)){
						switch(val){
							case 0:
							{
								obj.MenyCel();
							break;}
							case 1 :	
							{
								
								SUB.Zar();
					
							break;}
							case 2:
								{	
								if(obj.Name=="НЕТ"){
								
								cout<<"Сначала надо выберать цель!!!"<<endl;
								}
								else{
								bool pod=SUB.Fire(obj.Name);
								if(pod==true){
								obj.DelCel();
								}
								}
							break;}
						
							}
			
							}
		
						if(GetAsyncKeyState(VK_TAB)){
							obj.DelAll();PrintKey(2);break;
						}
					
						}
					}
			
						break;}
					
						}
			
			}
		
		if(GetAsyncKeyState(VK_ESCAPE)){
				break;
	}
		
		}
	}

	}
