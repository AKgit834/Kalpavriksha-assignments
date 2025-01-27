#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

void createLinkedList(ListNode** );
void printLinkedList(ListNode* );
void bubbleSortOnLinkedList(ListNode *);
void swap(int *,int *);
void freeMemory(ListNode* ); 


int main()
{
    ListNode* head=NULL;
    printf("Enter elements : ");
    createLinkedList(&head);

    bubbleSortOnLinkedList(head);
    printLinkedList(head);
    freeMemory(head);
    
    return 0;
}


void createLinkedList(ListNode** head) {
    ListNode* currentListNode = NULL;
    int inputValue;
    
    while(scanf("%d", &inputValue) == 1) {
        
        ListNode* newListNode = (ListNode*)malloc(sizeof(ListNode));
        newListNode->value = inputValue;
        newListNode->next = NULL;

        if(*head == NULL) {
            currentListNode = newListNode;
            *head = newListNode;
        }
        else {
            currentListNode->next = newListNode;
            currentListNode = newListNode;
        }
        
        if(getchar() == '\n') break;
    }
}

void printLinkedList(ListNode* head) {
    ListNode* currentListNode = head;
    while(currentListNode) {
        if(currentListNode->next) 
            printf("%d->", currentListNode->value);
        else 
            printf("%d", currentListNode->value);
        currentListNode = currentListNode->next;
    }
}


void bubbleSortOnLinkedList(ListNode *head){
    ListNode* currentNode=head;
    while(currentNode->next){
        int swapped=0;
        ListNode* comparisionNode=head;
        while(comparisionNode->next){
            if(comparisionNode->value > comparisionNode->next->value){
                swap(&(comparisionNode->value),&(comparisionNode->next->value));
                swapped=1;
            }
            comparisionNode=comparisionNode->next;
        }
        if(!swapped){
            break;
        }
        currentNode=currentNode->next;
    }
}


void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void freeMemory(ListNode* head){
    while(head){
        ListNode* nextNode=head->next;
        free(head);
        head=nextNode;
    }
}
