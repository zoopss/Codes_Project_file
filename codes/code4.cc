#include<iostream.h>
#include<stdlib.h>
void amount(float princ, int time, float rate)                  //#1
{  cout<<"\nPrincipal Amount :"<<princ;
   cout<<"\tTime :"<<time<<"years";
   cout<<"\tRate"<<rate;
   cout<<"\nIntrest Amount :"<<(princ * time * rate)<<"\n";
}
void amount(float princ, int time)                              //#2
{   
   cout<<"\nPrincipal Amount :"<<princ;
   cout<<"\tTime :"<<time<<"years";
   cout<<"\tRate : 0.08";
   cout<<"\nIntrest Amount : "<(princ * time * 0.08)<<"\n";
}
void amount(float princ,float rate)                             //#3
{
   cout<<"\nPrincipal Amount :"<<princ;
   cout<<"\tTime :2 years";
   cout<<"\tRate"<<rate;
   cout<<"\nIntrest Amount :"<<(princ * 2 * rate)<<"\n";
}
void amount(int time, float rate)                                //#4
{
   cout<<"\nPrincipal Amount :2000";
   cout<<"\tTime :"<<time<<"Years";
   cout<<"\tRate"<<rate;
   cout<<"\nIntrest Amount :"<<(2000 * time * rate)<<"\n";
}
void amount(float princ)                                         //#5
{
   cout<<"\nPrincipal Amount :"<<princ;
   cout<<"\tTime :2 years";
   cout<<\tRate : 0.08";
   cout<<"\nIntrest Amount :"<<(princ * 2 * 0.08)<<"\n";
}
int main ()
{   system("cls");
    cout<<"Case 1";
      amount(2000.0F);
    cout<<"Case 2";
      amount(2500.0F, 3);
    cout<<"Case 3";
      amount(2300.0F,3,0.11F);
    cout<<"Case 4";
      amount(2, 0.12F);
    cout<<"Case 5";
      amount(6, 0.07F);
    return 0;
}
