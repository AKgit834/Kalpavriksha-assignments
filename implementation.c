#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    struct node* next;
    int val;
}node;


int LL_creation(node** head);
void print_LL(node* head);

int main()
{
    node *head;
    int LL_len = LL_creation(&head);
    if(LL_len == 0)
        printf("Empty LL");
    else
        print_LL(head);
    return 0;
}


int LL_creation(node** head){
    node* temp=NULL;
    int x,len=0;;
    printf("Enter char for exiting\n");
    while (1)   
    {
        printf("Enter value : ");
        if(scanf("%d",&x) == 0){
            return len;
        }

        node* temp2=(node*)malloc(sizeof(node));
        temp2->val=x;
        temp2->next=NULL;
        if(len == 0){
            *head=temp2;
            temp=temp2;
        }
        else{
            temp->next=temp2;
            temp=temp2;
        }
        len++;
    }
    return len;
}

void print_LL(node* head){
    node* temp=head;
    while(temp){
        if(temp->next)
            printf("%d->",temp->val);
        else
            printf("%d",temp->val);
        temp=temp->next;
    }
}


