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
int peek(stack stk); // there is no need to pass by reference because we are not making any changes.
int isEmpty(stack stk);
int size(stack stk);

int main()
{
    stack stack=initializeStack(); // stack initialization.

    // push operation.
    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    printf("inserted values : %d %d %d\n",stack.data[0],stack.data[1],stack.data[2]);

    // pop operation.
    int v1=pop(&stack);
    int v2=pop(&stack);
    int v3=pop(&stack);
    printf("removed values : %d %d %d\n",v1,v2,v3);

    // peek operation.
    push(&stack,4);
    push(&stack,7);
    printf("value on top of stack : %d\n",peek(stack));

    //isEmpty operation.
    (isEmpty(stack))?printf("Empty\n"):printf("Not empty\n");

    //size operation.
    printf("size of stack : %d\n",size(stack));

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
        (*stk).data=(int*)realloc((*stk).data,(*stk).capacityofDataArr);
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

int peek(stack stk){
    if(stk.top < 0) {
        printf("Underflow , stack empty\n");
        return -1;
    }
    return stk.data[stk.top];
}

int isEmpty(stack stk){
    if(stk.top < 0) return 1;
    return 0;
}


int size(stack stk){
    if(stk.top < 0) return 0;
    return (stk.top+1);
}

