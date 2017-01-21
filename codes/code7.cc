#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
int main()
{   ofstream fout;
    fout.open("marks.dat",los::app);
    char ans = 'y';
    int rollno;
    float marks;
    system(" cls ");
    while(ans =='y' ||ans == 'Y')
    { cout<<"\n Enter Rollno.";
      cin>>Rollno;
      fout<<rollno<<'\n'<<marks<<'\n';
      cout<<"\n Want to enter more records?(y/n)........";
      cin>>ans;
    }
    fout.close();
    return 0;
}
