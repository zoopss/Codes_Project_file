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
  fout.write
