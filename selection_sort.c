#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node;

void make_LL(node**);
void print_LL(node*);
void selection_sort(node*);
void swap(int *,int *);


int main()
{
    node* head=NULL;
    printf("Enter elements : ");
    make_LL(&head);
    selection_sort(head);
    print_LL(head);
    
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


void selection_sort(node *head){
    node *temp=head;

    while(temp){
        node *temp2=temp->next;
        node *min_node=temp;
        while(temp2){
            if(min_node->val > temp2->val){
                min_node=temp2;
            }
            temp2=temp2->next;
        }
        swap(&min_node->val,&temp->val);
        temp=temp->next;
    }
}


void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}