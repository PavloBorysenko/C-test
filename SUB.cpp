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
string spis[]={"������� ���", "���������","��������� �����","������� �����","��������� �����","��� �����","������","�������","������ ����","�������"};
void PrintCombat(int val,string N)
{
	
	system("cls");
	val == 0 ? cout << "->" << "������ �����" : cout <<"  "<< "������ �����";
	cout << endl;
	val == 1 ? cout << "->" << "�������� �������" : cout << "  "<<"�������� �������";
	cout << endl;
	val == 2? cout << "->" << "�����" : cout << "  "<<"�����";
	cout << endl<< endl;
	
	cout<<"������� ����:  "<<N<<endl<<endl;
	cout<<"  To exit, press [TAB]"<<endl;
	cout<<"��� ��������� ��������� ������ ���� ����� [SPACE]"<<endl;
	
}


void PrintKey(int val)
{
	
	system("cls");
	val == 0 ? cout << "->" << "����������" : cout <<"  "<< "����������";
	cout << endl;
	val == 1 ? cout << "->" << "����� ����" : cout << "  "<<"����� ����";
	cout << endl;
	val == 2? cout << "->" << "������ �����" : cout << "  "<<"������ �����";
	cout << endl<< endl;
	
	
	cout<<"  To exit, press [Esc]"<<endl;
	cout<<"��� ��������� ��������� ������ ���� ����� [SPACE]"<<endl;
	
}
class submar{
public:
	string name;
	int Torp;
	int Disel;
	bool zar;
	int hit;
	submar(){
		name="������� �������";
		Torp=20;
		Disel=100;
		zar=false;
		hit=0;
	}
	void ShowSub(){
		cout<<endl<<endl;
		cout<<"�������� �����:    "<<name<<endl;
		cout<<"������� �������:   "<<Disel<<" %"<<endl;
		cout<<"���������� ������: "<<Torp<<" ��."<<endl;
		cout<<"\n\n�� �����  "<<hit<<" ��������� ������!!!!\n";
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
						cout<<"�����!!!"<<endl;
					}
					if(Knop==72){
						cout<<"���������, � �� ����������!"<<endl;
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
		cout<<"��� �������!!!"<<endl;
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
			cout<<"!!!������� ���������. ���� ��������� �� ����������!!!!"<<endl;
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
	 cout<<" [->] ��� ������. [<-] ��� �����."<<endl;
	 cout<<"C������ ����� �������� ��� ����������"<<endl;
	 cout<<"������� ����  ������ ���������(����������� ��� ����� �����������)"<<endl;
	 cout <<"��� ������ �� ������ �������� [TAB]"<<endl<<endl;
	 cout<<"������:";
	 for(int i=0;i<=100;i++){
		 if(i<Disel){cout<<"|";}
		/* else cout<<" ";*/
	 }
	 cout<<endl<<endl;
					cout<<"                                        � "<<endl;
					cout<<"                                        #"<<endl;
					cout<<"                                   <#o##o##o##>"<<endl;
	
	}

	void Zar(){
		try{
			if(Torp<=0)
				throw Torp;
			Torp-=1;
			zar=true;
			cout<<"������� ��������!!!"<<endl;
		}
		catch(int){
			cout<<"���  ������. ���������� ������� ��� ����������"<<endl;
		}
	}
	void Otvetka(string A){
		cout<<endl<<endl<<endl<<"           "<<A<<" ��� �������!!!! ������� �������� ����!!! "<<endl;
		Sleep(1500);
		cout<<endl<<"        ������ �� �����!!! �����������!!!!";
		Sleep(1500);
		if(rand()%4==0){
			system("cls");
			cout<<"\n\n\n\n        �����!!!!!! \n\n\n          SOS.....SOS.....SOS....SOS....SOS\n";
			cout<<"         ���� �� ���� ������!!!!\n\n\n\n";
			cout<<"   ������ "<<hit<<" ��������� ��. \n\n";
			exit(1);
		}
		else cout<<"\n\n\n     ��� ����!!! ���� ������. ���� �������� ��� �������!\n\n";
		}
	bool Fire(string N){
		if(zar==true){
		   cout<<"������ �������!!!"<<endl;
		   zar=false;
		   for(int i=500;i>=0;i-=100){
		   cout<<endl<<endl<<endl<<"          �� ����  �������� "<<i<<" ������"<<endl;
		   Sleep(500);
		   system("cls");
		}
		if(rand()%4!=0){
			cout<<endl<<"        ����:  "<<N<<", ����������!!!"<<endl;
			hit++;
			return true;
			}
		else cout<<"��������� ������������ � ������� ������ ����!!!"<<endl;
			Otvetka(N);
		}
		else{ 
			cout<<"      ������� �� ��������!!!"<<endl;
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
		Name="���";
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
				cout<<"-->"<<"����: "<<(*it)<<endl;
				temp=it;
			}
			else {
				cout<<"   "<<"����: "<<(*it)<<endl;
			}
		z++;
		}
		cout << endl<< endl;
}
else {
	cout<<"                  � ������� �������� ������ ���� �� ���������!!!"<<endl<<"          ����� � ������ �����!"<<endl<<endl<<endl<<endl;
}
	
	
	cout<<"  To exit, press [TAB]"<<endl;
	cout<<"��� ��������� ��������� ������ ���� ����� [SPACE]"<<endl;
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
				cout<<"���� "<<(*temp)<<" ���������."<<endl;
				Sleep(1000);
				PrintCombat(0,Name);
				return;

		}
			if(GetAsyncKeyState(VK_TAB)){Name="���";PrintKey(0); return;}
			}
	} 
	}
	void DelCel(){
	Cel.erase(temp);
	Name="���";
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
					PrintCombat( val,"���");
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
								if(obj.Name=="���"){
								
								cout<<"������� ���� �������� ����!!!"<<endl;
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
