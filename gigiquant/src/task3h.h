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
}; 

typedef struct stockList stockList;

struct treeNode
{
    stockList **stocks; //vector, adica in el am mai multe companii
    struct treeNode *left, *right;
    int companii; //numarul de companii
    int depth; //inaltimea nodului(sau pe ce nivel se afla)
};

typedef struct treeNode treeNode;

struct ordonare_elemente
{
    int index1, index2;
    stockList *stock1,*stock2;
};

typedef struct ordonare_elemente ordonare_elemente;


void buildPath(int *path, int directie, int *lenght);
treeNode *cautare_inversa(treeNode *root_initial,const int *path,int lenght);
void parcurgere(treeNode *root,treeNode *root_initial,int *path,int *lenght,ordonare_elemente el[],int *nr_perechi);
int depth(stockList *cap);
treeNode *newNode_cap(FILE *fi);
void construire_arbore(treeNode **root,int nr_companii,int max_zile);
void task3(const char *cale_in,const char *cale_out);
void stergere_liste(treeNode *root);
void stergere_arbore(treeNode **root);