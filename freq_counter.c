#include<stdio.h>
#include<malloc.h>
#include<string.h>

int word_counter(char *);
void remove_spaces(char* str,int);

int main()
{
    char *inp=(char*)malloc(sizeof(char));
    char c;
    int inp_size=0;

    while(inp_size == 0){
        printf("Enter string : ");
        while(scanf("%c",&c) == 1 && c != '\n'){
            inp[inp_size]=c;
            inp_size++;
            inp=(char*)realloc(inp,sizeof(char)*(inp_size+1));
        }
    }
    inp[inp_size]='\0';
    remove_spaces(inp,inp_size);
    printf("total words are : %d\n",word_counter(inp)+1);
    free(inp);
    return 0;
}

int word_counter(char *str){
    int cnt=0;
    for(char *c=str;*c!='\0';c++){
        if(*c == ' ') cnt++;
    }
    return cnt;
}

void remove_spaces(char* str,int str_size){
    int indx=0,i=0,first_space=1,end=str_size-1;

    while(i<str_size && str[i] == ' ') i++;
    while(end >=0 && str[end] == ' ') end--;
    
    str[end+1] = '\0';
    while (str[i] != '\0') {
        if (str[i] != ' '){
            str[indx++] = str[i];
            first_space=1;
        }
        else if(first_space){
            str[indx++]=' ';
            first_space=0;
        }
        i++;
    }
    
    str[indx] = '\0';
}

