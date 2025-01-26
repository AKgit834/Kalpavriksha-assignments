#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;


void createLinkedList(ListNode** head); 
void printLinkedList(ListNode* head);
int binarySearch(ListNode* head,int target); // performs binary search on linked list.
void sortLinkedList(ListNode *head); //sorts a linked list (performs selection sort).
void swap(int *x,int *y);
void freeMemory(ListNode* head); // frees the memory in end.
ListNode* findMiddle(ListNode* low,ListNode* high); // finds the middle node in linked list.


int main()
{
    int target;
    ListNode* head = NULL;

    printf("Enter elements: ");
    createLinkedList(&head);
    printf("Enter target : ");
    scanf("%d",&target);

    sortList(head);

    int ans=binarySearch(head,target);
    if(ans)
        printf("value present");
    else
        printf("value not present");

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
        if(getchar() == '\n') {
            break;
        }
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


int binarySearch(ListNode* head,int target){
    ListNode* low=head,*high=NULL,*mid;
 
    while(low != high){
        mid=findMiddle(low , high);
        if(mid->value == target)
            return 1;
        else if(mid->value > target)
            high=mid;
        else
            low=mid->next;
    }
    return 0;
}

ListNode* findMiddle(ListNode* low,ListNode* high){
    ListNode* slow=low;
    ListNode* fast=low;

    while(fast!=high && fast->next != high){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

void sortList(ListNode *head){
    ListNode *currentNode=head;

    while(currentNode){
        ListNode *comparisonNode=currentNode->next;
        ListNode *minValNode=currentNode;
        while(comparisonNode){
            if(minValNode->value > comparisonNode->value){
                minValNode=comparisonNode;
            }
            comparisonNode=comparisonNode->next;
        }
        swap(&minValNode->value,&currentNode->value);
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

