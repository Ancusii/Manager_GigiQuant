#include "task3h.h"

void buildPath(int *path, int directie, int *lenght)
{
    path[(*lenght)++]=directie;
}

void removeFromPath(int *path, int *lenght)
{
    (*lenght)--;

}

void parcurgere(treeNode *root,treeNode *root_initial,int *path,int *lenght)
{
    if(root==NULL)
    return;

    if(root->left==NULL&&root->right==NULL) //adica am ajuns la frunza
    {
        //parcurg pe cealalta cale
        treeNode *nod_cautat=cautare_inversa(root_initial,path,&lenght);

        return;
    }

    if(root->left!=NULL)
    {
    buildPath(path,0,lenght);
    parcurgere(root->left,root_initial,path,lenght);
    removeFromPath(path,lenght);
    }

    else if(root->right!=NULL)
    {
        buildPath(path,1,lenght);
        parcurgere(root->right,root_initial,path,lenght);
        removeFromPath(path,lenght);
    }
    

    
}

treeNode *cautare_inversa(treeNode *root_initial,int *path,int lenght)
{
    for(int i=0;i<lenght;i++)
    {
        if(path[i]==0) //adica sunt pe stanga
        root_initial=root_initial->right;
        else
        {
            root_initial=root_initial->left;
        }
        
    }
    return root_initial;
}

//s-ar putea sa nu am nevoie de index
stockList *citire_companie(int i,FILE *fi) //i este indexul
{
   // double dif;
    stockList *stock, *stock_next,*cap;
    stock=(stockList*)malloc(sizeof(stockList));
    gets(stock->nume);
   stock->index=i;
    scanf("%lf",&stock->valoare);
    cap=stock;
    cap->next=NULL;
    while(fscanf(fi,"%lf",&stock->valoare)==1)
    {
        stock_next=(stockList*)malloc(sizeof(stockList));
    strcpy(stock_next->nume,cap->nume);
    stock->index=i;
    scanf("%lf",&stock_next->valoare);
    stock_next->next=NULL;
    stock=stock_next;
    }

    return cap;
}

int depth(stockList *cap)
{
    int dep=0;
    while(cap!=NULL)
    {
        dep++;
        cap=cap->next;
    }
return dep;
}

treeNode *newNode_cap(FILE *fi)
{
    
    treeNode *new=(treeNode*)malloc(sizeof(treeNode));
    int index=0;
    while(feof(fi)==NULL) //voi modifica eu ulterior
    {   new->stocks[index]=citire_companie(index,fi);
        index++;
    }
    new->left=NULL;
    new->right=NULL;
    new->companii=index;
    new->depth=0; //pointer catre cap
    return new;
}

//functia asta o apelez in main pe nodul cap creat
void construire_arbore(treeNode **root,int nr_companii)
{
//pot sa ma duc pe stanga si dreapta recursiv pana nu mai am zile in lista, adica stocks->next==NULL
//si asa si construiesc nodurile din copac
if(*root==NULL)
return;


//idee: vad cate companii am pe stanga si cate companii am pe dreapta
//dupa aceea ii pun in vectori de stanga si dreapta
//dupa aia construiesc nodul din stanga si dupa pe cel din dreapta dupa lista
//dupa aia apelez recursiv

int companii_stanga=0, companii_dreapta=0;

stockList **vec_comp_st,**vec_comp_dr; //vectori de liste

int st=0,dr=0;

vec_comp_st=(stockList*)malloc(sizeof(nr_companii*sizeof(stockList))); //vector de liste
vec_comp_dr=(stockList*)malloc(sizeof(nr_companii*sizeof(stockList)));

for(int i=0;i<nr_companii;i++)
{
    double dif=0;
    //nodul meu de start are depth=0;
    //fac un auxiliar aux stocks;
    stockList *aux=&((*root)->stocks[i]);
    for(int j=0;j<depth;j++)
    aux=aux->next;

    if(aux!=NULL&&aux->next!=NULL)
    dif=aux->next->valoare-aux->valoare;

    if(dif<0) //sunt pe stanga
    {companii_stanga++;
    vec_comp_st[st++]=(*root)->stocks[i];
    }
    
    
    else if(dif>0)
    {companii_dreapta++;
    vec_comp_st[dr++]=(*root)->stocks[i];
    }

}


//ma duc mai intai pe stanga

/*for(int i=0;i<companii_stanga;i++)
{
    (*root)->left->stocks[i]=vec_comp_st[i];
}
*/
if(companii_stanga>0)
{
   (*root)->left=(treeNode*)malloc(sizeof(treeNode)); 
   (*root)->left->stocks=vec_comp_st;
   (*root)->left->left=NULL;
   (*root)->left->right=NULL;
   (*root)->left->depth=(*root)->depth+1;

   //apelez recursiv
   construire_arbore((&(*root)->left),companii_stanga);

}

if(companii_dreapta>0)
{
    (*root)->right=(treeNode*)malloc(sizeof(treeNode)); 
   (*root)->right->stocks=vec_comp_dr;
   (*root)->right->left=NULL;
   (*root)->right->right=NULL;
   (*root)->right->depth=(*root)->depth+1;

   //apelez recursiv
   construire_arbore((&(*root)->right),companii_stanga);
}



}


void task3()
{
    treeNode *nodul_cap=NULL;
    //construiesc arborele
    nodul_cap=newNode_cap(nodul_cap);
    construire_arbore(&nodul_cap,nodul_cap->companii);
    //acum trebuie sa caut in tree
    //am indexul la fiecare stock...pot sa compar indexii cand afisez

}

