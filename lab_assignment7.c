#include <stdio.h>
#include <stdlib.h>

int swapCount[4] = {0, 0, 0, 0}; 

void swap(int *a, int *b, int index)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    swapCount[index]++;
    return;
}

int * selectionSort(int arr[], int n, int idx)
{
    for(int i = 0; i < n - 1; i ++)
    {
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            swap(&arr[minIndex], &arr[i], idx);
        }
    }

    return arr;
    
}

int * bubbleSort(int arr[], int n, int idx)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1], idx);
            }
        }
        
    }
    return arr;
}

int main(void)
{
    int a1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int a2[9] = {90, 80, 70, 60, 50, 40, 30, 20 ,10};

    //selectionSort(a2, 9, 0);
    bubbleSort(a2, 9, 0);
    for(int i = 0; i < 9; i++)
    {
        printf("%d ", a2[i]);
    }
    printf("\n%d", swapCount[0]);
    // used for testing
    

    return 0;

    
}