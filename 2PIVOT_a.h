#ifndef _2PIVOT_a_H_
#define _2PIVOT_a_H_

#include<stdio.h>

void swap2a(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition2a(int arr[], int low, int high, int *lp)
{
    // make arr[low] < arr[high]
    if(arr[low] > arr[high])
        swap2a(&arr[low], &arr[high]);
    
    int j = low+1;      // left pointer for insert
    int k = low+1;      // scan the full array

    int g = high-1;     // right pointer for insert

    int p = arr[low];    // left pivot
    int q = arr[high];  // right pivot

    while(k <= g)
    {
        // current elements less than left pivot
        if(arr[k] < p)
        {
            swap2a(&arr[k], &arr[j]);
            ++j;
        }

        // current elements greater than right pivot
        else if( arr[k] >= q)
        {
            // decrement right poiter
            while(arr[g] > q && k < g)
                --g;
            
            // swap right pointer and the current elements
            swap2a(&arr[k], &arr[g]);
            --g;

            // check the swaped elements, and rearrange it
            if(arr[k] < p)
            {
                swap2a(&arr[k], &arr[j]);
                ++j;
            }
        }

        // scan the whole array
        ++k;
    
    }

    // move the left pivot in its place
    --j;
    swap2a(&arr[j], &arr[low]);

    // move the right pivot in its place
    ++g;
    swap2a(&arr[g], &arr[high]);

    // index of the left pivot
    *lp = j;

    // index of the right pivot
    return g;
}

void dualPivotQuickSort2a(int arr[], int low, int high)
{
    if(low<high)
    {
        int lp, rp;

        rp = partition2a(arr, low, high, &lp);
        dualPivotQuickSort2a(arr,low,lp-1);
        dualPivotQuickSort2a(arr,lp+1,rp-1);
        dualPivotQuickSort2a(arr, rp+1,high);
    }
}
#endif



