#include<stdio.h>

void power(int , int ,int);// funciton for calculating power.
int multiply(int ,int [],int );//for multiplying the number again and again.
int mod(int [],int ,int );// calculating mod.


int main()
{
    int b,m,n,last;

    //taking input.
    printf("Enter vlaue of b , n and m : ");
    if(scanf("%d%d%d",&b,&n,&m) != 3){
        printf("invalid input in scanf");
        return 0;
    }
    printf("b: %d, n: %d, m: %d",b,n,m);
    if(b<0 || n<0 || m<=1){
        printf("invalid input in value");
        return 0;
    }

    power(b,n,m);
    return 0;
}


void power(int b,int n,int m) {
    int res[10000]; // stores the calculated number.
    int size=0,temp=b;

    //entering values in array.
    while(temp){
        res[size]=temp%10;
        temp=temp/10;
        size++;
    }

    for(int i=2;i<=n;i++)
        size=multiply(b,res,size);

    //printing the value.
    printf("\n\npower is : ");
    for(int i=size-1;i>=0;i--)
        printf("%d",res[i]);
    printf("\n");

    printf("\nremainder of %d^%d mod %d is : %d",b,n,m,mod(res,size,m));
}

int multiply(int b,int res[],int size){
    int product,carry=0;

    //multiplying every digit in res[] with the base.
    for(int i=0;i<size;i++){
        product=res[i]*b+carry;
        carry=product/10;
        res[i]=product%10;
    }

    //handling remaining carry.
    while(carry){
        res[size]=carry%10;
        carry=carry/10;
        size++;
    }
    return size;
}


int mod(int res[],int size,int m){
    int rem=0;
    for(int i=size-1;i>=0;i--)
        rem=(rem*10+res[i])%m;
    return rem;
}

