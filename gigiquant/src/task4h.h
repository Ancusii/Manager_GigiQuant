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
};

typedef struct graf Graph;



void task4(char *cale_in,char *out);