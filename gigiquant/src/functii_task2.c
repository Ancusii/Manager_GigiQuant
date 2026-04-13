#include "task2h.h"

void task2(const char *cale_in,const char *cale_out)
{
    FILE *fi=fopen(cale_in,"r");
    FILE *fo=fopen(cale_out,"w");
    node *P1=NULL, *P2=NULL, *P3=NULL;
    char nume1[100], nume2[100], nume3[100];
    double x;
    queue *queue_final=creareQueue();


    //construiesc stivele(sa fac functii dupa)
    fgets(nume1,100,fi);
    while(fscanf(fi,"%lf",&x)==1)
    push(&P1,x);
   

    fgets(nume2,100,fi);
    while(fscanf(fi,"%lf",&x)==1)
    push(&P2,x);
   

    fgets(nume3,100,fi);
    while(fscanf(fi,"%lf",&x)==1)
    push(&P3,x);
    
    int i=1;

    double diferenta;

    while((P1!=NULL&&P2!=NULL&&P3!=NULL))
    {
        if(P1->val==P2->val&&P1->val!=P3->val)
        { //nota: voi face o functie cu queue_final,numele si stivele
            diferenta=fabs(P1->val-P3->val);
            adaugare_coada(&queue_final,i,diferenta,nume3);
        }

        if(P1->val==P3->val&&P1->val!=P2->val)
        {   diferenta=fabs(P1->val-P2->val);
            adaugare_coada(&queue_final,i,diferenta,nume2);
        }

        if(P2->val==P3->val&&P2->val!=P1->val)
        {   diferenta=fabs(P3->val-P1->val);
            adaugare_coada(&queue_final,i,diferenta,nume1);
        }
        pop(&P1);
        pop(&P2);
        pop(&P3);
        i++;

    }
    
    deleteQueue(queue_final,fo);
    delete(&P1);
    delete(&P2);
    delete(&P3);

    
fclose(fi);
fclose(fo);

}

void push(node **top, double v)
{
    node *newNode=(node*)malloc(sizeof(node));
    newNode->val=v;
    newNode->next=*top;
    (*top)=newNode;
}

int pop(node **top)
{
    if(isEmpty(*top)) return INT_MIN;
    node *temp=*top;
    int aux=temp->val;
    (*top)=(*top)->next;
    free(temp);
    return aux;

}

/*int top(node *top)
{
    if(isEmpty(top)) return INT_MIN;
    return top->val;
}*/
int isEmpty(const node *top)
{
    return top==NULL;
}

void delete(node **top)
{
    while((*top)!=NULL)
    {
       node *temp=*top;
        *top=(*top)->next;
        free(temp);
    }
}

queue *creareQueue()
{
    queue *q;
    q=(queue*)malloc(sizeof(queue));
    if(q==NULL) return NULL;
    q->front=q->rear=NULL;
    return q;
}

void enQueue(queue *q, const char *val)
{
    node_coada *nou=(node_coada*)malloc(sizeof(node));
    nou->nume=malloc(strlen(val)+1);
    strcpy(nou->nume,val);
    nou->next=NULL;
    if(q->rear==NULL) q->rear=nou;
    else
    {
        (q->rear)->next=nou;
        (q->rear)=nou;
    }
    if(q->front==NULL) q->front=q->rear;
    
}

int isItEmptyQ(const queue *q)
{
    return(q->front==NULL);
}

void deleteQueue(queue *q,FILE *fo)
{
    int i=0;
    while(!isItEmptyQ(q))
    { 
        node_coada *aux=q->front;
        q->front=q->front->next;
        fprintf(fo,"%s",aux->nume);
        //if(i%3==2) printf("\n");
        if(i%3!=2) fprintf(fo," - "); 
        
        i++;
        free(aux->nume);
        free(aux);
    }
    free(q);
}

void adaugare_coada(queue **queue_final,int zi, double dif, const char nume[])
{
     char buff[100];
     sprintf(buff,"ziua %d",zi);
     enQueue(*queue_final,buff);
     sprintf(buff,"%.2lf",dif);
     enQueue(*queue_final,buff);
     enQueue(*queue_final,nume);
}

