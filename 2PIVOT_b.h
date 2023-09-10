#ifndef _2PIVOT_b_H_
#define _2PIVOT_b_H_

#include<stdio.h>

void swap2b(int *a, int *b)
{
    int terp = *a;
    *a = *b;
    *b = terp;
}

int partition2b(int arr[], int low, int high, int *rp)
{

    // make arr[low] < arr[low+1]
    if(arr[low] > arr[low+1])
        swap2b(&arr[low], &arr[low+1]);
    

    // pointer for insert elements which are less than the left pivot
    int a = low+2;

    // pointer for insert elements which are less than the right pivot
    int b = low+2;

    int k = b;      // scan the whole array

    int p = arr[low];       // left pivot
    int q = arr[low+1];     // right pivot


    // traversing the whole array
    while (k <= high)
    {

        // element less than right pivot
        if(arr[k] < q)
        {
            // elements less than left pivot
           if(arr[k] < p)
           {
               // insert in the first part
                swap2b(&arr[b],&arr[k]);    // moving the bigger element in third part
                swap2b(&arr[a],&arr[b]);    // move the smaller elements in the first part

                ++a;        // always point the one step ahead from where first part end. 

                ++b;        // always point the one step ahead from where second part end.
           }
           else
           {
                // insert in the second part

                //arr[b] points the elements greater than right pivot
                //  we bring the smaller elements at that point
                swap2b(&arr[b], &arr[k]);
                ++b;
           }
        }
        else
        {
            // do nothing
            // arr[left pivot] < arr[right pivot]
            // if we consider the elements lower than right pivot and
            // placed them in the currect subarray than elements 
            // higher than the right pivot automatically moves at the end part of the array
        }

        // scan the whole array
        ++k;
    }

    --a;      // now a points end of the first sub array

    // low+1 = right pivot = rp
    //  lp  rp        a     b
    // [5,  10, 2, 3, 4, 7, 6, 20, 29 ]
    swap2b(&arr[a],&arr[low+1]);        // 
    //  lp rp        a         b
  //  [ 5, 4, 2, 3, 10, 7, 6, 20, 29 ]


    --b;
    //  lp rp        a     b
  //  [ 5, 4, 2, 3, 10, 7, 6, 20, 29 ]
    swap2b(&arr[a], &arr[b]);
    //  lp rp       a      b
  //  [ 5, 4, 2, 3, 6, 7, 10, 20, 29 ]

    --a;
    //  lp rp    a         b
  //  [ 5, 4, 2, 3, 6, 7, 10, 20, 29 ]
    swap2b(&arr[low], &arr[a]);             // low = lp = left pivot
    //  lp rp    a         b
  //  [ 3, 4, 2, 5, 6, 7, 10, 20, 29 ]    

    // index of the right pivot
    *rp = b;

    //  lp       a         rp
  //  [ 3, 4, 2, 5, 6, 7, 10, 20, 29 ] 
    
    // arr[a] = 5 -> left pivot
    // arr[rp] = 10 -> right pivot

    // index of the left pivot
    return a;
}

void dualPivotQuickSort2b(int arr[], int low, int high)
{
    if(low<high)
    {
        int lp,rp;

        lp = partition2b(arr,low,high, &rp);

        dualPivotQuickSort2b(arr,low,lp-1);
        dualPivotQuickSort2b(arr,lp+1,rp-1);
        dualPivotQuickSort2b(arr,rp+1, high);

    }
}

#endif

