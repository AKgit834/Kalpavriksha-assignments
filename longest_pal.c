#include<stdio.h>
#include<stdlib.h>


char *take_str_inp(int*);
int palindrome_checker(char [],int);
int longest_palindrome(char [],int);

int main(int argc, char const *argv[])
{
    char *str;
    int str_size=0;
    printf("Enter string : ");
    str=take_str_inp(&str_size);
    printf("string is : %s\n",str);

    int ans=longest_palindrome(str,str_size);
      
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


int palindrome_checker(char str[],int str_size){
    for(int i=0;i<str_size/2;i++){
        if(str[i] != str[str_size-i-1]){
            return 0;
        }
    }
    return str_size;
}


int longest_palindrome(char str[],int str_size){
    char longest_pal[50];
    int mx_len=0;
    for(int i=0;i<str_size;i++){
        char arr[50];
        int indx=0;
        for (int j = i; j < str_size; j++){
            arr[indx]=str[j];
            indx++;
            arr[indx]='\0';
            int len=palindrome_checker(arr,indx);
            if(len > mx_len){
                mx_len=len;
                for(int j=0;j<indx;j++){
                    longest_pal[j]=arr[j];
                }
            }
        }
    }
    longest_pal[mx_len] = '\0';
    printf("longest pal is : %s",longest_pal);
    return mx_len;
}


