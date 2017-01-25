#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
struct customer
{
  char name[51];
  float balance;
};
int main()
{
  System("cls");
  customer savac;
  strcpy(savac.name, "Tina Marshal");
  savac.balance = 21310.75;
  ofstream fout;
  fout.open("Saving", ios :: out|ios::binary);
  if(!fout)
  {
    cout<<"File cant be opened \n";
    return 1;
  }
  fout.write((char*)& savac, sizedof(customer));
  fout.close()
  ifstream fin;
  fin.open("Saving",ios::in|ios::binary);
  fin.read((char*)& savac, sizedof(customer));
  cout<<savac.name;
  cout<<"has the balance amount of Rss. "<<savac.balance<<"\n";
  fin.close();
  return ;
}
