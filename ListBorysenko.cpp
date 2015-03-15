#include <iostream>
using namespace std;
 

struct Element
{
   
   int data;
   
   Element * Next;
};


class List
{
   
   Element * Head;
   
   Element * Tail;
  
   int Count;

public:
  
   List();
   // ����������
   ~List();
	
   // ���������� �������� � ������
   // (����� ������� ���������� ���������)
   void Add(int data);
   void AddHead(int data); 
   void AddPos(int pos);
	
   // �������� �������� ������
   // (��������� �������� �������)
   void Del();
   // �������� ����� ������
   void DelAll();
	 
   void DelPos(int pos);
   // ���������� ����������� ������
   // (���������� ���������� � ��������� ��������)
   void Print();
	
   int Wonted(int Data);
   // ��������� ���������� ���������, ����������� � ������
   int GetCount();
};

List::List()
{
   // ���������� ������ ����
   Head = Tail = NULL;   
   Count = 0;
}

List::~List()
{
   // ����� ������� ��������
   DelAll();
}

int List::GetCount()
{
   // ���������� ���������� ���������
   return Count;
}

void List::Add(int data)
{
   // �������� ������ ��������
   Element * temp = new Element;

   // ���������� �������
   temp->data = data;
   // ��������� ������� �����������
   temp->Next = NULL;
   // ����� ������� ���������� ��������� ��������� ������
   // ���� �� �� ������ �����������
   if(Head!=NULL){
		Tail->Next=temp;
		Tail = temp;
   }
   // ����� ������� ���������� ������������
   // ���� �� ������ �����������
   else{
	   Head=Tail=temp;
   }
   Count++;
}
void List::AddHead(int n)
{
   // ����� �������
   Element * temp = new Element;

   
   // ��������� ������
   temp->data = n;
   // ��������� - ������ ������
   temp->Next = Head;
   if(Count == 0)
      Head = Tail = temp;
   else
      // ����� ����� ������� - ��������
      Head = temp;

   Count++;


}
void List::AddPos(int pos){
 if(pos == 0)
   {
      cout << "Input position: ";
      cin >> pos;
   }
 if(pos < 1 || pos > Count + 1)
   {
      // �������� �������
      cout << "Incorrect position !!!\n";
      return;
   }
  if(pos == Count + 1)
   {
      // ����������� ������
      int data;
      cout << "Input new number: ";
      cin >> data;
      // ���������� � ����� ������
      Add(data);
      return;
   }
   else if(pos == 1)
   {
      // ����������� ������
      int data;
      cout << "Input new number: ";
      cin >> data;
      // ���������� � ������ ������
      AddHead(data);
      return;
   }
  int i = 1;

   // ����������� �� ������ n - 1 ���������
   Element * Ins = Head;

   while(i < pos-1)
   {
      // ������� �� ��������, 
      // ����� ������� �����������
      Ins = Ins->Next;
      i++;
   }
 Element * temp = new Element;

   // ������ ������
   cout << "Input new number: ";
   cin >> temp->data;
   
   temp->Next=Ins->Next;
   Ins->Next=temp;
   Count++;
}


void List::Del()
{
   // ���������� ����� ��������� ��������
   Element * temp = Head;
   // ������������� ������ �� ��������� �������
   Head = Head->Next;
   // ������� ������ �������� �������
   delete temp;
   Count--;
}
void List::DelPos(int pos)
{
// ���� �������� ����������� ��� ����� 0, �� ����������� ���
   if(pos == 0)
   {
       cout << "Input position: ";
       cin >> pos;
   }
   // ������� �� 1 �� Count?
   if(pos < 1 || pos > Count)
   {
      // �������� �������
      cout << "Incorrect position !!!\n";
      return;
   }
   if(pos==1){
	   Del();
	  return;
   }
	    int i = 1;

   Element * Del = Head;

   while(i < pos)
   {
      // ������� �� ��������, 
      // ������� ���������
      Del = Del->Next;
      i++;
   }
   i = 1;

   Element * temp = Head;

   while(i < pos-1)
   {
      // ������� �� ��������, 
      // ����� ������� ���������
      temp = temp->Next;
      i++;
   }
   temp->Next=Del->Next;
     if(pos == Count)
       Tail = temp;

   // �������� ��������
   delete Del;

   Count--;

}

void List::DelAll()
{
   // ���� ��� ���� ��������
   while(Head != 0)
      // ������� �������� �� ������
      Del();
   Count=0;
}

void List::Print()
{
   // ���������� ����� ��������� ��������
   Element * temp = Head;
   // ���� ��� ���� ��������
   while(temp != 0)
   {
      // ������� ������
      cout << temp->data << " ";
      // ��������� �� ��������� �������
      temp = temp->Next;
   }

   cout << "\n\n";
}
int List::Wonted(int Date){
	int i = 1;

   Element * temp = Head;
    while(i < Count+1)
   {
	   if(temp->data==Date)return i;
      // ������� �� ��������, 
      // ������� ���������
      temp = temp->Next;
      i++;
   }
	return NULL;
}

// �������� ������
void main()
{
   setlocale (LC_ALL,"Russian");
   // ������� ������ ������ List
   List Lst;
   int date;
   int pos;
  cout<<"������� � ������. 0-EXIT"<<endl;
  for(;;){
	  cin>>date;
	  if(date==0)break;
      Lst.Add(date);
  }
   // ������������� ���������� ������
   Lst.Print();
  cout<<"������� �����  ������� ��� ���������� � ������"<<endl;
  cin>>pos;
  Lst.AddPos(pos);
   Lst.Print();
   cout<<"������� ������� ��� ��������"<<endl;
   cin>>pos;
   Lst.DelPos(pos);
   Lst.Print();
   cout<<"������ �������� ��� ������"<<endl;
   cin>>date;
   if(Lst.Wonted(date)==0){
   cout<<" ��� ����� �������� � ������!"<<endl;
   }
   else cout<<"�������� ��������� �� �������  "<<Lst.Wonted(date)<<endl;
}

