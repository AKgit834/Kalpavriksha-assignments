#include<stdio.h>
#include<stdlib.h>


typedef struct queue{
    int front;
    int rear;
    int *data;
}queue;

queue initializeQueue();
void enqueue(queue *q,int data);
int dequeue(queue *q);
int peek(queue q);
int isEmpty(queue q);
int sizeOfQueue(queue q);
void freeQueue(queue *q);

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
            printf("peeked val : %d\n",peek(q));
        }else if(choice == 4){
            (isEmpty(q))?printf("queue is empty\n"):printf("queue is not empty\n");
        }else if(choice == 5){
            printf("size of queue : %d\n",sizeOfQueue(q));
        }else{
            printf("Exiting\n");
            freeQueue(&q);
            return 1;
        }
        printf("\nEnter choice : ");
    }
    return 0;
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

int peek(queue q){
    if(q.front == q.rear){
        printf("queue empty\n");
        return -1;
    }
    return q.data[q.front];
}

int isEmpty(queue q){
    if(q.front == q.rear) return 1;
    return 0;
}

int sizeOfQueue(queue q){
    return (q.rear - q.front);
}


void freeQueue(queue *q){
    free(q->data);
}

