#include<iostream.h>
#include<stdlib.h>
class Deposit
{
  long int principal;
  int time;
  float rate;
  float total_amt;
public:
  Deposit();
  Deposit(long p, int t, float r);
  Deposit(long p, int t);
  Deposit(long p, float r);
  void calc_amt(void);
  void display(void);
}
Deposit::Deposit()
{ principal = time = rate = 0.0; }
Deposit::Deposit(long p, int t, float r)
{ principal = p; time = t; rate = r; }
Deposit::Deposit(long p, int t)
{ principal = p; time = t; rate = 0.08; }
Deposit::Deposit(long p, float r)
{ principal = p; time = 2; rate = r; }
void Deposit::calc_amt(void)
{      total_amt = principal + (principal * time * rate)/100;
}
void Deposit::calc_amt(void)
{      cout<<"\nPrincipal Amount : Rs"<<principal;
       cout<<"\tPeriod of investment :"<<time<<"years";
       cout<<"\nRate of intrest :"<<rate;
       cout<<"\tTotal Amount : Rs."<<total_amt<<"\n";
}
int main()
{
  system("cls");
  Deposit D1, D2(2000,2,0.7f),D3(4000,1),D4(3000,0.12f);
  D1.calc_amt();
  D2.calc_amt();
  D3.calc_amt();
  D4.calc_amt();
  cout<<"Object 1\n"; D1.display();
  cout<<"Object 2\n"; D2.display();
  cout<<"Object 3\n"; D3.display();
  cout<<"Object 4\n"; D4.display();
  return 0;
}
