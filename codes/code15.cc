#include<iostream.h>
#include<fstream.h>
struct stu
{
  int rollno;
  char name[25];
  float marks;
  char grade;
  s1;
}
int main()
{
  int rn; char found = 'n';
  ifstream fin("stu.dat", ios::in);
  cout<<"Enter rollno to be searched for :";
  cin>>rn;
  while(!fin.eof())
  {
    fin.read((char*)&s1, sizeof(s1));
    if(s1.rollno == rn)
    {
      cout<<s1.name<<"rollno"<<rn<<"has"<<s1.marks<<"%marks and"<<s1.grade<<"grade"<<endl;
      found = 'y';
      break;
    }
  }
  if(found == 'n')
    cout<<"Rolno. not found in file!!!"<<endl;
  fin.close();
  return0;
}
