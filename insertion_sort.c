#include<stdio.h>


void insertion_sort(int[],int);

int main()
{
    int arr[100];
    int arr_indx=0;

    printf("Enter elements : ");
    while(scanf("%d",&arr[arr_indx]) == 1){
        arr_indx++;
        if(getchar()=='\n') break;
    }

    insertion_sort(arr,arr_indx);

    for (int i = 0; i < arr_indx; i++)
        printf("%d ",arr[i]);
    

    return 0;
}


void insertion_sort(int arr[],int n){
    
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

