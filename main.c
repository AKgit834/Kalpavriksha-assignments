#include<stdio.h>
#include<math.h>

void power(int , int );
int multiply(int ,int [],int );


int main()
{
    int b,m,n,last;

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

    power(b,n);
    return 0;
}


void power(int b,int n) {
    int res[100];
    int size=0,temp=b;

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

}

int multiply(int b,int res[],int size){
    int product,carry=0;

    for(int i=0;i<size;i++){
        product=res[i]*b+carry;
        carry=product/10;
        res[i]=product%10;
    }

    while(carry){
        res[size]=carry%10;
        carry=carry/10;
        size++;
    }
    return size;
}

