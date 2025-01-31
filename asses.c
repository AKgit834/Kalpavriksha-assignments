#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode{
    int patientId;
    int severityLevel;
    struct ListNode* next;
}ListNode;

void createLinkedList(ListNode  **head,int n);
void printLinkedList(ListNode  *head);
ListNode* sortBySeverity(ListNode* head);

int main()
{
    int n;
    ListNode* head=NULL;
    printf("Enter no. of patients : ");
    scanf("%d",&n);

    createLinkedList(&head,n);
    head=sortBySeverity(head);
    // printLinkedList(head);
    printf("\nexit");
    
    return 0;
}


ListNode* sortBySeverity(ListNode* head){
    ListNode* currNode=head;
    ListNode* criticalList=NULL,*criticalListTail=NULL;
    ListNode* seriousList=NULL,*seriousListTail=NULL;
    ListNode* stableList=NULL,*stableListTail=NULL;
    while(currNode)
    {
        ListNode *temp=currNode;
        currNode=currNode->next;
        temp->next=NULL;
        if(temp->severityLevel == 3){
            if(criticalList){
                criticalListTail->next=temp;
                criticalListTail=temp;
            }else{
                criticalList=temp;
                criticalListTail=temp;
            }
        }else if(temp->severityLevel == 2){
            if(seriousList){
                seriousListTail->next=temp;
                seriousListTail=temp;
            }else{
                seriousList=temp;
                seriousListTail=temp;
            }
        }else if(temp->severityLevel == 1){
            if(stableList){
                stableListTail->next=temp;
                stableListTail=temp;
            }else{
                stableList=temp;
                stableListTail=temp;
            }
        }
    }
    if(criticalList){
        if(seriousList){
            seriousListTail->next=stableList;
        }
        criticalListTail->next=seriousList;
        // seriousListTail->next=stableList;
        printLinkedList(criticalList);
        return criticalList;
    }
    else if(seriousList){
        seriousListTail->next=stableList;
        printLinkedList(seriousList);
        return seriousList;
    }else{
        printLinkedList(stableList);
        return stableList;
    }
    
}




void createLinkedList(ListNode  **head,int n){
    int id;
    char severity[10];
    ListNode *currNode=NULL;
    while(n){
        printf("Enter id and severity level : ");
        scanf("%d",&id);
        getchar();
        scanf("%[^\n]s",severity);
        
        ListNode *newNode=(ListNode*)malloc(sizeof(ListNode));
        newNode->patientId=id;
        newNode->next=NULL;
        if(strcmp(severity,"Critical") == 0)
            newNode->severityLevel=3;
        else if(strcmp(severity,"Serious") == 0)
            newNode->severityLevel=2;
        else if(strcmp(severity,"Stable") == 0)
            newNode->severityLevel=1;
        
        if(!(*head)){
            *head=newNode;
            currNode=newNode;
        }else{
            currNode->next=newNode;
            currNode=newNode;
        }
        n--;
    }
}


void printLinkedList(ListNode  *head){
    ListNode* currNode=head;
    while(currNode){
        printf("\nid : %d severity level : %d",currNode->patientId,currNode->severityLevel);
        currNode=currNode->next;
    }
}


