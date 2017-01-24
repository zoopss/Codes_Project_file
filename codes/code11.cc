#include<iostream>
 
using namespace std;
 
int main()
{
    int a[50],x,n,i,j,b[50];
    cout<<"How many elements do you want to create array with?(max. 50)....";
    cin>>n;
    cout<<"\nEnter Array elements...\n";
    
    for(i=0;i<n;++i)
        cin>>a[i];
    char ch='y';
    while(ch=='y'||ch =='Y')
    {
     cout<<"\nEnter element to be deleted:";
     cin>>x;
    
     for(i=0,j=0;i<n;++i)
     {
         if(a[i]!=x)
             b[j++]=a[i];
     }
     cout<<"Wnat to Delete more elements(y/n)?...";
     cin>>ch;
    }
     if(j==n)
     {
         cout<<"\nSoory!!!Element is not in the Array";
         exit(0);
     }
     else
     {
         cout<<"\nNew Array is ";
         for(i=0;i<j;i++)
             cout<<b[i]<<" ";
     }
 
     return 0;
   
}
