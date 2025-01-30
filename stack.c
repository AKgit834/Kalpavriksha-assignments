#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *next;
    int data;
}node;

typedef struct stack{
    node *head;
}stack;

stack initializeStack();
void push(stack *stk,int data);
int pop(stack *stk);
int peek(stack stk);
int size(stack stk);
int isEmpty(stack stk);

int main()
{
    int choice;
    stack stk=initializeStack();
    
    printf("  choices\n1. push\n2. pop\n3. peek\n4. isEmpty\n5. size\n6. exit");
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
            printf("peeked val : %d\n",peek(stk));
        }else if(choice == 4){
            (isEmpty(stk))?printf("Stack is empty\n"):printf("Stack is not empty\n");
        }else if(choice == 5){
            printf("size of stack : %d\n",size(stk));
        }else{
            printf("Exiting\n");
            return 1;
        }
        printf("\nEnter choice : ");
    }
    return 0;
}

stack initializeStack(){
    stack stk;
    stk.head=NULL;
    return stk;
}


void push(stack *stk,int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=stk->head;
    stk->head=newNode;
}

int pop(stack *stk){
    if(!(stk->head)){
        printf("stack empty\n");
        return -1;
    }
    int dataOnTop=stk->head->data;
    stk->head=stk->head->next;
    return dataOnTop;
}

int peek(stack stk){
    if(!(stk.head)){
        printf("stack empty\n");
        return -1;
    }
    return stk.head->data;
}

int isEmpty(stack stk){
    if(stk.head) return 0;
    return 1;
}

int size(stack stk){
    int size=0;
    node *temp=stk.head;
    while(temp){
        size++;
        temp=temp->next;
    }
    return size;
}


