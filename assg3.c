#include <stdio.h>
#include <string.h>
#define range_for_number(a) (48<=a && a<=57)

int vowels(char a);


int main() {
    int row,col;
    printf("enter number of rows: ");
    scanf("%d",&row);
    printf("enter number of cols: ");
    scanf("%d",&col);
    getchar();

    char mat[row][col][51];
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
        {
            
            printf("name at (%d,%d) : ",i,j);
            fgets(mat[i][j],50,stdin);
            
            mat[i][j][strlen(mat[i][j])-1]='\0';
            
            for(char *c=mat[i][j];*c!='\0';c++){
                if(range_for_number(*c)){
                    printf("enter correct input");
                    return 0;
                }
            }
            int flg=1;
            for(char *c=mat[i][j];*c!='\0';c++){
                if(*c != ' '){
                    flg=0;
                    break;
                }
            }
            if(flg){
                printf("blank string error");
                return 0;
            }
            
        }
    }
    printf("\n");
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%s ",mat[i][j]); 
        }
        printf("\n");
    }
    printf("\n");  
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(vowels(mat[i][j][0]))
                printf("\n%s starts with vowels ",mat[i][j]); 
        }
        
    }
    int mx_len=0;
    int rindx=0,cindx=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(strlen(mat[i][j]) > mx_len){
                mx_len=strlen(mat[i][j]);
                rindx=i;cindx=j;
            }
                
        }
    }
    printf("\n\nlongest string is : %s",mat[rindx][cindx]);
    return 0;
}


int vowels(char a){
    if(a == 'a' || a=='e' || a=='i' || a=='o' || a=='u' || a == 'A' || a=='E' || a=='I' || a=='O' || a=='U' )
        return 1;
    return 0;
}