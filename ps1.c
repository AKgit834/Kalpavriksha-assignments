#include<stdio.h>
#include<malloc.h>

void dup_remover(char *inp);
int dup_checker(char *str,char c);


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
    dup_remover(inp);
    return 0;
}


void dup_remover(char *inp){
    char *str=(char*)malloc(sizeof(char));
    int str_size=0;

    for(char *c=inp;*c!='\0';c++){
        if(dup_checker(str,*c))
        {
            str[str_size]=*c;
            str=(char*)realloc(str,sizeof(char)*(str_size+1));
            str_size++;
        }
    }
    str[str_size]='\0';
    printf("after removing duplicate characters : %s",str);

}


int dup_checker(char *str,char c){
    for(char *temp=str;*temp!='\0';temp++){
        if(c == *temp) return 0;
    }
    return 1;
}


