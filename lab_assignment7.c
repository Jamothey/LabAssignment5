#include <stdio.h>
#include <stdlib.h>

int swapCount[4] = {0, 0, 0, 0};
int indexCounter[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int numIndex[18] = {97, 16, 45, 63, 13, 22, 7, 58, 72, 90, 80, 70, 60, 50, 40, 30, 20,10};
int reseterNumIndex[18] = {97, 16, 45, 63, 13, 22, 7, 58, 72, 90, 80, 70, 60, 50, 40, 30, 20,10};


void swap(int *a, int *b, int index)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    swapCount[index]++;
    for(int i = 0; i < 18; i++)
    {
        if(numIndex[i] == *a || numIndex[i] == *b)
        {
            indexCounter[i]++;
        }
    }
    return;
}

void swapIndexes(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
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

void resetCounter(void)
{
    for(int i = 0; i < 18; i++)
    {
        indexCounter[i] = 0;
        numIndex[i] = reseterNumIndex[i];
    }
}

void orderIndexes(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 18; j++)
        {
            if(arr[i] == numIndex[j])
            {
                swapIndexes(&indexCounter[j], &indexCounter[i]);
                swapIndexes(&numIndex[i], &numIndex[j]);
            }
        }
    }
    return;
}


int main(void)
{
    int a1sS[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int a1bS[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int a2sS[9] = {90, 80, 70, 60, 50, 40, 30, 20,10};
    int a2bS[9] = {90, 80, 70, 60, 50, 40, 30, 20,10};

    printf("array1:\n\n");
    selectionSort(a1sS, 9, 0);
    orderIndexes(a1sS, 9);
    printf("Selection Sort:\n");
    for(int i = 0; i < 9; i++)
    {
        printf("%02d : %02d\n", a1sS[i], indexCounter[i]);
    }
    printf("Total Swaps: %02d\n\n", swapCount[0]);
    resetCounter();
    bubbleSort(a1bS, 9, 1);
    orderIndexes(a1bS, 9);
    printf("Bubble Sort:\n");
    for(int i = 0; i < 9; i++)
    {
        printf("%02d : %02d\n", numIndex[i], indexCounter[i]);
    }
    printf("Total Swaps: %02d\n\n", swapCount[1]);
    resetCounter();
    printf("array2:\n\n");
    selectionSort(a2sS, 9, 2);
    orderIndexes(a2sS, 9);
    printf("Selection Sort:\n");
    for(int i = 0; i < 9; i++)
    {
        printf("%02d : %02d\n", numIndex[i], indexCounter[i]);
    }
    printf("Total Swaps: %02d\n\n", swapCount[2]);
    resetCounter();
    bubbleSort(a2bS, 9, 3);
    orderIndexes(a2bS, 9);
    printf("Bubble Sort:\n");
    for(int i = 0; i < 9; i++)
    {
        printf("%02d : %02d\n", numIndex[i], indexCounter[i]);
    }
    printf("Total Swaps: %02d\n\n", swapCount[3]);
    resetCounter();

    return 0;

    
}