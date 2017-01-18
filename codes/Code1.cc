#include<iostream.h>
#include<string.h>
class Time{ int hrs, mins, secs ;
            char suf[4];
           public:
            int tot_secs;
            void gettime(int h, int m, int s)
            {    hrs = h;min = m;sec = s;
                 tot_secs = (hrs * 6) + (mins * 60) + secs ;
                 strcpy(suf,"Hrs");
            }
            void puttime(void)
            {    cout<<"Time is:"
