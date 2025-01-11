#include<stdio.h>
#include<malloc.h>

int sub_string_finder(char *str,char *sub_str);
void print_str(char *str);

int main()
{
    char *str=NULL,*sub_str=NULL,c;
    int str_size=0,sub_str_size=0;
    printf("Enter the first string : ");
    while(scanf("%c",&c) == 1 && c !='\n'){
        str=realloc(str,str_size+1);
        str[str_size]=c;
        str_size++;
    }
    str[str_size]='\0';
    printf("\nEnter the sub-string : ");
    while(scanf("%c",&c) == 1 && c !='\n'){
        sub_str=realloc(sub_str,sub_str_size+1);
        sub_str[sub_str_size]=c;
        sub_str_size++;
    }
    sub_str[sub_str_size]='\0';
    printf("\nstring is : %s\n",str);
    printf("sub-string is : %s",sub_str);
    // print_str(str);
    // print_str(sub_str);
    int ans = sub_string_finder(str,sub_str);
    if(ans)
        printf("\nsub-string is present at index : %d",ans);
    else
        printf("\nsub-string is not present");
    return 0;
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

void print_str(char *str){
    for(int i=0;str[i]!='\0';i++){
        if(str[i] == ' ')
            printf("@");
        else
            printf("%c",str[i]);
    }
    printf("\n");
}

