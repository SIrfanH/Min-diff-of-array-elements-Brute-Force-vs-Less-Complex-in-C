#include <stdio.h>
#include <stdlib.h>
void mergesort(int arr[], int left, int right);
void merge(int arr[], int l, int m, int r);
int main()
{
    int i;                // For loop indices
    int index1;             // Used for storing the index of the first number
    int index2;             // For storing the second number index
    int minDiff;            // Stores the minimum difference of two number from the array
    int n, arr[10000];       // Size of array and array

    printf("Enter the number of Elements for the Array\n");
    scanf("%d",&n);

    if( n < 2)
    {
        printf("Not Enough Elements\n");
        return 1;
    }

    srand(time(0));         // For generating random number to fill the array
    for(i=0;i<n;i++)
    {
        printf("Enter element %d:\t",i+1);          // Filling the array
        arr[i]=rand();
        printf("%d\n",arr[i]);
    }
    /*
    for(i=0;i<n;i++)
    {
        printf("Enter element %d:\t",i+1);
        scanf("%d",&arr[i]);
        printf("%d\n",arr[i]);
    }*/

    mergesort(arr,0,n-1);           // Sorting the array before finding the minimum difference
    minDiff = abs(arr[0]-arr[1]);   // Initializing the value of minDiff by finding the difference of first two element
    index1 = 0;
    index2 = 1;                     // Filling the initial values
    for(i=0;i<n-1;i++)
    {
        int difference = abs(arr[i]-arr[i+1]);
        if(minDiff > difference)
        {
            minDiff = difference;
            index1 = i;
            index2 = i+1;
        }
    }
    printf("Elements with smallest difference is %d, %d. The difference is %d ",arr[index1],arr[index2] , minDiff);

    return 0;
}

void mergesort(int arr[], int left, int right)
{
    if(left<right)
    {
        int middle = (left+right)/2;

        mergesort(arr,left,middle);
        mergesort(arr,middle+1,right);

        merge(arr,left,middle,right);
    }
}

void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;


    int L[n1], R[n2];           // Create temp arrays


    for (i = 0; i < n1; i++)    // Copy data to temp arrays L[] and R[] */
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0;          // Initial index of first subarray
    j = 0;          // Initial index of second subarray
    k = left;       // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
