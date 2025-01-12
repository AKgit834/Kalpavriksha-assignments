#include<stdio.h>
#include<stdlib.h>

typedef struct map{
    char word[50];
    int len;
}map;

char* take_str_inp(int *str_size);
void longest_word_finder(char*,int);

int main()
{
    char *str;
    int str_size=0;
    printf("Enter string : ");
    str=take_str_inp(&str_size);

    longest_word_finder(str,str_size);
    free(str);

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


void longest_word_finder(char *str,int str_size){
    map words[30];
    int words_indx=0;
    int mx_len_word_indx=0,mx_len=0;

    for(int i=0;str[i]!='\0';i++){
        if(str[i] == ' ') continue;

        int indx=0;
        while(str[i] != ' ' && str[i] !='\0' && i<str_size){
            words[words_indx].word[indx]=str[i];
            indx++;
            printf("i: %d for char %c\n",i,str[i]);
            i++;
        }

        words[words_indx].word[indx]='\0';
        words[words_indx].len=indx;
        if(words[words_indx].len >= mx_len){
            mx_len_word_indx=words_indx;
            mx_len=words[words_indx].len;
        }
        words_indx++;
    }
    printf("max len word is : %s",words[mx_len_word_indx].word);
}



