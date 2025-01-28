#include<stdio.h>


void insertionSort(int arr[],int n);

int main()
{
    int arr[100];
    int arrIndx=0;

    printf("Enter elements : ");
    while(scanf("%d",&arr[arrIndx]) == 1){
        arrIndx++;
        if(getchar()=='\n') break;
    }

    insertionSort(arr,arrIndx);

    for (int i = 0; i < arrIndx; i++)
        printf("%d ",arr[i]);
    return 0;
}


void insertionSort(int arr[],int n){
    for (int i=1;i<n;i++) {
            int key=arr[i];
            int j=i-1;
            
            while (j >= 0 && arr[j] > key) {
                arr[j + 1]=arr[j];
                j--;
            }
            arr[j + 1] = key;
    }
}

