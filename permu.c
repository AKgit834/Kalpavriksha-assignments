#include<stdio.h>
#include<string.h>

void swap(char *,char *);
int factorial(int );
void permute(char *, int , int );

int main() {
    char str[100];
    int indx = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    int n = strlen(str);
    permute(str, 0, n - 1);


    return 0;
}


int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void swap(char *x,char *y){
    char temp=*x;
    *x=*y;
    *y=temp;
}

void permute(char *str, int left, int right) {
    if (left == right) {
        printf("%s\n",str);
    } 
    else {
        for (int i = left; i <= right; i++) {
            swap(&str[left], &str[i]); 
            permute(str, left + 1, right);
            swap(&str[left], &str[i]);
        }
    }
}




