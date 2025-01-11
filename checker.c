#include<stdio.h>
#include<malloc.h>

char* take_str_inp(int *);
void concatenate(char *,char *,int);
int sub_string_finder(char *str,char *sub_str);

int main()
{
    char *str1=(char*)malloc(sizeof(char)),*str2=(char*)malloc(sizeof(char));
    int str1_size,str2_size;

    printf("Enter first string : ");
    str1=take_str_inp(&str1_size);
    printf("Enter second string : ");
    str2=take_str_inp(&str2_size);

    if(str1_size != str2_size){
        printf("false");
        return 0;
    }

    // printf("string1 is : %s with size : %d\n",str1,str1_size);
    // printf("string2 is : %s with size : %d\n",str2,str2_size);

    char *concated_str=(char*)malloc(sizeof(char)*(2*str1_size + 1));
    concatenate(str1,concated_str,str1_size);
    // printf("\nconcated string is : %s\n",concated_str);
    int ans=sub_string_finder(concated_str,str2);
    if(ans>0)
        printf("true");
    else
        printf("false");
    
    free(str1);free(str2);free(concated_str);

    return 0;
}


char* take_str_inp(int *str_size){
    char *str=(char*)malloc(sizeof(char)),c;
    *str_size=0;
    while(scanf("%c",&c) && c!='\n'){
        str=(char*)realloc(str,sizeof(char)*(*str_size+1));
        if (str == NULL) {
            printf("memory allocation failed\n");
            return NULL;
        }
        str[*str_size]=c;
        (*str_size)++;
    }
    str[*str_size]='\0';
    return str;
}


void concatenate(char *str,char *concated_str,int str_size){
    // printf("inside concate");
    for (int i = 0; i < str_size; i++) {
        concated_str[i] = str[i];
    }
    for (int i = 0; i < str_size; i++) {
        concated_str[i + str_size] = str[i];
    }
    concated_str[2 * str_size] = '\0';
}

int sub_string_finder(char *str,char *sub_str){
    for(int i=0;str[i]!='\0';i++){
        int indx=i,flg=1;
        for(int j=0;sub_str[j]!='\0';j++){
            if(str[indx] != sub_str[j]){
                flg=0;
                break;
            }
            indx++;
        }
        if(flg) return i;
    }
    return -1;
}
