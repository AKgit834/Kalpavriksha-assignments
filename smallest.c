#include<stdio.h>
#include<stdlib.h>

char* take_str_inp(int *);
int checker(char [],char [],int ,int);
void smallest_window(char [],char [],int *,int *);



int main(int argc, char const *argv[])
{
    char *str,*str2;
    int str_size=0,str_size2=0;
    printf("Enter first string : ");
    str=take_str_inp(&str_size);
    printf("Enter second string : ");
    str2=take_str_inp(&str_size2);

    int start=0,end=0;
    smallest_window(str,str2,&start,&end);

    printf("start : %d end : %d\n",start,end);
    for(int i=start;i<=end;i++)
        printf("%c",str[i]);
    free(str);
    free(str2);

    return 0;
}


char* take_str_inp(int *str_size){
    int capacity=1;
    char c;
    char *str=(char*)malloc(sizeof(char)*capacity);

    while(scanf("%c",&c) == 1 && c!='\n'){
        if(*str_size >= capacity-1){
            capacity=2*capacity;
            char* temp=(char*)realloc(str,sizeof(char)*capacity);
            if(temp == NULL){
                printf("Memory allocation failed!!");
                free(str);
                return NULL;
            }
            str=temp;
        }
        str[*str_size]=c;
        (*str_size)++;
    }
    str[*str_size]='\0';
    return str;
}


int checker(char str[],char sub_str[],int left,int right){
    
    int str_freq[256]={0};
    int sub_str_freq[256]={0};

    
    for(int i = 0; sub_str[i] != '\0'; i++) {
        sub_str_freq[sub_str[i]]++;
    }
    
    for(int i = left; i <= right; i++) {
        str_freq[str[i]]++;
    }
    
    for(int i = 0; i < 256; i++) {
        if(str_freq[i] < sub_str_freq[i]) {
            return 0;
        }
    }
    return 1;
}

void smallest_window(char str[],char sub_str[],int *left,int *right){
    int min_len=-1;
    for(int i=0;str[i]!='\0';i++){
        for (int j = i; str[j] != '\0'; j++){
            int flag = checker(str,sub_str,i,j);
            if(flag == 1){
                if(min_len == -1 || min_len > j-i+1){
                    min_len=j-i+1;
                    *left=i;
                    *right=j;
                }
            }
        }
    }
}


