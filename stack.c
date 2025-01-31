#include<stdio.h>
#include<stdlib.h>


typedef struct queue{
    int front;
    int rear;
    int *data;
}queue;

typedef struct stack{
    queue q1;
    queue q2;
}stack;


//stack functions.
stack initializeStack();
void push(stack *stk,int data);
int peek(stack *stk);
int pop(stack *stk);
int size(stack *stk);
int isEmpty(stack *stk);
void freeStack(stack *stk);

// queue Functions.
queue initializeQueue();
void enqueue(queue *q,int data);
int dequeue(queue *q);
int peekQueue(queue q);
int isQueueEmpty(queue q);
int sizeOfQueue(queue q);
void freeQueue(queue *q);
void swap(queue *q1,queue *q2);

int main()
{
    int choice;
    stack stk=initializeStack();
    
    printf("  choices\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Size\n6. exit");
    printf("\nEnter choice : ");
    while(scanf("%d",&choice) == 1){
        if(choice == 1){
            int data;
            printf("Enter value to be inserted : ");
            scanf("%d",&data);
            push(&stk,data);
        }else if(choice == 2){
            printf("poped val : %d\n",pop(&stk));
        }else if(choice == 3){
            printf("peeked val : %d\n",peek(&stk));
        }else if(choice == 4){
            (isEmpty(&stk))?printf("stack is empty\n"):printf("stack is not empty\n");
        }else if(choice == 5){
            printf("size of stack : %d\n",size(&stk));
        }else{
            freeStack(&stk);
            printf("Exiting\n");
            return 1;
        }
        printf("\nEnter choice : ");
    }
    return 0;
}

stack initializeStack(){
    stack stk;
    stk.q1=initializeQueue();
    stk.q2=initializeQueue();
    return stk;
}

void push(stack *stk,int data){
    enqueue(&(stk->q2),data);
    
    while(!isEmpty(stk)){
        enqueue(&(stk->q2),dequeue(&(stk->q1)));
    }
    swap(&(stk->q1),&(stk->q2));
}

int peek(stack *stk){
    return peekQueue(stk->q1);
}

int pop(stack *stk){
    if(isQueueEmpty(stk->q1)){
        printf("Stack empty !!\n");
        return -1;
    }
    return dequeue(&(stk->q1));
}

int size(stack *stk){
    return sizeOfQueue(stk->q1);
}

int isEmpty(stack *stk){
    return isQueueEmpty(stk->q1);
}

void freeStack(stack *stk){
    freeQueue(&(stk->q1));
    freeQueue(&(stk->q2));
}


void swap(queue *q1,queue *q2){
    queue temp=*q1;
    *q1=*q2;
    *q2=temp;
}

queue initializeQueue(){
    queue q;
    q.front=0;
    q.rear=0;
    q.data=(int*)malloc(sizeof(int)*100);
    return q;
}

void enqueue(queue *q,int data){
    if(q->rear > 100){
        printf("Queue overflow\n");
        return;
    }
    q->data[q->rear]=data;
    (q->rear)++;
}

int dequeue(queue *q){
    if(q->front == q->rear){
        q->front=0;
        q->rear=0;
        printf("queue empty\n");
        return -1;
    }
    int valOnFront=q->data[q->front];
    (q->front)++;
    return valOnFront;
}

int peekQueue(queue q){
    if(q.front == q.rear){
        printf("stack empty !!\n");
        return -1;
    }
    return q.data[q.front];
}

int isQueueEmpty(queue q){
    if(q.front == q.rear) return 1;
    return 0;
}

int sizeOfQueue(queue q){
    return (q.rear - q.front);
}

void freeQueue(queue *q){
    free(q->data);
}
