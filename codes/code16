#include<iostream.h>
#include<process.h>
struct Node    {
                  int info;
 	                Node * next ;
               }  *start, *newptr, *save, *ptr ;
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
           cout<<"\n\nNew Node created Successfully. Pres  enter to contineu.....";
           system("pause");
       }
       else 
       {
           cout<<"\nCAnnot create new new node!!! Aborting!!\n";
           system("paused");
           exit(1);
       }
       cout<<"\n\nNow inserting this node in the begning of list ...\n";
       cout<<"Press  enter to contineu...\n";
       system("pause");
       Insert_Beg(newptr);
       cout<<"\nNow the list is :\n";
       Display(start);
       cout<<"\n Press Y to enter more nodes, N to exit....\n";
       cin>>ch;
     }
     Node * Create_New_Node( int n)
     {ptr = new Node;
      ptr -> info = n;
      ptr -> next = NULL;
      return ptr;
     }
     Void Insert_Beg(Node*np)
     {  if (start == NUll)
           start = np;
        else
        { save= start;
          start= np;
          np -> next = save ;
        }
     }
     Void Display(NOde*np)
     {  while(np != NULL)
        {  cout<< np -> info<<"->";
           np = np -> next ;
        }
        cout<< "!!!\n";
     }
