#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;


typedef struct queue{
    struct node* front;
    struct node* rear;
}queue;

queue initializeQueue();
void enqueue(queue *q,int data);
int dequeue(queue *q);
int peek(queue q);
int isEmpty(queue q);
int sizeOfQueue(queue *q);
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
            printf("size of queue : %d\n",sizeOfQueue(&q));
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
    q.front=NULL;
    q.rear=NULL;
    return q;
}

void enqueue(queue *q,int data){
    // if(q->rear > 100){
    //     printf("Queue overflow\n");
    //     return;
    // }
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    if(q->rear)
        q->rear->next=newNode;
    q->rear=newNode;
    if(!(q->front)) q->front=q->rear;
}

int dequeue(queue *q){
    if(!(q->front)){
        q->rear=NULL;
        printf("queue empty\n");
        return -1;
    }
    struct node* frontNode=q->front;
    int valOnFront=q->front->data;
    q->front=q->front->next;
    free(frontNode);
    return valOnFront;
}

int peek(queue q){
    if(!(q.front)){
        printf("queue empty\n");
        return -1;
    }
    return q.front->data;
}

int isEmpty(queue q){
    if(!(q.front)) return 1;
    return 0;
}

int sizeOfQueue(queue *q){
    int size=0;
    struct node* temp=q->front;
    while(temp){
        size++;
        temp=temp->next;
    }
    return size;
}


void freeQueue(queue *q){
    while(q->front){
        node* toFree=q->front;
        q->front=q->front->next;
        free(toFree);
    }
}

