#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node;

void make_LL(node**);
void print_LL(node*);
node* merge_sort(node*,int*);
node* merge(node*,node*,int*);
node* middle_node_finder(node*);

int main()
{
    node* head=NULL;
    int cnt=0;
    printf("Enter elements : ");
    make_LL(&head);
    printf("Before : ");
    print_LL(head);
    head=merge_sort(head,&cnt);
    printf("\nAfter : ");
    print_LL(head);
    printf("\ninversion count : %d",cnt==0?cnt:cnt-1);
    return 0;
}


void make_LL(node **head){
    node *temp=NULL;
    int val;
    while(scanf("%d",&val) == 1){
        node* temp2=(node*)malloc(sizeof(node));
        temp2->val=val;
        temp2->next=NULL;

        if(!(*head)){
            temp=temp2;
            *head=temp2;
        }
        else{
            temp->next=temp2;
            temp=temp2;
        }
        if(getchar() == '\n'){
            break;
        }
    }
}

void print_LL(node *head){
    node* temp=head;
    while(temp){
        if(temp->next) printf("%d->",temp->val);
        else printf("%d",temp->val);
        temp=temp->next;
    }
}

node* merge_sort(node *head,int *cnt){
    
    if(!head || !head->next) return head;

    node* second = middle_node_finder(head);

    head=merge_sort(head,cnt);
    second=merge_sort(second,cnt);
    return merge(head,second,cnt); 

}

node* merge(node *first,node *second,int *cnt){
    if(!first) return second;
    if(!second) return first;

    if(first->val <= second->val){
        first->next=merge(first->next,second,cnt);
        return first;
    }else{
        second->next=merge(first,second->next,cnt);
        node* temp = first;
        while (temp) {
            (*cnt)++;
            temp = temp->next;
        }
        return second;
    }
    
}


node* middle_node_finder(node *head){
    node* slow=head;
    node* fast=head;
    while(fast && fast->next){
        fast=fast->next->next;
        if(fast)
            slow=slow->next;
    }
    node* temp=slow->next;
    slow->next=NULL;
    return temp;
}

