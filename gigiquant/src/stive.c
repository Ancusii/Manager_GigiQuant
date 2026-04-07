#include "stive.h"

void push(node **top, int v)
{
    node *newNode=(Node*)malloc(sizeof(node));
    newNode->val=v;
    newNode->next=*top;
    (*top)=newNode;
}

int pop(Node **top)
{
    if(isEmpty(*top)) return INT_MIN;
    node *temp=*top;
    int aux=temp->val;
    (*top)->(*top)->next;
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
    iff(q==NULL) return NULL;
    q->front=q->rear=NULL;
    return q;
}

void enQueue(queue *q, int val)
{
    node *nod=(node*)malloc(sizeof(node));
    nod->val=val;
    nod->next=NULL;
    if(q->rear==NULL) q->rear=nod;
    else
    {
        (q->rear)->next=nod;
        (q->rear)=nod;
    }
    if(q->front==NULL) q->front=q->rear;
    
}

int isItEmpty(queue *q)
{
    return(q->front==NULL);
}

void deleteQueue(queue *q)
{
    node *aux;
    while(!isItEmpty(q))
    {
        aux->q->front;
        q->front=q->front->next;
        //printf
        free(aux);
    }
    free(q);
}

