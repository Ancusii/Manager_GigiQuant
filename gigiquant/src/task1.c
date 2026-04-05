#include "task1h.h"



int main(int argc, char **argv)
{
    FILE *fi=fopen(argv[1],"r");
    FILE *fo=fopen(argv[2],"w");

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
return 0;



}