#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct nod{
    double val;
    double randament;
    struct nod *next;
};

typedef struct nod nod;

void creare_lista(int **node,int n);
double calcul_zecimale(double x);
void eliberare_lista(node **cap);