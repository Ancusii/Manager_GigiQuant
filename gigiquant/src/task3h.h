#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>

struct stockList
{
    char nume[5];
    int index;
    double valoare;
    struct stockList *next;
}; //asta e o lista, cred ca trebuie implementata pe heap

typedef struct stockList stockList;

struct treeNode
{
    stockList **stocks; //vector, adica in el am mai multe companii
    struct treeNode *left, *right;
    int companii;
    int depth; //inaltimea nodului(sau pe ce nivel se afla)
};

typedef struct treeNode treeNode;