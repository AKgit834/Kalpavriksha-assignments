#include<stdio.h>
#include<stdlib.h>
#define range_for_number(a) (a>='0' && a<='9')


char* take_str_inp(int *);
int validate(char [],int);


int main()
{
    char* ip_address;
    int ip_address_size=0;
    
    printf("Enter ip address : ");
    ip_address=take_str_inp(&ip_address_size);
    printf("string is : %s\n",ip_address);
    int ans = validate(ip_address,ip_address_size);
    if(ans == 1)
        printf("ip address is valid");
    else
        printf("ip address is not valid");

    free(ip_address);
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


int validate(char ip_address[],int ip_address_size){
    int arr[4]={-1,-1,-1,-1};
    int indx=0;
    for (int i = 0; ip_address[i] != '\0' ; i++)
    {
        if(!range_for_number(ip_address[i]) && ip_address[i] != '.'){
            // printf("returning because char at : %d position is : %c\n",i,ip_address[i]);
            return 0;
        }
        else if(ip_address[i] == '.'){
            indx++;
            // if(ip_address)
        }
        else {
            int temp=0;
            while(ip_address[i] != '.' && i<ip_address_size){
                temp=temp*10+(ip_address[i]-'0');
                if(temp == 0 && ip_address[i+1]!='.') return 0;
                i++;
            }
            i--;
            if(temp > 255 || temp<0) return 0;
            arr[indx]=temp;
        }
    }
    for(int i=0;i<4;i++){
        if(arr[i] == -1) return 0;
        // printf("arr[%d] is : %d\n",i,arr[i]);
    }
    return 1;
}





