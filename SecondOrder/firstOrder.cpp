#include "firstOrder.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>

#include <stdio.h>
#include <stdlib.h>
#include <new>
#include <sstream>

using namespace std;


#include <stdio.h>
#include <stdlib.h>
#include <new>
#include <sstream>

#include "firstOrder.h"
#include "secondOrder.h"

//#define N 10

//#define printFillSums
//#define printRepeat
//#define printArrays
//#define printSavedSums
//#define printCycles


First :: First(int * a, int l ) 
  : N(l)
{}

int First::getLength()
{

	return N;
}


void printArray(int * array, int length)
{
        int i;
        for(i = 0; i < length; i++)
        {
                printf("%d ",array[i]);

        }
        printf("\n");
}

void First::printArrayComma(int * array, int length)
{
	
	if(iteration + length > N)
	{
		#ifdef printCycles
		printf("Cycle:%d Iter=%d L:%d ", cycle_iteration, iteration, length);  
		#endif

		cycle_iteration++;
		iteration = length;
		#ifdef printArrays
		printf("\n");
		#endif

	}
	else
	{
		iteration = iteration + length;
	}
	#ifdef printArrays
	printf("\n");
	#endif

	cycle++;               	
	cycle_sums += length;

	int i;
        for(i = 0; i < length; i++)
        {
		#ifdef printArrays
                printf("%d,",array[i]);
		#endif

        }
	#ifdef printArrays
        printf("   ");
	#endif
	
}



int First::inSums(int t)
{
	int i;
	for(i = 0; i < totalSums; i++)
	{
		if(t == sums[i])
		{
			#ifdef printFillSums
			printf(" in sums\n");
			#endif
			return 0;
		}
	}
	#ifdef printFillSums
	printf(" added\n");
	#endif
	sums[runningSums++] = t;
	return 1;
}

int First::fillSums(int * a, int length)
{
	int i = 0;
	int j = 0;
	int newSum = 0;
	for(i ; i < length; i++)
	{
		int sum = 0;
		for(j = 0; j < length; j++)
		{
			if(i+j < length)
			{
				sum += a[i+j];	
			}
			//sum += a[ (i+j)%length ];
			#ifdef printFillSums
			printf("s:%d", sum);
			#endif
			newSum += inSums(sum);
		}
		//printf("\n");
		
	}

	#ifdef printFillSums
	printf("NewSum:%d\n", newSum);
	#endif
	return newSum;
}



// Program to print all combination of size r in an array of size n
//void combinationUtil(int arr[], int data[], int start, int end, int index, int r);
 
// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void First::printCombination(int arr[], int n, int r)
{
    // A temporary array to store all combination one by one
    int data[r];
 
    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, data, 0, n-1, 0, r);
}
 
/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void First::combinationUtil(int arr[], int data[], int start, int end,
                     int index, int r)
{
    // Current combination is ready to be printed, print it
    if (index == r)
    {
        //for (int j=0; j<r; j++)
        //    printf("%d ", data[j]);
        //printf("\n");
	int saved = fillSums(data,r);
	if(saved)
	{
		printArrayComma(data,r);
		averageSums += saved;
		savedPerN += saved;
		perN ++;
		#ifdef printArrays
		printf(" :%d ", saved);
		#endif
		
		#ifdef printSavedSums
	
		if(averageSums >= (totalSums / 2) && !reachedAverage)
		{
			printf("   Average Reached *** Cycles:%d Sums:%d \n", cycle_iteration, cycle_sums); 
			reachedAverage = true;
		}
		#endif
	}
	else
	{
		#ifdef printRepeat
		printf("repeat: ");
		printArray(data,r);
		#endif
	}
        return;
    }
 
    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
 
// Driver program to test above functions

void First::init(int size)
{

        runningSums = 0;
        averageSums = 0;
        savedPerN = 0;
        perN = 0;

        reachedAverage = false;

        cycle = 0;
        cycle_iteration = 0;
        cycle_sums = 0;
        iteration;
	
	totalSums = 1 << size;
	sums = new int [1 << size];

}

void First::del()
{
	delete[] sums;
}

void First::printSumArray()
{
	printArray(sums, totalSums);	
}

void First::line(int * array, int length)
{
	N = length;
	
	iteration = N;

	int i=0;
	//for(i = 0; i < N ; i+=1)
	{	
		printCombination(array, N, N-i);
		#ifdef printArrays
		//printf("\n");
		#endif

		#ifdef printSavedSums
		
		printf("N:%d-%d Saved:%d Average:%f \n",N-i, perN, savedPerN, savedPerN*1.0 / (perN * 1.0) );
		savedPerN = 0;
		perN = 0;
		#endif
	}
	
	//printf("\n");
	#ifdef printSavedSums	
	printf("Cycles:%d Cycle Iteration:%d \n", cycle, cycle_iteration);
	#endif

	#ifdef printArrays
	printArray(sums, totalSums);	
	#endif

}
