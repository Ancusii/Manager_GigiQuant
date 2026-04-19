#include "task3h.h"

void buildPath(int *path, int directie, int *lenght)
{
    path[(*lenght)++]=directie;
}

void removeFromPath(int *path, int *lenght)
{
    (*lenght)--;

}

/*int max_companii_noduri(treeNode *root, treeNode *root_gasit)
{

    if(root->companii>root_gasit->companii)
    return root->companii;
    
    return root_gasit->companii;

}*/
treeNode *cautare_inversa(treeNode *root_initial,int *path,int lenght)
{
    for(int i=0;i<lenght;i++)
    {
        if(root_initial==NULL)
        return NULL;

        if(path[i]==0) //adica sunt pe stanga
        root_initial=root_initial->right;
        else
        {
            root_initial=root_initial->left;
        }
        
    }
    return root_initial;
}

void parcurgere(treeNode *root,treeNode *root_initial,int *path,int *lenght,FILE *fo)
{
    if(root==NULL)
    return;


    if(root->left==NULL&&root->right==NULL) //adica am ajuns la frunza
    {   //parcurg pe cealalta cale, gasesc nodul cautat, compar indexii si afisez;
        //parcurg pe cealalta cale
        treeNode *nod_cautat=cautare_inversa(root_initial,path,*lenght);
        //ar trebui sa vad cate companii am in nodul respectiv...
        //fac un for si pentru for-ul respectiv vad ce companii am...
        if(nod_cautat==NULL)
       return;

       for(int i=0;i<nod_cautat->companii;i++)
        {
            for(int j=0;j<root->companii;j++)
            {
                if(root->stocks[j]->index < nod_cautat->stocks[i]->index)
                fprintf(fo,"%s-%s\n",root->stocks[j]->nume,nod_cautat->stocks[i]->nume);
                
            }
        }
        return;
    }

    if(root->left!=NULL)
    {
    buildPath(path,0,lenght);
    parcurgere(root->left,root_initial,path,lenght,fo);
    removeFromPath(path,lenght);
    }

     if(root->right!=NULL)
    {
        buildPath(path,1,lenght);
        parcurgere(root->right,root_initial,path,lenght,fo);
        removeFromPath(path,lenght);
    }
    

    
}





//ca sa citesc companiile cum vreau trebuie sa iau prima linie si sa o citesc
//citesc linia cu numele si bag numele in vectorul de stocks din nod
//apoi citesc liniile cu valori si le bag in liste;


treeNode *newNode_cap(FILE *fi)
{
    stockList *stocks;
    treeNode *root=(treeNode*)malloc(sizeof(treeNode));
    root->stocks=(stockList**)malloc(sizeof(stockList)*100);
    char buff[2000];
    int nr_companii=0;
    int i=0;
    char *p;
    int ok;
    if(fgets(buff,2000,fi)!=NULL)  //am citit prima linie
    {   
        p=strtok(buff,",\n");
        while(p)
        {   root->stocks[i]=(stockList*)malloc(sizeof(stockList));
            strcpy(root->stocks[i]->nume,p);
            root->stocks[i]->index=i;
            root->stocks[i]->next=NULL;
            nr_companii++;
            i++;

            p=strtok(NULL,",\n");
        }
    }
    //tin minte ultimul element din lista ca sa pot sa leg
    stockList *ultimul_nod[100];

    for(i=0;i<nr_companii;i++)
    ultimul_nod[i]=root->stocks[i];
    ok=1; //ca sa presupun ca sunt in prima zi

    //
    
    while(fgets(buff,2000,fi)!=NULL)
    {
        p=strtok(buff,",\n");
        i=0;
        while(p!=NULL&&i<nr_companii)
        {
            double val=atof(p);
            if(ok==1) //sunt in prima zi
            {root->stocks[i]->valoare=val;
            root->stocks[i]->index=i;
            }
            else
            {
                stockList *aux;
                aux=(stockList*)malloc(sizeof(stockList));
                aux->valoare=val;
                aux->next=NULL;
                aux->index=i;
                ultimul_nod[i]->next=aux;
                ultimul_nod[i]=aux;

            }
        i++;
        p=strtok(NULL,",\n");
        }
    ok=0; //ca practic am trecut de prima zi si trec in urmatoarele

    }
    root->left=NULL;
    root->right=NULL;
    root->companii=nr_companii;
    root->depth=0;

    return root;

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



void construire_arbore(treeNode **root,int nr_companii,int max_zile)
{
//pot sa ma duc pe stanga si dreapta recursiv pana nu mai am zile in lista, adica stocks->next==NULL
//si asa si construiesc nodurile din copac
if(*root==NULL)
return;


if((*root)->depth>=max_zile-1)
return;


//idee: vad cate companii am pe stanga si cate companii am pe dreapta
//dupa aceea ii pun in vectori de stanga si dreapta
//dupa aia construiesc nodul din stanga si dupa pe cel din dreapta dupa lista
//dupa aia apelez recursiv

int companii_stanga=0, companii_dreapta=0;

stockList **vec_comp_st,**vec_comp_dr; //vectori de liste

int st=0,dr=0;

vec_comp_st=(stockList**)malloc(nr_companii*sizeof(stockList*)); //vector de liste
vec_comp_dr=(stockList**)malloc(nr_companii*sizeof(stockList*));

for(int i=0;i<nr_companii;i++)
{
    double dif=0;
    //nodul meu de start are depth=0;
    //fac un auxiliar aux stocks;
    stockList *aux=(*root)->stocks[i]; //asta e deja pointer deci nu mai pun &
    for(int j=0;j<(*root)->depth;j++)
    aux=aux->next;

    if(aux!=NULL&&aux->next!=NULL)
    dif=aux->next->valoare-aux->valoare;

    if(dif<0) //sunt pe stanga
    {companii_stanga++;
    vec_comp_st[st++]=(*root)->stocks[i];
    }
    
    
    else
    {companii_dreapta++;
    vec_comp_dr[dr++]=(*root)->stocks[i];
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
    (*root)->left->companii=companii_stanga;
   (*root)->left->left=NULL;
   (*root)->left->right=NULL;
   (*root)->left->depth=(*root)->depth+1;

   //apelez recursiv
   construire_arbore(&((*root)->left),companii_stanga,max_zile);

}

if(companii_dreapta>0)
{
    (*root)->right=(treeNode*)malloc(sizeof(treeNode)); 
   (*root)->right->stocks=vec_comp_dr;
   (*root)->right->companii=companii_dreapta;
   (*root)->right->left=NULL;
   (*root)->right->right=NULL;
   (*root)->right->depth=(*root)->depth+1;

   //apelez recursiv
   construire_arbore(&((*root)->right),companii_dreapta,max_zile);
}



}


void task3(const char *cale_in,const char *cale_out)
{
    FILE *fi=fopen(cale_in,"r");
    FILE *fo=fopen(cale_out,"w");
    treeNode *nodul_cap=NULL;
    int path[100];
    int lenght=0;
    int depth_max;
    //construiesc arborele
    nodul_cap=newNode_cap(fi);
    depth_max=depth(nodul_cap->stocks[0]);
    construire_arbore(&nodul_cap,nodul_cap->companii,depth_max);
    //acum trebuie sa caut in tree
    //am indexul la fiecare stock...pot sa compar indexii cand afisez
    parcurgere(nodul_cap,nodul_cap,path,&lenght,fo);

}

