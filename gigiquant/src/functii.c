#include "task1h.h"

double calcul_zecimale(double x)
{
    x=int(x*1000)/1000;
 
 return x;
}

void creare_lista(int **node,int n)
{

    nod *q;
      for(int i=2;i<=n;i++)
    {
        q=(nod*)malloc(sizeof(nod));
        fscanf(fi,"%lf",&q->val);
        q->randament=((q->val-(*node)->val)/(*node)->val);

        randament_mediu+=q->randament;

        (*node)->next=q;
        q->next=NULL;
        (*node)=q;

    }


}

void eliberare_lista(node **cap)
{
    node *temp;
    while(*cap!=NULL)
    {
        temp=(*cap)->next;
        free(*cap);
        *cap=temp;
    }
    *cap=NULL;

}

