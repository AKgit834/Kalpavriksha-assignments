#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAME_SIZE 30
#define TABLE_SIZE 100


typedef struct person{
    char name[NAME_SIZE];
    int age;
    struct person *next;
}person;


person *hashTable[TABLE_SIZE];
int hashFunction(char name[]);
void initHashTable();
void insert(person p);
void display();
void delete();
void freeMemory();
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
            freeMemory();
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
    if(hashTable[indexInHashTable]){
        person *temp=hashTable[indexInHashTable];
        person *prev=NULL; 
        // update the value if person already present.
        while(temp){
            if(strcmp(temp->name,p.name) == 0){
                temp->age=p.age;
                return;
            }
            prev=temp;
            temp=temp->next;
        }
        person *newPerson=(person*)malloc(sizeof(person));
        strcpy(newPerson->name,p.name);
        newPerson->age=p.age;
        newPerson->next=NULL;
        prev->next=newPerson;
        return;
    }
    person *newPerson=(person*)malloc(sizeof(person));
    strcpy(newPerson->name,p.name);
    newPerson->age=p.age;
    newPerson->next=NULL;
    hashTable[indexInHashTable]=newPerson;
}

person* search(char name[]){
    int indexInHashTable=hashFunction(name);
    if(hashTable[indexInHashTable]){
        person *currPerson=hashTable[indexInHashTable];
        while(currPerson){
            if(strcmp(currPerson->name,name) == 0){
                return currPerson;
            }
            currPerson=currPerson->next;
        }
    }
    return NULL;
}

void delete(char name[]){
    int indexInHashTable=hashFunction(name);
    if(hashTable[indexInHashTable]){
        person *currPerson=hashTable[indexInHashTable];
        person *prev=NULL;
        while(currPerson){
            if(strcmp(currPerson->name,name) == 0){
                if(currPerson->next){
                    if(prev){
                        prev->next=currPerson->next;
                        free(currPerson);
                    }else{
                        hashTable[indexInHashTable]=currPerson->next;
                        free(currPerson);
                    }
                }else if(prev){
                    prev->next=NULL;
                    free(currPerson);
                }
                else{
                    hashTable[indexInHashTable]=NULL;
                    free(currPerson);
                }
                return;
            }
            prev=currPerson;
            currPerson=currPerson->next;
        }
    }
    return;
}


void display(){
    for (int i = 0; i < TABLE_SIZE; i++){
        if(hashTable[i]){
            printf("| index : %d,%s:%d | ",i,hashTable[i]->name,hashTable[i]->age);
            person* currPerson=hashTable[i]->next;
            while(currPerson){
                printf("->| index : %d,%s:%d | ",i,currPerson->name,currPerson->age);
                currPerson=currPerson->next;
            }
            printf("\n");
        }
    }
}

void freeMemory(){
    for (int i = 0; i < TABLE_SIZE; i++){
        person* currPerson = hashTable[i];
        while (currPerson != NULL) {
            person* temp = currPerson;
            currPerson = currPerson->next;
            free(temp);
        }
    }
    
}
