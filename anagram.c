#include<stdio.h>
#include<malloc.h>


char *take_str_inp(int *str_size);
int check_anagram(char str1[],char str2[]);

int main()
{
    int str1_size=0,str2_size=0;
    printf("enter first string : ");
    char *str1=take_str_inp(&str1_size);   
    printf("enter second string : ");
    char *str2=take_str_inp(&str2_size);   

    if(str1_size != str2_size){
        printf("false");
        return 0;
    }

    if(check_anagram(str1,str2)){
        printf("true");
    }
    else{
        printf("false");
    }

    return 0;
}

char* take_str_inp(int *str_size){

    int capacity=1;
    char c;
    char *str=(char*)malloc(sizeof(char)*capacity);

    if (str == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    while(scanf("%c",&c) == 1 && c!='\n'){
        if(*str_size >= capacity-1){
            capacity=2*capacity;
            char* temp=(char*)realloc(str,capacity*sizeof(char));
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


int check_anagram(char str1[],char str2[]){
    int arr1[26]={0};
    int arr2[26]={0};

    for(int i=0;str1[i] != '\0' ;i++){
        arr1[str1[i]-'a']++;
        arr2[str2[i]-'a']++;
    }

    for(int i=0;i<26;i++){
        if(arr1[i] != arr2[i]){
            return 0;
        }
    }
    return 1;

}

