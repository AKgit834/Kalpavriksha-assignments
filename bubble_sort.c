#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node;

void make_LL(node**);
void print_LL(node*);
void bubble_sort(node *);
void swap(int *,int *);


int main()
{
    node* head=NULL;
    printf("Enter elements : ");
    make_LL(&head);
    bubble_sort(head);
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


void bubble_sort(node *head){
    node* temp=head;
    while(temp->next){
        int swapped=0;
        node* temp2=head;
        while(temp2->next){
            if(temp2->val > temp2->next->val){
                swap(&(temp2->val),&(temp2->next->val));
                swapped=1;
            }
            temp2=temp2->next;
        }
        if(!swapped){
            break;
        }
        temp=temp->next;
    }
}


void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
