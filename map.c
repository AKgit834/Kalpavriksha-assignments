#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAME_SIZE 30
#define TABLE_SIZE 100


typedef struct person{
    char name[NAME_SIZE];
    int age;
}person;


person *hashTable[TABLE_SIZE];
int hashFunction(char name[]);
void initHashTable();
void insert(person p);
void display();
void delete();
person* search(char name[]);

int main()
{
    int choice;
    

    initHashTable();
    printf("\toperations\n1. insert\n2. Search\n3. Delete\n4. Display\n5. exit\n");
    printf("Enter choice : ");
    while(scanf("%d",&choice) == 1){
        if(choice == 1){
            person p;
            printf("Enter key and value : ");
            scanf("%s %d",&p.name,&p.age);
            insert(p);
        }else if(choice == 2){
            char name[NAME_SIZE];
            printf("Enter person to search : ");
            scanf("%s",name);
            person *p=search(name);
            (p)?printf("name : %s,age : %d\n",p->name,p->age):printf("Not present\n");
        }else if(choice == 3){
            char name[NAME_SIZE];
            printf("Enter person to delete : ");
            scanf("%s",name);
            delete(name);
        }else if(choice == 4){
            display();
        }else{
            exit(1);
        }
        printf("Enter choice : ");
    }
    
    return 0;
}

void initHashTable(){
    for (int i = 0; i < TABLE_SIZE; i++){
        hashTable[i]=NULL;
    }
}

int hashFunction(char name[]){
    int hashValue=0;
    for(int i=0;i<strlen(name);i++){
        hashValue=hashValue+name[i];
    }
    return hashValue%TABLE_SIZE;
}

void insert(person p){
    int indexInHashTable=hashFunction(p.name);
    if(hashTable[indexInHashTable] != NULL) return;
    person *newPerson=(person*)malloc(sizeof(person));
    strcpy(newPerson->name,p.name);
    newPerson->age=p.age;
    hashTable[indexInHashTable]=newPerson;
}

person* search(char name[]){
    int indexInHashTable=hashFunction(name);
    if(hashTable[indexInHashTable] && strcmp(hashTable[indexInHashTable]->name,name) == 0)
        return hashTable[indexInHashTable];
    return NULL;
}

void delete(char name[]){
    int indexInHashTable=hashFunction(name);
    if(hashTable[indexInHashTable] && strcmp(hashTable[indexInHashTable]->name,name) == 0){
        free(hashTable[indexInHashTable]);
        hashTable[indexInHashTable]=NULL;
        printf("Person deleted\n");
    }else{
        printf("Person not found\n");
    }
    return;
}


void display(){
    for (int i = 0; i < TABLE_SIZE; i++)
        if(hashTable[i]) printf("index : %d,%s:%d\n",i,hashTable[i]->name,hashTable[i]->age);
}


