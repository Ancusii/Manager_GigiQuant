#include "task4h.h"

Graph *citire_date(FILE *fi,int *K)
{
    int N;
    double P,Pmin,Pmax,d;
    double Pstart,Ptarget,vp[30];
    Graph *g;

    Pmin=INT_MAX;
    Pmax=INT_MIN;
    fscanf(fi,"%d",&N);
    fscanf(fi,"%lf",&d);
    fscanf(fi,"%d",K);
    fscanf(fi,"%lf%lf",&Pstart,&Ptarget);
    for(int i=0;i<N;i++)
    {
        fscanf(fi,"%lf",&P);
        vp[i]=floor(P);
        if(P<Pmin)
        Pmin=P;
        if(P>Pmax)
        Pmax=P;
    }
    //trebuie sa aloc spatiu pentru graf,matrice si liniile matricei
    g=(Graph*)malloc(sizeof(Graph));
    Pmax=floor(Pmax);
    Pmin=floor(Pmin);
    g->V=(Pmax-Pmin)/d+1;
   


    g->a=(fractie**)malloc(sizeof(fractie*)*g->V); //aloc spatiu matricei mai intai, matricea devine un vector de pointeri,aloc liniile

    for(int i=0;i<g->V;i++)
    {
        g->a[i]=(fractie*)calloc(g->V,sizeof(fractie)); //aloc pentru coloane acum
    for(int j=0;j<g->V;j++)
    g->a[i][j].numitor=1; //ca sa nu am 0 la numitor
    }
    
    //pun muchiile in graf
    for(int i=0;i<N-1;i++)
    {
        g->a[(int)((vp[i]-Pmin)/d)][(int)((vp[i+1]-Pmin)/d)].numarator++; //sa vad de cate ori ma intorc
    }
   
    g->index_target=(int)((Ptarget-Pmin)/d);
    g->index_start=(int)((Pstart-Pmin)/d);
    
    return g;
}
int cmmdc(int a,int b)
{
    int aux;
    while(b!=0)
    {
        aux=b;
        b=a%b;
        a=aux;
    }
    return a;
}

fractie reducere_fractie(fractie fr)
{
    int div;
    do
    {
        div=cmmdc(fr.numarator,fr.numitor);
        fr.numarator/=div;
        fr.numitor/=div;
    } while (div!=1);
    
    return fr;
}

void Markov(Graph **g) //functie care transforma graful meu in markov
{
    int i,j;
    int numi;
    for(i=0;i<(*g)->V;i++)
    {   numi=0;
        for(j=0;j<(*g)->V;j++)
        {
            if((*g)->a[i][j].numarator!=0)
            numi+=(*g)->a[i][j].numarator; //trebuie sa adun cu frecventa pe care o calculez, ca poate merge dintr-un nod in altul de mai multe ori
        }
        for(j=0;j<(*g)->V;j++)
        {   if((*g)->a[i][j].numarator!=0)
            {
            (*g)->a[i][j].numitor=numi;
            (*g)->a[i][j]=reducere_fractie((*g)->a[i][j]); //aduc g la fractie simpla
            }
            else (*g)->a[i][j].numitor=1;
        }
    }
}



void parcurgere_lant(Graph *g,int K,FILE *fo)
{
    fractie *prob_c,*prob_urm; //fac un vector cu probabilitatile in ziua respectiva si ce va urma
    int i=0,j;
    int cont=1;
    fractie P={0};
    int numarator,numitor;
    prob_c=(fractie*)malloc(sizeof(fractie)*g->V);
    prob_urm=(fractie*)malloc(sizeof(fractie)*g->V);
    for(i=0;i<g->V;i++)
    {prob_c[i].numarator=0;
    prob_c[i].numitor=1;
    }
    prob_c[g->index_start].numitor=1;
    prob_c[g->index_start].numarator=1;
    
    int tranz=0;

    while(cont<=K){

    for(i=0;i<g->V;i++) //reinitializez cu 0 sa o iau de la capat, sa nu depasesc 100% probabilitatea
    {prob_urm[i].numarator=0;
    prob_urm[i].numitor=1;
    }
    for(i=0;i<g->V;i++)
    {
        if(prob_c[i].numarator!=0) //probabilitatea nodului curent
        {
            for(j=0;j<g->V;j++)
            {
                if(g->a[i][j].numarator!=0) //conditia cu probabilitatea am pus-o mai sus si ma scuteste de parcurgeri inutile
                {  
                    P.numarator=prob_c[i].numarator*g->a[i][j].numarator; //inmultesc probabilitatea curenta cu probabilitatea curenta de muchie
                    P.numitor=prob_c[i].numitor*g->a[i][j].numitor;
                    //simplific P
                    P=reducere_fractie(P);
                    //adun P la probabilitatea viitoare a lui j (adun fractiile)
                    prob_urm[j].numarator=(prob_urm[j].numarator*P.numitor)+(P.numarator*prob_urm[j].numitor); //transmit probabilitatea mea mai departe
                    prob_urm[j].numitor=prob_urm[j].numitor*P.numitor;
                    //reduc la fractie simpla
                    prob_urm[j]=reducere_fractie(prob_urm[j]);
                }
            }
        }
    }
    //afisez probabilitatea curenta
    if(cont<K){
    if(prob_c[g->index_target].numitor==1)
    fprintf(fo,"%d\n",prob_c[g->index_target].numarator);
    else
    fprintf(fo,"%d/%d\n",prob_c[g->index_target].numarator,prob_c[g->index_target].numitor);
    }
    else
    {
    fprintf(fo,"%d/%d",prob_c[g->index_target].numarator,prob_c[g->index_target].numitor);
    }
    
    //actualizez starile urmatoare
    for(i=0;i<g->V;i++)
    {
        prob_c[i]=prob_urm[i];
    }
    cont++;

}
    


}

void task4(char *cale_in,char *cale_out)
{
    FILE *fi=fopen(cale_in,"rt"); //sa nu mai it de fopen
    FILE *fo=fopen(cale_out,"wt");
    int K;
    Graph *g=citire_date(fi,&K);
    int i,j;
    Markov(&g);

    parcurgere_lant(g,K,fo);
}