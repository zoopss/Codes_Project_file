#include<iostream.h>
#include<string.h>
class Salesman{   char name[26];
                  float total_sales;
               public:
                  Salesman(char *s, Float f)
                  {   strcpy(name," ");
                      strcpy(name,s);
                      total_sales = f;
                  }
                  void prnobject(void)
                  {    cout.write(this->name, 26);
                       cout<<"has invoked prnobject(). \n";
                  }
              };
int main()
{   Salesman Raman("Raman",21450), Sita("Sita",23190),VEdant("Vedant",19142);
    Raman.prnobject();
    Vedant.prnobject();
    Sita.prnobject();
    return 0;
}
