#include<iostream>
 
using namespace std;
 
int main()
{
    int a[50],n,x,i,pos=0;
    cout<<"How many elements do you want to create array with(Max. 50)....";
    cin>>n;
    cout<<"Enter the array elements(Must be sorted in ascending order)\n";
    
    for(i=0;i<n;++i)
        cin>>a[i];
    char ch = 'y';
    while(ch =='y'||ch =='Y')
    {  cout<<"\nEnter element to be inserted...";
       cin>>x;
     
       for(i=0;i<n;++i)
           if(a[i]<=x&&x<a[i+1])
           {
               pos=i+1;
               break;
           }          
                    
       for(i=n+1;i>pos;--i)
               a[i]=a[i-1];
        
       a[pos]=x;
       cout<<"Want to insert more element? (y/n)...";
       cin>>ch;
    }
    
    cout<<"\n\n The Array is now as shown below...\n";
    
    for(i=0;i<n+1;i++)
        cout<<a[i]<<" ";
 
    return 0;
}
