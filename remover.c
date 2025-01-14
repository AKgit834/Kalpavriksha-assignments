#include<stdio.h>
#include<stdlib.h>

char* take_str_inp(int *);
int remove_adj_dup(char*,int);
void rem_all_dup(char* ,int);


int main() {
    char *str;
    int str_size=0;
    
    printf("Enter string : ");
    str=take_str_inp(&str_size);
    
    rem_all_dup(str,str_size);
    printf("After removing duplicates: %s\n", str);
    
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



int remove_adj_dup(char* str,int str_size) {
    int flag = 0;
    int read_pos = 0,write_pos = 0;
    
    while (read_pos < str_size) {
        if(read_pos < str_size - 1 && str[read_pos] == str[read_pos + 1]){
            str[write_pos] = str[read_pos];
            write_pos++;
            
            while(read_pos < str_size - 1 && str[read_pos] == str[read_pos + 1]){
                read_pos++;
            }
        }
        else{
            str[write_pos] = str[read_pos];
            write_pos++;
        }
        read_pos++;
    }
    
    str[write_pos] = '\0';
    return flag;
}

void rem_all_dup(char* str,int str_size) {
    while (remove_adj_dup(str,str_size));
}



