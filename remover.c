#include<stdio.h>
#include<stdlib.h>

char* take_str_inp(int *);
void remove_char(char *str,char ch);


int main()
{
    char *str,ch;
    int str_size=0;
    printf("Enter string : ");
    str=take_str_inp(&str_size);
    printf("Enter char to remove : ");
    scanf("%c",&ch);

    remove_char(str,ch);
    printf("after removal : %s",str);
    return 0;
}

char* take_str_inp(int *str_size){
    int capacity=8;
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

void remove_char(char* str,char ch){
    // char temp[];
    int indx=0;
    for (int i = 0;str[i]!='\0'; i++){
        if(str[i] == ch) continue;
        str[indx]=str[i];
        indx++;
    }
    str[indx]='\0';
    

}

