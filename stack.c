#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int top;
    int capacityofDataArr;
    int *data; 
}stack;

stack initializeStack();
void push(stack *stk,int val);
int pop(stack *stk);
int peek(stack *stk); 
int isEmpty(stack stk);
int size(stack stk);
void freeStack(stack stk);

int main()
{
    stack stk=initializeStack(); // stack initialization.
    int choice;
    
    printf("  choices\n1. push\n2. pop\n3. peek\n4. isEmpty\n5. size\n6. exit");
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
            (isEmpty(stk))?printf("Stack is empty\n"):printf("Stack is not empty\n");
        }else if(choice == 5){
            printf("size of Stack : %d\n",size(stk));
        }else{
            printf("Exiting\n");
            freeStack(stk);
            return 1;
        }
        printf("\nEnter choice : ");
    }
    return 0;
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
        printf("Underflow , stack empty\n");
        return -1;
    }
    int val=(*stk).data[(*stk).top];
    (*stk).top--;
    return val;
}

int peek(stack *stk){
    if((*stk).top < 0) {
        printf("Underflow , stack empty\n");
        return -1;
    }
    return (*stk).data[(*stk).top];
}

int isEmpty(stack stk){
    if(stk.top < 0) return 1;
    return 0;
}


int size(stack stk){
    if(stk.top < 0) return 0;
    return (stk.top+1);
}

void freeStack(stack stk){
    free(stk.data);
}

