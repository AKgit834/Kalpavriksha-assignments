#include<stdio.h>
#include<malloc.h>
#include<string.h>

int counter(char *);
void remove_space(char* str,int);
void print_str(char *str);

int main()
{
    char *inp=(char*)malloc(sizeof(char));
    char c;
    int inp_size=0;
    printf("Enter string : ");
    while(scanf("%c",&c) == 1 && c != '\n'){
        inp[inp_size]=c;
        inp_size++;
        inp=(char*)realloc(inp,sizeof(char)*(inp_size+1));
    }
    if(inp_size == 0){
        printf("Empty expression");
        return 0;
    }
    inp[inp_size]='\0';
    remove_space(inp,inp_size);
    printf("total words are : %d\n",counter(inp)+1);
    // printf("string len : %d",strlen(inp));
    print_str(inp);
    return 0;
}

int counter(char *str){
    
    int cnt=0;
    for(char *c=str;*c!='\0';c++){
        if(*c == ' ') cnt++;
    }
    return cnt;
}

void remove_space(char* str,int str_size){
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
    // printf("%s",str);
}

void print_str(char *str){
    for(char *c=str;*c!='\0';c++){
        if(*c == ' ') printf("@");
        else printf("%c",*c);
    }
}


