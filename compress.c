#include<stdio.h>
#include<stdlib.h>


char* take_str_inp(int *);
int compress(char*,int);

int main(int argc, char const *argv[])
{
    int str_size=0;
    char *str;

    printf("Enter string : ");
    str=take_str_inp(&str_size);

    int return_flag = compress(str,str_size);
    if(return_flag == 0) printf("%s",str);
    
    return 0;
}


char* take_str_inp(int *str_size){
    int capacity=8;
    char *str=(char*)malloc(sizeof(char)*capacity);
    char c;
    
    while(scanf("%c",&c) == 1 && c!='\n'){
        if(*str_size >= capacity-1){
            capacity=2*capacity;
            char* temp=(char*)realloc(str,sizeof(char)*capacity);
            if(temp == NULL){
                printf("Memory allocation failed");
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


int compress(char *str,int str_size){
    char freq[26]={0};
    int flg=1;
    char temp[52];
    int indx=0;

    for(int i=0;str[i] != '\0' ;i++){
        freq[str[i] - 'a']++;
        if(freq[str[i] - 'a'] > 1) flg=0;
    }
    if(flg == 1) return 0;

    for(int i=0;i<26;i++){
        if(freq[i] > 0){
            temp[indx]='a'+i;
            indx++;
            temp[indx]=freq[i]+'0';
            indx++;
        }
    } 

    for (int i = 0; i < indx; i++)
    {
        printf("%c",temp[i]);
    }
    
    return 1;
}

