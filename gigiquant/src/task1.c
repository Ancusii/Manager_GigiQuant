#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct nod{
    double val;
    double randament;
    struct nod *next;
};

typedef struct nod nod;


int main(int argc, char *argv[])
{
    FILE *fi=fopen(argv[1],"r");
    FILE *fo=fopen(argv[2],"w");

    nod *cap=NULL, *p, *q;
    double randament_mediu=0;
    double volatil=0;
    double sharpe_ratio;
   // double sum=0;
    int n; //numarul total de observatii
    
    fscanf(fi,"%d",&n);

    cap=(nod*)malloc(sizeof(nod));
    fscanf(fi,"%lf",&cap->val);
    //cap->randament=0;
    p=cap;
    p->next=NULL;

    for(int i=2;i<=n;i++)
    {
        q=(nod*)malloc(sizeof(nod));
        fscanf(fi,"%lf",&q->val);
        q->randament=((q->val-p->val)/p->val);

        randament_mediu+=q->randament;

        p->next=q;
        q->next=NULL;
        p=q;

    }

    randament_mediu/=(n-1);

    for(p=cap->next;p!=NULL;p=p->next)
    {
        volatil+=pow(p->randament-randament_mediu,2);
    }
    volatil/=(n-1);
    volatil=sqrt(volatil);

    sharpe_ratio=randament_mediu/volatil;
    randament_mediu=(int)(randament_mediu*1000)/1000.;
    volatil=(int)(volatil*1000)/1000.;
    sharpe_ratio=(int)(sharpe_ratio*1000)/1000.;
    
    fprintf(fo,"%.3lf\n",randament_mediu);
    fprintf(fo,"%.3lf\n",volatil);
    fprintf(fo,"%.3lf\n",sharpe_ratio);

    fclose(fi); fclose(fo);
return 0;

   



}