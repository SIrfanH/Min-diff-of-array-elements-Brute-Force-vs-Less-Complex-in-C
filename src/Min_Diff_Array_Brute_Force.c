#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;                // for loop indices
    int index1;             // used for storing the index of the first number
    int index2;             // for storing the second number index
    int minDiff;            // stores the minimum difference of two number from the array
    int n, arr[10000];       // size of array and array
    printf("Enter the number of Elements in the Array\n");
    scanf("%d",&n);

    if( n < 2)
    {
        printf("Not Enough Elements\n");
        return 1;
    }

    srand(time(0));         // for generating random number to fill the array
    for(i=0;i<n;i++)
    {
        printf("Enter element %d:\t",i+1);          // filling the array
        //scanf("%d",&arr[i]);
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

    minDiff = abs(arr[0]-arr[1]);       // initial value of minDiff is difference of first two elements of the array
    index1 = 0;
    index2 = 1;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            int difference = abs(arr[i]-arr[j]); // for saving the difference of two elements of the array
            if( minDiff > difference )
            {                                   // if minimum difference(minDiff) is larger than the new difference(difference)
                minDiff = difference;           // minimum difference should get the value of the new difference
                index1 = i;                     // and the indices should be stored in index1 and index2
                index2 = j;
            }
        }
    }
    printf("Elements with smallest difference is %d, %d. The difference is %d, indices are %d, %d\n",arr[index1],arr[index2] , minDiff,index1,index2);
    return 0;
}
