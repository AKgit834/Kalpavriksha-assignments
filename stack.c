#include<stdio.h>
#include<stdlib.h>


typedef struct queue{
    int front;
    int rear;
    int *data;
}queue;

typedef struct stack{
    queue q;
}stack;


//functions of stack
void push(stack *stk,int data);
int pop(stack *stk);
int peek(stack *stk);
int isEmpty(stack *stk);
int size(stack *stk);

//functions of queue
queue initializeQueue();
void enqueue(queue *q,int data);
int dequeue(queue *q);
int peekInQueue(queue q);
int isQueueEmpty(queue q);
int sizeOfQueue(queue q);
void freeQueue(queue *q);

int main()
{
    int choice;
    stack stk;
    stk.q=initializeQueue();

    printf("  choices\n1. Push\n2. Pop\n3. peek\n4. isEmpty\n5. size\n6. exit");
    printf("\nEnter choice : ");
    while(scanf("%d",&choice) == 1){
        if(choice == 1){
            int data;
            printf("Enter value to be pushed : ");
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
            printf("Exiting\n");
            freeQueue(&(stk.q));
            return 1;
        }
        printf("\nEnter choice : ");
    }
    return 0;
}


void push(stack *stk,int data){
    int stkSize=sizeOfQueue(stk->q);
    if(stkSize >= 100){
        printf("Stack Overflow !!\n");
        return;
    }
    enqueue(&(stk->q),data);
    for(int i=stk->q.front;i<stkSize;i++){
        enqueue(&(stk->q),stk->q.data[stk->q.front]);
        dequeue(&(stk->q));
    }
}

int peek(stack *stk){
    if(sizeOfQueue(stk->q) == 0){
        printf("Stack empty !!\n");
        return -1;
    }
    return stk->q.data[stk->q.front];
}

int pop(stack *stk){
    return dequeue(&(stk->q));
}

int isEmpty(stack *stk){
    return isQueueEmpty(stk->q);
}

int size(stack *stk){
    return sizeOfQueue(stk->q);
}

queue initializeQueue(){
    queue q;
    q.front=0;
    q.rear=0;
    q.data=(int*)malloc(sizeof(int)*100);
    return q;
}

void enqueue(queue *q,int data){
    if(q->rear >= 100){
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

int peekInQueue(queue q){
    if(q.front == q.rear){
        printf("queue empty\n");
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