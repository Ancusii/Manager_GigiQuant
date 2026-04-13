#include "task1h.h"

void task1(const char *cale_in, const char *cale_out )
{
    FILE *fi=fopen(cale_in,"r");
    FILE *fo=fopen(cale_out,"w");

         nod *cap=NULL, *p;
    double randament_mediu;
    double volatil=0;
    double sharpe_ratio;
    int n; //numarul total de observatii
    
    fscanf(fi,"%d",&n);

    cap=(nod*)malloc(sizeof(nod));
    fscanf(fi,"%lf",&cap->val);

    p=cap;
    p->next=NULL;

    creare_lista(&p,n,fi);

    //calcul randament_mediu;
    randament_mediu=rand_mediu(cap);
    randament_mediu/=(n-1);

    //calcul volatilitate
    volatil=calcul_volatilitate(cap,randament_mediu);
    volatil/=(n-1);
    volatil=sqrt(volatil);

    sharpe_ratio=randament_mediu/volatil;

   randament_mediu=calcul_zecimale(randament_mediu);   
   volatil=calcul_zecimale(volatil);
   sharpe_ratio=calcul_zecimale(sharpe_ratio);      

    fprintf(fo,"%.3lf\n",randament_mediu);
    fprintf(fo,"%.3lf\n",volatil);
    fprintf(fo,"%.3lf\n",sharpe_ratio);

    eliberare_lista(&cap);
    fclose(fi); fclose(fo);
}

double calcul_zecimale(double x)
{
    x=(int)(x*1000)/1000.0;
 
 return x;
}

void creare_lista(nod **node,int n,FILE *fi)
{

    nod *q;
      for(int i=2;i<=n;i++)
    {
        q=(nod*)malloc(sizeof(nod));
        fscanf(fi,"%lf",&q->val);
        q->randament=((q->val-(*node)->val)/(*node)->val);


        (*node)->next=q;
        q->next=NULL;
        (*node)=q;

    }


}

double rand_mediu(nod *cap)
{
    nod *node;
    double randament_mediu=0;
    for(node=cap->next;node!=NULL;node=node->next)
    {
       randament_mediu+=node->randament;
    }

    return randament_mediu;
}

double calcul_volatilitate(nod *cap,double randament_mediu)
{
    double volatil=0;
    nod *node;
    for(node=cap->next;node!=NULL;node=node->next)
    {
        volatil+=pow(node->randament-randament_mediu,2);
    }

    return volatil;

}

void eliberare_lista(nod **cap)
{
    nod *temp;
    while(*cap!=NULL)
    {
        temp=(*cap)->next;
        free(*cap);
        *cap=temp;
    }
    *cap=NULL;

}

