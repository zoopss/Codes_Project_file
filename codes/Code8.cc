#include<iostream.h>
#include<process.h>
struct Node      {
                              int info;
 	              Node * next ;
                         }    *start, *newptr, *save, *ptr ;
Node * Create_New_Node( int );
void Insert_Beg( Node*b);
void Display( Node*);

int main()
{
     start = NULL;
     int inf; char ch = 'y';
     while (ch == 'y' | | ch == 'Y')
     {
       system(" cls ");
       cout<<"\nEnter information for the new node...";
       cin>> inf;
       cout<<"\nCreating New Node! Press Enter to contineu...";
       system("pause");
       newptr = Create_New_Node(inf);
       if (newptr != NULL)
       {
           cout<<"\n\nNew Node created Successfully. Pres  enter ro contineu.....";
           system("pause");
       }
       else 
       {
           cout
