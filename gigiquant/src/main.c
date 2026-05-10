#include "task1h.h"
#include "task2h.h"
#include "task3h.h"



int main(int argc, char **argv)
{

    char *fisier_in=argv[1];
    //TASK1
    if(strstr(fisier_in,"data1.in")!=NULL||strstr(fisier_in,"data2.in")!=NULL||strstr(fisier_in,"data3.in")!=NULL||strstr(fisier_in,"data4.in")!=NULL||strstr(fisier_in,"data5.in")!=NULL)
    task1(argv[1],argv[2]);

    //TASK2
    else if(strstr(fisier_in,"data6.in")!=NULL||strstr(fisier_in,"data7.in")!=NULL||strstr(fisier_in,"data8.in")!=NULL||strstr(fisier_in,"data9.in")!=NULL||strstr(fisier_in,"data10.in")!=NULL)
    task2(argv[1],argv[2]);

    //TASK3
    else if(strstr(fisier_in,"data11.in")!=NULL||strstr(fisier_in,"data12.in")!=NULL||strstr(fisier_in,"data13.in")!=NULL||strstr(fisier_in,"data14.in")!=NULL||strstr(fisier_in,"data15.in")!=NULL)
    task3(argv[1],argv[2]);
    return 0;
}