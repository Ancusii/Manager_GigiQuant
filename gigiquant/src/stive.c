#include "stiveheader.h"

void push(node **top, int v)
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

int top(node *top)
{
    if(isEmpty(top)) return INT_MIN;
    return top->val;
}
int isEmpty(node *top)
{
    return top==NULL;
}

void delete(node **top)
{
    node *temp;
    while((*top)!=NULL)
    {
        temp=*top;
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

void enQueue(queue *q, char *val)
{
    node *node_coada=(node*)malloc(sizeof(node));
    node_coada->val=malloc(strlen(val)+1);
    strcpy(node_coada->val,val);
    node_coada->next=NULL;
    if(q->rear==NULL) q->rear=node_coada;
    else
    {
        (q->rear)->next=node_coada;
        (q->rear)=node_coada;
    }
    if(q->front==NULL) q->front=q->rear;
    
}

int isItEmptyQ(queue *q)
{
    return(q->front==NULL);
}

void deleteQueue(queue *q,FILE *fo)
{
    node_coada *aux;
    while(!isItEmptyQ(q))
    {
        aux=q->front;
        q->front=q->front->next;
        fprintf(fo,"%s - ",aux->nume);
        free(aux);
    }
    free(q);
}

