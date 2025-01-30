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
void freeStack(stack stk);

int main()
{
    stack stk=initializeStack(); // stack initialization.

    // push operation.
    push(&stk,1);
    push(&stk,2);
    push(&stk,3);
    printf("inserted values : %d %d %d\n",stk.data[0],stk.data[1],stk.data[2]);

    // pop operation.
    int v1=pop(&stk);
    int v2=pop(&stk);
    int v3=pop(&stk);
    printf("removed values : %d %d %d\n",v1,v2,v3);

    // peek operation.
    push(&stk,4);
    push(&stk,7);
    printf("value on top of stack : %d\n",peek(stk));

    //isEmpty operation.
    (isEmpty(stk))?printf("Empty\n"):printf("Not empty\n");

    //size operation.
    printf("size of stack : %d\n",size(stk));


    // program ends.
    freeStack(stk);
    printf("Memory freed");
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

void freeStack(stack stk){
    free(stk.data);
}

