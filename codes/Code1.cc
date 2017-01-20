# include <iostream.h>
# include <process.h>
# include <conio.h>
int display_menu();
class circularqueue
{
  int arr[10];
  int front,rear;
  int size;
  public:
     circularqueue()
     {
      front=0;
      rear=0;
      size=10;
     }
     void display();
     void enqueue();
     void delete_element();
};

void circularqueue :: display()
{
 cout<<endl;
 if(front!=0 && rear!=0)
 {
        int i=front;
        cout<<"arr["<<i<<"] :"<<arr[i]<<endl;
        while(i!=rear)
        {
         i=(i % size)+1;
         cout<<"arr["<<i<<"] :"<<arr[i]<<endl;
        }

 }
 else
 {
    cout<<"Queue is empty"<<endl;
 }
 getch();
}

void circularqueue :: enqueue()
{
 cout<<endl;
 if(front==0 && rear==0)
 {
  cout<<"Enter Number to enqueue at Position arr["<<rear+1<<"] :";
  cin>>arr[1];
  rear=1;
  front=1;
 }
 else
 {
  int next=(rear % size)+1;






  if(next==front)
  {
   cout<<"Queue is Full ...";
   getch();
  }
  else
  {
   cout<<"Enter Number to enqueue at Position arr["<<next<<"] :";
   cin>>arr[next];
   rear=next;
  }
 }
}

void  circularqueue :: delete_element()
{
 cout<<endl;
 if(rear==0 && front==0)
 {
   cout<<"Queue is empty ...";
   getch();
   return;
 }


 if(rear==front)
 {
  rear=0;
  front=0;
 }
 else
 {
  front=(front % size)+1;
 }
}
void main()
{
 circularqueue cq1;
 while(1)
 {
  switch(display_menu())
  {
    case 1: cq1.enqueue();
        break;
    case 2: cq1.delete_element();
        break;
    case 3: cq1.display();
        break;
    case 4: exit(1);
  }
 }
}
int display_menu()
{
 int c;
 clrscr();
 cout<<endl;
 cout<<"| 1  : Enqueue element"<<endl;
 cout<<"| 2 | : Delete element"<<endl;
 cout<<"| 3 | : Display"<<endl;
 cout<<"| 4 | : Exit"<<endl;
 cout<<"Enter your Choice :";
 cin>>c;
 return c;
}
