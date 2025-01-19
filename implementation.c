#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    struct node* next;
    int val;
}node;


int LL_creation(node** );
void print_LL(node* );
void add_at_end(node **,int);
void add_at_beg(node **,int);
void add_at_pos(node **,int,int);
void update_at_pos(node **,int,int);
void delete_at_beg(node **);
void delete_at_end(node **);
void delete_at_pos(node**,int);


int main()
{
    node *head=NULL;
    int n;
    printf("Enter no. of operations to perform : ");
    scanf("%d",&n);
    printf("1. Add at end\n2. Add at beginning\n3. Add at pos");
    printf("\n4. Display Linked List\n5. Update at pos\n6. Delete at beginning");
    printf("\n7. Delete at end\n8. Delete at Position\n");
    for (int  i = 0; i < n; i++)
    {
        int choice,pos,val;
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter val : ");
            scanf("%d",&val);
            add_at_end(&head,val);
            break;
        case 2:
            printf("enter val : ");
            scanf("%d",&val);
            add_at_beg(&head,val);
            break;
        case 3:
            printf("Enter position : ");
            scanf("%d",&pos);
            printf("Enter val : ");
            scanf("%d",&val);
            add_at_pos(&head,pos,val);
            break;

        case 4:
            print_LL(head);
            break;

        case 5:
            printf("Enter position : ");
            scanf("%d",&pos);
            printf("Enter val : ");
            scanf("%d",&val);
            update_at_pos(&head,pos,val);
            break;

        case 6:
            delete_at_beg(&head);
            break;
        
        case 7:
            delete_at_end(&head);
            break;

        case 8:
            printf("Enter position : ");
            scanf("%d",&pos);
            delete_at_pos(&head,pos);
            break;

        default:
            break;
        }
    }

    return 0;
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

void add_at_end(node **head,int val){
    node* temp2=(node*)malloc(sizeof(node));
    temp2->val=val;
    temp2->next=NULL;
    if(*head == NULL){
        *head=temp2;
        return;
    }
    node *temp=*head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=temp2;
}

void add_at_beg(node **head,int val){
    node *temp=(node*)malloc(sizeof(node));
    temp->next=*head;
    temp->val=val;
    if(*head == NULL){
        *head=temp;
        return;
    }
    *head=temp;
}

void add_at_pos(node **head,int pos,int val){
    if(pos == 1){
        add_at_beg(head,val);
        return;
    }
    pos-=2; // we stop one node before.
    node* temp=*head;
    while(pos && temp){
        temp=temp->next;
        if(temp == NULL && pos >= 0){
            printf("\nPosition out of bound\n");
            return;
        }
        pos--;
    }
    node *temp2=(node*)malloc(sizeof(node));
    temp2->val=val;
    temp2->next=temp->next;
    temp->next=temp2;
}

void update_at_pos(node **head,int pos,int val){
    if((*head) == NULL){
        printf("Empty LL\n");
        return;
    }
    if(pos == 1){
        (*head)->val=val;
        return;
    }
    pos--; // 1 based indexing.
    node* temp=*head;
    while(pos && temp){
        pos--;
        temp=temp->next;
        if(temp == NULL && pos >=0){
            printf("\nPosition out of bound");
            return;
        }
    }
    temp->val=val;
    return;
}

void delete_at_beg(node **head){
    if((*head) == NULL){
        return;
    }
    node *temp=*head;
    (*head)=(*head)->next;
    free(temp);
    return;
}

void delete_at_end(node **head){
    if((*head) == NULL){
        return;
    }else if((*head)->next == NULL){
        (*head)=NULL;
        return;
    }
    node*temp=*head;
    while(temp->next && temp->next->next){
        temp=temp->next;
    }
    temp->next=NULL;

}

void delete_at_pos(node** head,int pos){
    if((*head) == NULL){
        return;
    }else if(pos == 1){
        delete_at_beg(head);
        return;
    }

    pos-=2;
    node *temp=*head;
    while(pos && temp->next){
        temp=temp->next;
        pos--;
        if(temp == NULL && pos >=0){
            printf("Position out of bound");
            return;
        }
    }
    if(temp->next == NULL){
        printf("Position out of bound");
        return;
    }
    temp->next=temp->next->next;

}


