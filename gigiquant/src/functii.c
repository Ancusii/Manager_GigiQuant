#include "task1h.h"

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

