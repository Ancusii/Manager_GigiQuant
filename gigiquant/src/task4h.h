#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct fractie
{
    int numarator;
    int numitor;
};
typedef struct fractie fractie;

struct graf{
    int V;
    int E;
    fractie **a;
    int index_target,index_start;
};

typedef struct graf Graph;



void task4(const *cale_in,const *out);
Graph *citire_date(FILE *fi,int *K);