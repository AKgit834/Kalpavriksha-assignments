#include<stdio.h>
#include<stdlib.h>
#define range_for_numbers(a) (48 <= a && a <= 57)

void create();
void read();
void update();
void delete(int id);
int findID(int id);

struct user{
    int id;
    char name[60];
    int age;
};

int main()
{
    int ch,t;
    do{
        if(ch == 0) exit(0);
        else if(ch == 1) create();
        else if(ch == 2) read();
        else if(ch == 3) update();
        else if(ch == 4){
            printf("Enter the ID of user : ");
            scanf("%d",&t);
            delete(t);
        }
        else if(ch > 4) printf("choose correct option");
        printf("\n1. Add a new user.\n2. Display all users.");
        printf("\n3. Update a user.\n4. Delete a user.\nEnter any character or 0 for exiting.");
        printf("\n\nChoose the operation to perform : ");
        fflush(stdin);
    }while(scanf("%d",&ch) != 0);

    return 0;
}

void create(){
    struct user u;
    FILE *fp=fopen("users.txt","a");
    printf("Enter the id , age and name of user respectively\n");
    if(scanf("%d%d",&u.id,&u.age) != 2){
        printf("Enter correct id and age");
        return;
    }
    gets(u.name);
    char *c=u.name;
    while(*c != '\0'){
        if(range_for_numbers(*c)){
            printf("Enter name without numebrs");
            return;
        }
        c++;
    }
    if(findID(u.id) == -1)
        fprintf(fp,"%d %s %d\n",u.id,u.name,u.age);
    else
        printf("\nID not unique\n");
    fclose(fp);
}

void read(){
    FILE *fp=fopen("users.txt","r");
    char ch;
    printf("...RECORDS...\n");
    while(1){
        ch=fgetc(fp);
        if(ch == EOF) break;
        printf("%c",ch);
    }
    fclose(fp);
}

void update(){
    struct user u;
    int line,cnt=0;
    char str[50];

    printf("Enter the id of user : ");
    scanf("%d",&u.id);
    printf("Enter the new age and name with space : ");
    scanf("%d",&u.age);
    gets(u.name);

    line=findID(u.id);
    if(line == -1){
        printf("ID not found\n");
    }
    else{
        FILE *f=fopen("users.txt","r");
        FILE *fp=fopen("temp.txt","w");

        while(fgets(str,50,f) != NULL){
            cnt++;
            if(line == cnt){
                delete(u.id);
                fprintf(fp,"%d %s %d\n",u.id,u.name,u.age);
            }
            else
                fputs(str,fp);
        }
        fclose(f);fclose(fp);
        remove("users.txt");
        rename("temp.txt","users.txt");
    }

}

void delete(int id){
    int line,cnt=0;
    FILE *f,*fp;
    char str[50];
    
    //finding the line where the id present.
    line=findID(id);
    f=fopen("temp.txt","w");
    if(f == NULL) printf("cannot open temp file for writing.");
    fp=fopen("users.txt","r");
    if(fp == NULL) printf("cannot open users file for reading.");
    while(fgets(str,50,fp) != NULL){
        cnt++;
        // if line no. is found don't copy that line.
        if(line != cnt){
            fputs(str,f);
        }
    }
    fclose(fp);fclose(f);
    remove("users.txt");
    rename("temp.txt","users.txt");
}

int findID(int id) {
    FILE *f = fopen("users.txt", "r");
    char str[50];
    int line=0; // for determining the line no.
    
    while(fgets(str,50,f) != NULL){
        int i=0,temp=0;
        line++;
        // making the id.
        while(range_for_numbers(str[i])){
            temp=temp*10+str[i++]-'0';
        }
        //ID found.
        if(temp == id){
            fclose(f);
            // printf("\nID %d found on line : %d\n",id,line);
            return line;
        }
    }
    fclose(f);
    return -1; // ID is unique and no line contains the ID to delete.
}
