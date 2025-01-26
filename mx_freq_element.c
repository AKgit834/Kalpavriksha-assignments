#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node;

typedef struct freq{
    int freq;
    int element;
}freq;


void make_LL(node**);
void print_LL(node*);
void freq_counter(node*,freq[],int*);
int mx_freq_element(node*);

int main()
{
    node* head=NULL;

    printf("Enter elements : ");
    make_LL(&head);

    int ans=mx_freq_element(head);
    printf("Element with most occurence : %d",ans);

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

void freq_counter(node *head,freq map[],int *map_indx){
    node* temp=head;
    while(temp){
        int flg=0;
        for(int i=0;i<*map_indx;i++){
            if(temp->val == map[i].element){
                map[i].freq++;
                flg=1;
                break;
            }
        }
        if(!flg){
            map[*map_indx].freq=1;
            map[*map_indx].element=temp->val;
            (*map_indx)++;
        }
        temp=temp->next;
    }
}


int mx_freq_element(node* head){
    freq map[100];
    int map_indx=0;
    int mx_freq=-1;
    int mx_indx=-1;

    freq_counter(head,map,&map_indx);

    for(int i=0;i<map_indx;i++){
        if(map[i].freq > mx_freq){
            mx_indx=i;
            mx_freq=map[i].freq;
        }
    }
    return map[mx_indx].element;

}



