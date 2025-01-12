#include<stdio.h>
#include<malloc.h>
#define range_for_number(a) (a>='0' && a<='9')

int flag=1;
int atoi_func(char []);

int main()
{
    char *str=(char*)malloc(sizeof(char)),c;
    int str_size=0;

    printf("Enter string : ");
    while(scanf("%c",&c) == 1 && c!='\n'){
        str[str_size]=c;
        str=(char*)realloc(str,sizeof(char)*(str_size+1));
        str_size++;
    }
    str[str_size]='\0';

    int ans=atoi_func(str);
    if(flag == 1)
        printf("int is : %d",ans);
    else
        printf("invalid characters present");
    return 0;
}

int atoi_func(char str[]){

    int temp=0,sign=1;
    for(int i=0;str[i]!='\0';i++){
        if(range_for_number(str[i]) || str[i] == '-'){
            if(str[i] == '-'){
                sign = -1;
                i++;
            }
            temp=temp*10+(str[i]-'0');
        }
        else {
            flag=0;
            return -1;
        }
    }
    return temp*sign;
}
