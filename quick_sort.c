#include<stdio.h>

void printArray(int arr[],int n);
void quickSort(int arr[],int low,int high);
int partition(int arr[],int low,int high);
void swap(int* x,int *y);


int main()
{
    int arrIndx=0;
    int arr[100];
    
    printf("Enter arr elements : ");
    while(scanf("%d",&arr[arrIndx]) == 1){
        arrIndx++;
        if(getchar() == '\n') break;
    }   

    quickSort(arr,0,arrIndx-1);
    printf("\n");
    printArray(arr,arrIndx);

    return 0;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pivotIndex=partition(arr,low,high);
        quickSort(arr,low,pivotIndex-1);
        quickSort(arr,pivotIndex+1,high);
    }
}

int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j){
        while(arr[i] <= pivot  && i<=high-1){
            i++;
        }
        while(j>=low+1 && pivot < arr[j]){
            j--;
        }

        if(j>i) swap(&arr[i],&arr[j]);
    }
    swap(&arr[low],&arr[j]);
    return j;
}


void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
        printf("%d ",arr[i]);
}

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
