#include<stdio.h>
#include<stdlib.h>


typedef struct stack{
    int top;
    int capacityofDataArr;
    int *data; 
}stack;


typedef struct queue{
    stack stk1; // used for storing values.
    stack stk2; // used for storing the values during enqueue.
}queue;

// queue functions.
queue initializeQueue();
void enqueue(queue *q,int data);
int dequeue(queue *q);
int peekInQueue(queue *q);
int isQueueEmpty(queue *q);
int sizeOfQueue(queue *q);
void freeQueue(queue *q);

// stack functions.
stack initializeStack();
void push(stack *stk,int val);
int pop(stack *stk);
int peek(stack *stk);
int isEmpty(stack *stk);
int size(stack stk);


int main()
{
    int choice;
    queue q=initializeQueue();

    printf("  choices\n1. enqueue\n2. dequeue\n3. peek\n4. isEmpty\n5. size\n6. exit");
    printf("\nEnter choice : ");
    while(scanf("%d",&choice) == 1){
        if(choice == 1){
            int data;
            printf("Enter value to be inserted : ");
            scanf("%d",&data);
            enqueue(&q,data);
        }else if(choice == 2){
            printf("poped val : %d\n",dequeue(&q));
        }else if(choice == 3){
            printf("peeked val : %d\n",peekInQueue(&q));
        }else if(choice == 4){
            (isQueueEmpty(&q))?printf("queue is empty\n"):printf("queue is not empty\n");
        }else if(choice == 5){
            printf("size of queue : %d\n",sizeOfQueue(&q));
        }else{
            printf("Exiting\n");
            freeQueue(&q);
            return 1;
        }
        printf("\nEnter choice : ");
    }


    printf("Memory freed");
    return 0;
}

queue initializeQueue(){
    queue q;
    q.stk1=initializeStack();
    q.stk2=initializeStack();
    return q;
}

stack initializeStack(){
    stack stack;
    stack.top=-1;
    stack.capacityofDataArr=20;
    stack.data=(int*)malloc(sizeof(int)*stack.capacityofDataArr);
    return stack;
}

void enqueue(queue *q,int data){
    while(q->stk1.top >= 0){
        push(&(q->stk2),q->stk1.data[q->stk1.top]);
        (q->stk1.top)--;
    }
    push(&(q->stk1),data);
    while(q->stk2.top >= 0){
        push(&(q->stk1),q->stk2.data[q->stk2.top]);
        (q->stk2.top)--;
    }
}

int dequeue(queue *q){
    return pop(&(q->stk1));
}

int isQueueEmpty(queue *q){
    return isEmpty(&(q->stk1));
}

int peekInQueue(queue *q){
    return peek(&(q->stk1));
}

int sizeOfQueue(queue *q){
    return size(q->stk1);
}

void push(stack *stk,int val){
    if(stk->top >= 100){
        printf("Stack Overflow\n");
        return;
    }
    (*stk).top++;
    (*stk).data[(*stk).top]=val;
}

int pop(stack *stk){
    if((*stk).top < 0) {
        printf("Underflow , queue empty\n");
        return -1;
    }
    int val=(*stk).data[(*stk).top];
    (*stk).top--;
    return val;
}

int peek(stack *stk){
    if(stk->top < 0) {
        printf("Underflow , queue empty\n");
        return -1;
    }
    return stk->data[stk->top];
}

int isEmpty(stack *stk){
    if(stk->top < 0) return 1;
    return 0;
}


int size(stack stk){
    if(stk.top < 0) return 0;
    return (stk.top+1);
}

void freeQueue(queue *q){
    free(q->stk1.data);
    free(q->stk2.data);
}



