#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct nod{
    double val;
    double randament;
    struct nod *next;
};

typedef struct nod nod;


void creare_lista(nod **node,int n, FILE *fi);
double calcul_zecimale(double x);
void eliberare_lista(nod **cap);
double rand_mediu(nod *cap);
double calcul_volatilitate(nod *cap,double randament_mediu);