#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    int value;
    struct listNode* next;
} listNode;

void createLinkedList(listNode** head);
void printLinkedList(listNode* head);
int advancePointerByN(listNode** Pointer,int n);
listNode* findNthNodeFromEnd(listNode* head,int n);


int main()
{
    listNode* head = NULL;
    int n;
    printf("Enter elements: ");
    createLinkedList(&head);

    printf("Enter the node you want to find from end : ");
    scanf("%d",&n);

    listNode* nthNode=findNthNodeFromEnd(head,n);
    if(nthNode)
        printf("Nth node from end : %d",nthNode->value);

    return 0;
}

void createLinkedList(listNode** head) {
    listNode* currentNode  = NULL;
    int inputValue;
    
    while(scanf("%d", &inputValue) == 1) {
        listNode* newNode  = (listNode*)malloc(sizeof(listNode));
        newNode ->value = inputValue;
        newNode ->next = NULL;

        if(*head == NULL) {
            currentNode  = newNode ;
            *head = newNode ;
        }
        else {
            currentNode ->next = newNode ;
            currentNode  = newNode ;
        }
        
        if(getchar() == '\n') break;
    }
}

void printLinkedList(listNode* head) {
    listNode* currentNode  = head;
    while(currentNode ) {
        if(currentNode ->next) 
            printf("%d->", currentNode ->value);
        else 
            printf("%d", currentNode ->value);
        currentNode  = currentNode ->next;
    }
}

int advancePointerByN(listNode** pointer,int n){
    while(n-- && *pointer){
        *pointer=(*pointer)->next;
    }
    if(!(*pointer) && n>=0) return 0;
    return 1;
}

listNode* findNthNodeFromEnd(listNode* head,int n){
    listNode* slowPointer=head,*fastPointer=head;
    
    if(!advancePointerByN(&fastPointer,n)){
        printf("value greater than linked list size\n");
        return NULL;
    }
    if(!fastPointer) return slowPointer;
    while(fastPointer){
        fastPointer=fastPointer->next;
        slowPointer=slowPointer->next;
    }
    return slowPointer;
}

