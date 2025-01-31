#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int top;
    int capacityofDataArr;
    int *data; 
}stack;

typedef struct queue{
    stack stk;
}queue;

//queue functions.
void enqueue(queue *q,int data);
int dequeue(queue *q);
int peekInQueue(queue *q);
int isQueueEmpty(queue *q);
int queueSize(queue *q);

// stack functions.
stack initializeStack();
void push(stack *stk,int val);
int pop(stack *stk);
int peek(stack *stk);
int isEmpty(stack stk);
int size(stack stk);
void freeStack(stack *stk);

int main()
{
    int choice;
    queue q;
    q.stk = initializeStack();

    printf("  choices\n1. enqueue\n2. dequeue\n3. Peek\n4. isEmpty\n5. Size\n6. exit");
    printf("\nEnter choice : ");
    while(scanf("%d",&choice) == 1){
        if(choice == 1){
            int data;
            printf("Enter value to be enqued : ");
            scanf("%d",&data);
            enqueue(&q,data);
        }else if(choice == 2){
            printf("poped val : %d\n",dequeue(&q));
        }else if(choice == 3){
            printf("peeked val : %d\n",peekInQueue(&q));
        }else if(choice == 4){
            (isQueueEmpty(&q))?printf("Queue is empty\n"):printf("Queue is not empty\n");
        }else if(choice == 5){
            printf("size of Queue : %d\n",queueSize(&q));
        }else{
            freeStack(&q.stk);
            printf("Exiting\n");
            return 1;
        }
        printf("\nEnter choice : ");
    }
    return 0;
}


void enqueue(queue *q,int data){
    if(isEmpty(q->stk)){
        push(&(q->stk), data);
        return;
    }
    int val=dequeue(q);
    enqueue(q,data);
    push(&(q->stk),val);
}

int dequeue(queue *q){
    if(isEmpty(q->stk)){
        printf("Queue empty\n");
        return -1;
    }
    return pop(&(q->stk));
}

int peekInQueue(queue *q){
    if(isEmpty(q->stk)){
        printf("Queue empty !!\n");
        return -1;
    }
    return peek(&(q->stk));
}

int isQueueEmpty(queue *q){
    return isEmpty(q->stk);
}

int queueSize(queue *q){
    return size(q->stk);
}

stack initializeStack(){
    stack stack;
    stack.top=-1;
    stack.capacityofDataArr=20;
    stack.data=(int*)malloc(sizeof(int)*stack.capacityofDataArr);
    return stack;
}

void push(stack *stk,int val){
    (*stk).top++;
    if((*stk).top >= (*stk).capacityofDataArr){
        (*stk).capacityofDataArr = (*stk).capacityofDataArr*2;
        (*stk).data=(int*)realloc((*stk).data,sizeof(int)*(*stk).capacityofDataArr);
    }
    (*stk).data[(*stk).top]=val;
}

int pop(stack *stk){
    if((*stk).top < 0) {
        
        return -1;
    }
    int val=(*stk).data[(*stk).top];
    (*stk).top--;
    return val;
}

int peek(stack *stk){
    if(stk->top < 0) {
        return -1;
    }
    return stk->data[stk->top];
}

int isEmpty(stack stk){
    if(stk.top < 0) return 1;
    return 0;
}


int size(stack stk){
    if(stk.top < 0) return 0;
    return (stk.top+1);
}

void freeStack(stack *stk){
    free(stk->data);
}
