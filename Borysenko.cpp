#include<iostream>
#include<Windows.h>
#include<conio.h>
#include <io.h>
#include <stdio.h>
#include <direct.h>
#include <time.h>
using namespace std;

char string1[40] = "ввести директорию";
char string2[40] = "ввести путь";
char string3[40] = "Вывести на экран";

HANDLE hConsole;

void PrintKey(int val)
{
	
	system("cls");
	val == 0 ? cout << "->" << string1 : cout <<"  "<< string1;
	cout << endl;
	val == 1 ? cout << "->" << string2 : cout << "  "<<string2;
	cout << endl;
	val == 2? cout << "->" << string3 : cout << "  "<<string3;
	cout << endl<< endl;
	
	
	cout<<"  To exit, press [Esc]"<<endl;
	cout<<"Для активации выбраного пункта меню нажми [SPACE]"<<endl;
	cout<<endl<<"!!!!!Внимание!!!! После выбора [Вывести на экран] просто нажмите любую стрелку. Это глюк от которого не могу избавиться!"<<endl;
}
struct Men{
public:
char nam[MAX_PATH];
};
class Sgil{
public:
	char dir[20];
	char put[60];
	char polput[260];
	char polput1[260];
	char temp[260];
    _fsize_t  tempS;
	time_t  tempT;
	int count;
	Men *meny;
	int diskr;
	Sgil(){
	strcpy(dir,"d:\\");
	strcpy(put,".");
     count=0;
	}
void Dir(){

cout<<"Введите директорию "<<endl;
cin>>dir;
//AnsiToOem(dir,dir);
strcat(dir,":\\");
}

void Put(){
	char Name[60];
	cout<<"Введите путь"<<endl;
	cin>>Name;
	
	strcpy(put,Name);

}




void monualMeny(){

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((1 << 4) | 10));
	
	cout << endl;
	char pressKey = '\0';
	int keyInd = 0;
	int keyVal = 0;
	int val=0;
	PrintmonualMeny( val);
	while (pressKey != '\r'){
		if (kbhit())
		{
			keyInd = getch();
			if (keyInd == 224)
			{ 
				keyVal = getch();
			
				keyVal==80?val++:val--;
				if(val<0)val=count-1;
				if(val>=count)val=0;
				
				 PrintmonualMeny(val);
					
			
			}
			if(GetAsyncKeyState(VK_SPACE)){
				if(diskr==1){
				struct tm *ptr;
				ptr=localtime(&tempT);
				cout<<"***************************"<<endl;
				cout<<"Размер файла "<<tempS<<"байт"<<endl;
				cout<<"Время создания "<<asctime(ptr)<<endl;
				cout<<"***************************"<<endl;
				}
				else { strcat(polput1,"\\");
				strcat(polput1,temp);
			    strcpy(polput,polput1);
				cout<<polput<<endl;Sleep(200);
				Showsize();
				 PrintmonualMeny(0);
				}
	
				
			
			}
			if(GetAsyncKeyState(VK_TAB)){
			    strcat(polput1,"\\");
				strcat(polput1,"..");
				strcpy(polput,polput1);
				cout<<polput;Sleep(200);
				Showsize();
				PrintmonualMeny(0);
			}
		
		if(GetAsyncKeyState(VK_ESCAPE)){
			PrintKey(0);	break;
	}

		}
	}
	PrintKey(0);
}


void Showsize(int ch=0){
	// определяет размер текущей директории
	
	
	if(ch==1){
	char path[MAX_PATH];
	strcpy(path,dir);
	strcat(path,put);
	strcpy(polput,path);
	}
	    strcpy(polput1,polput);
		strcat(polput,"\\*.*");
		/*AnsiToOem(polput,polput);*/
	count=0;
	_finddata_t *file_info = new _finddata_t;
	long done = _findfirst(polput, file_info);

	int go = done;
	if (go==-1) {
		
		cout<<"нет такой директории"<<endl;return;}
	
	while (go != -1) {
		/*AnsiToOem(file_info->name, file_info->name);*/// для файлов с русскими именами
	
	
	if(strcmp(file_info->name,".")){
		cout << file_info->name << endl;
		count++;
	}
		go = _findnext(done, file_info);
	}
	
	_findclose(done);
     delete file_info;
	
	

}
void PrintmonualMeny(int val){
	
	cout<<polput<<endl;
	int i=0;
	_finddata_t *file_info = new _finddata_t;
	long done = _findfirst(polput, file_info);

	int go = done;
	if (go==-1) {
		
		cout<<"нет такой директории, нажмите ESC"<<endl;return;}
	
	system("cls");
	while (go != -1) {
		/*AnsiToOem(file_info->name, file_info->name);*/// для файлов с русскими именами
		if(strcmp(file_info->name,".")){
		if(val==i) {
			cout << "->" << file_info->name;
			strcpy(temp,file_info->name);
			if(file_info->attrib&_A_SUBDIR){cout<<"...................... Каталог "; diskr=0;}
			else{ cout<<"................. Файл ";
			diskr=1;
			tempS=file_info->size;
			tempT=file_info->time_create;
			
			}
		}
		else cout <<"  "<<file_info->name;
	cout << endl;
	i++;
		}
		go = _findnext(done, file_info);
		
	}
	cout<<endl<<"для возврата в директорию нажмит [TAB]"<<endl;
	cout<<"Для активации выбраного пункта меню нажми [SPACE]"<<endl;
	cout<<"  To exit, press [Esc]"<<endl;
	_findclose(done);
     delete file_info;
	
	}
};



	void main(){
	setlocale (LC_ALL,"Russian");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((1 << 4) | 10));
	Sgil f;
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
					{f.Dir();
					break;}
				case 1 :	
					{f.Put();
					
					break;}
				case 2:
				{	/*f.Show();*/
                 
					f.Showsize(1);
				
					f.monualMeny();
					f.PrintmonualMeny(0);
					
					break;}
				/*default: break;*/
					}
				continue;
			}
		
		if(GetAsyncKeyState(VK_ESCAPE)){
				break;
	}
		
		}
	}
	
	/*PrintKey(0);*/
	}