#include "stiveheader.h"





int main(int argc, char **argv)
{
    FILE *fi=fopen(argv[1],"r");
    FILE *fo=fopen(argv[2],"w");

    node *P1=NULL, *P2=NULL, *P3=NULL;
    char nume1[100], nume2[100], nume3[100];
    int x;
    queue *queue_final=creareQueue();
    int ok=0;

    //construiesc stivele(sa fac functii dupa)
    fscanf(fi,"%99s",nume1);
    while(fscanf(fi,"%d",&x)==1)
    push(&P1,x);

    fscanf(fi,"%99s",nume2);
    while(fscanf(fi,"%d",&x)==1)
    push(&P2,x);

    fscanf(fi,"%99s",nume3);
    while(fscanf(fi,"%d",&x)==1)
    push(&P3,x);
    int i=1;
    char buff[100];
    int diferenta;

    while((P1!=NULL&&P2!=NULL&&P3!=NULL)&&ok==0)
    {
        if(P1->val==P2->val)
        { //nota: voi face o functie cu queue_final,numele si stivele
            sprintf(buff,"ziua %d",i);
            enQueue(queue_final,buff);
            diferenta=abs(P1->val-P3->val);
            sprintf(buff,"%d",diferenta);
            enQueue(queue_final,buff);
            enQueue(queue_final,nume3);
            ok=1;
        }

        if(P1->val==P3->val)
        {   sprintf(buff,"ziua %d",i);
            enQueue(queue_final,buff);
            diferenta=abs(P1->val-P2->val);
            sprintf(buff,"%d",diferenta);
            enQueue(queue_final,buff);
            enQueue(queue_final,nume2);
            ok=1;
        }

        if(P2->val==P3->val)
        {   sprintf(buff,"ziua %d",i);
            enQueue(queue_final,buff);
            diferenta=abs(P3->val-P1->val);
            sprintf(buff,"%d",diferenta);
            enQueue(queue_final,buff);
            enQueue(queue_final,nume1);
            ok=1;
        }
        i++;

    }
    
    deleteQueue(queue_final,fo);





    return 0;
}