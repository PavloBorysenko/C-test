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
   // Деструктор
   ~List();
	
   // Добавление элемента в список
   // (Новый элемент становится последним)
   void Add(int data);
   void AddHead(int data); 
   void AddPos(int pos);
	
   // Удаление элемента списка
   // (Удаляется головной элемент)
   void Del();
   // Удаление всего списка
   void DelAll();
	 
   void DelPos(int pos);
   // Распечатка содержимого списка
   // (Распечатка начинается с головного элемента)
   void Print();
	
   int Wonted(int Data);
   // Получение количества элементов, находящихся в списке
   int GetCount();
};

List::List()
{
   // Изначально список пуст
   Head = Tail = NULL;   
   Count = 0;
}

List::~List()
{
   // Вызов функции удаления
   DelAll();
}

int List::GetCount()
{
   // Возвращаем количество элементов
   return Count;
}

void List::Add(int data)
{
   // создание нового элемента
   Element * temp = new Element;

   // заполнение данными
   temp->data = data;
   // следующий элемент отсутствует
   temp->Next = NULL;
   // новый элемент становится последним элементом списка
   // если он не первый добавленный
   if(Head!=NULL){
		Tail->Next=temp;
		Tail = temp;
   }
   // новый элемент становится единственным
   // если он первый добавленный
   else{
	   Head=Tail=temp;
   }
   Count++;
}
void List::AddHead(int n)
{
   // новый элемент
   Element * temp = new Element;

   
   // Заполняем данные
   temp->data = n;
   // Следующий - бывшая голова
   temp->Next = Head;
   if(Count == 0)
      Head = Tail = temp;
   else
      // иначе новый элемент - головной
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
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return;
   }
  if(pos == Count + 1)
   {
      // Вставляемые данные
      int data;
      cout << "Input new number: ";
      cin >> data;
      // Добавление в конец списка
      Add(data);
      return;
   }
   else if(pos == 1)
   {
      // Вставляемые данные
      int data;
      cout << "Input new number: ";
      cin >> data;
      // Добавление в начало списка
      AddHead(data);
      return;
   }
  int i = 1;

   // Отсчитываем от головы n - 1 элементов
   Element * Ins = Head;

   while(i < pos-1)
   {
      // Доходим до элемента, 
      // перед которым вставляемся
      Ins = Ins->Next;
      i++;
   }
 Element * temp = new Element;

   // Вводим данные
   cout << "Input new number: ";
   cin >> temp->data;
   
   temp->Next=Ins->Next;
   Ins->Next=temp;
   Count++;
}


void List::Del()
{
   // запоминаем адрес головного элемента
   Element * temp = Head;
   // перебрасываем голову на следующий элемент
   Head = Head->Next;
   // удаляем бывший головной элемент
   delete temp;
   Count--;
}
void List::DelPos(int pos)
{
// если параметр отсутствует или равен 0, то запрашиваем его
   if(pos == 0)
   {
       cout << "Input position: ";
       cin >> pos;
   }
   // Позиция от 1 до Count?
   if(pos < 1 || pos > Count)
   {
      // Неверная позиция
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
      // Доходим до элемента, 
      // который удаляется
      Del = Del->Next;
      i++;
   }
   i = 1;

   Element * temp = Head;

   while(i < pos-1)
   {
      // Доходим до элемента, 
      // перед которым удаляется
      temp = temp->Next;
      i++;
   }
   temp->Next=Del->Next;
     if(pos == Count)
       Tail = temp;

   // Удаление элемента
   delete Del;

   Count--;

}

void List::DelAll()
{
   // Пока еще есть элементы
   while(Head != 0)
      // Удаляем элементы по одному
      Del();
   Count=0;
}

void List::Print()
{
   // запоминаем адрес головного элемента
   Element * temp = Head;
   // Пока еще есть элементы
   while(temp != 0)
   {
      // Выводим данные
      cout << temp->data << " ";
      // Переходим на следующий элемент
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
      // Доходим до элемента, 
      // который удаляется
      temp = temp->Next;
      i++;
   }
	return NULL;
}

// Тестовый пример
void main()
{
   setlocale (LC_ALL,"Russian");
   // Создаем объект класса List
   List Lst;
   int date;
   int pos;
  cout<<"Добавте в список. 0-EXIT"<<endl;
  for(;;){
	  cin>>date;
	  if(date==0)break;
      Lst.Add(date);
  }
   // Распечатываем содержимое списка
   Lst.Print();
  cout<<"Введите номер  позиции для добавления в список"<<endl;
  cin>>pos;
  Lst.AddPos(pos);
   Lst.Print();
   cout<<"Введите позицию для удаления"<<endl;
   cin>>pos;
   Lst.DelPos(pos);
   Lst.Print();
   cout<<"Ведите значение для поиска"<<endl;
   cin>>date;
   if(Lst.Wonted(date)==0){
   cout<<" Нет таких значений в списке!"<<endl;
   }
   else cout<<"Значение находится на позиции  "<<Lst.Wonted(date)<<endl;
}

