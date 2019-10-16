#include <stdio.h>

void printArray(int array[], int n)
{
    int i;
    printf("[");
    for (i=0; i<n-1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[i]);
}

int min(int array[], int i, int n)
{
    int m = i, k;
    
    for (k=i+1; k != n-1; k++) {
        if (array[i] < array[m])
            m = i;
    }
    
    return m;
}

void selectionSort(int array[], int n)
{
    int i, j;
    for (i=0; i < n; i++) {
        j = min(array, i, n);
        array[i] = array[j];
    }
}

int main()
{
    
    int array[6] = {6, 5, 4, 3, 2, 1};
    
    selectionSort(array, 6);

    printArray(array, 6);

    return 0;
}