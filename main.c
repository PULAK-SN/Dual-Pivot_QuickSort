#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "2PIVOT_a.h"
#include "2PIVOT_b.h"

int main()
{
    
    int SIZE = 18000;
    printf("\n--------\t\t---------- SIZE = %d --------\t\t----------\n",SIZE);
    int arrA[SIZE],arrB[SIZE];

    for(int i=0; i<SIZE; ++i)
        arrA[i] = arrB[i] = rand()%(2*SIZE);

    double time_spent = 0.0;
    clock_t begin, end;

 // ------------------------------------------------------------------
    begin = clock();
    dualPivotQuickSort2a(arrA,0,SIZE-1);

    end = clock();

    time_spent = (double)(end - begin) * 1000.0 / (double)CLOCKS_PER_SEC;;
    printf("\nI -A Pivot -> The elapsed time is %f ms", time_spent);

// ------------------------------------------------------------------

    begin = clock();

    dualPivotQuickSort2b(arrB,0,SIZE-1);

    end = clock();

    time_spent = (double)(end - begin) * 1000.0 / (double)CLOCKS_PER_SEC;
    printf("\nI -B Pivot -> The elapsed time is %f ms", time_spent);
    
    // -------------------------------------------------------------
    printf("\n");

    return 0;
}

