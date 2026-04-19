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

void buildPath(int *path, int directie, int *lenght);
treeNode *cautare_inversa(treeNode *root_initial,int *path,int lenght);
void parcurgere(treeNode *root,treeNode *root_initial,int *path,int *lenght,FILE *fo);
//stockList *citire_companie(int i,FILE *fi);
int depth(stockList *cap);
treeNode *newNode_cap(FILE *fi);
void construire_arbore(treeNode **root,int nr_companii,int max_zile);
void task3(const char *cale_in,const char *cale_out);