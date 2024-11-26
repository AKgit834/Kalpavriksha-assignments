#include<stdio.h>
#include<stdlib.h>
#define range_for_numbers(a) (48 <= a && a <= 57)


void create();
void read();
void update();
void delete();
int findID(int id);

struct user{
    int id;
    char name[40];
    int age;
};

int main()
{
    int ch;
    while(1){
        printf("\n1. Add a new user.\n2. Display all users.");
        printf("\n3. Update a user.\n4. Delete a user.\n0 for exiting.");
        printf("\n\nChoose the operation to perform : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                create();
                break;
            case 2:
                read();
                break;
            case 3:
                update();
                break;
            case 4:
                delete();
                break;
            default:
                exit(1);
        }
    }

    return 0;
}

void create(){
    struct user u;
    FILE *fp=fopen("users.txt","a");
    printf("Enter the id , age and name of user respectively\n");
    scanf("%d %d",&u.id,&u.age);
    gets(u.name);
    if(findID(u.id) == 1)
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
    printf("Update function is called\n");
}

void delete(){
    int line,id,cnt=0;
    FILE *f,*fp;
    char str[50];

    printf("Enter the ID of user : ");
    scanf("%d",&id);
    
    //finding the line where the id present.
    line=findID(id);
    // printf("\nID %d found on line : %d\n",id,line);
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
            return line;
        }
    }
    fclose(f);
    return 1; // ID is unique and no line contains the ID to delete.
}