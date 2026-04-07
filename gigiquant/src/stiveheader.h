#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int val;
    struct node *next;
};
typedef struct node node;

struct Q{
    node *front, *rear;
}
typedef struct Q queue;

void push(node **top, int v);
int pop(Node **top);
int top(node *top);
int isEmpty(node *top);
void delete(node **top);
queue *creareQueue();
void enQueue(queue *q, int val);
int isItEmptyQ(queue *q);
void deleteQueue(queue *q);