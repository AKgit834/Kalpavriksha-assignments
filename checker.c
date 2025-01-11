#include<stdio.h>

int str_len(char []);
void concatenate(char [],char *,int);
int sub_string_finder(char *str,char *sub_str);

int main()
{
    char str1[100],str2[100];
    int str1_size,str2_size;

    printf("Enter first string : ");
    scanf("%[^\n]s",str1);
    getchar();
    printf("Enter second string : ");
    scanf("%[^\n]s",str2);

    str1_size=str_len(str1);
    str2_size=str_len(str2);
    if(str1_size != str2_size){
        printf("false");
        return 0;
    }

    printf("string1 is : %s with size : %d\n",str1,str1_size);
    printf("string2 is : %s with size : %d\n",str2,str2_size);

    char concated_str[200];
    concatenate(str1,concated_str,str1_size);
    printf("\nconcated string is : %s\n",concated_str);
    int ans=sub_string_finder(concated_str,str2);
    if(ans!=-1)
        printf("true");
    else
        printf("false");

    return 0;
}

int str_len(char str[]){
    int cnt=0;
    for(int i=0;str[i]!='\0';i++)
        cnt++;
    return cnt;
}

void concatenate(char str[],char *concated_str,int str_size){
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
