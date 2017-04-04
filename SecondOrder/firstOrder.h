#ifndef FIRST_H_
#define FIRST_H_

void printArray(int * array, int length);
//void line(int * array, int length);

class First
{
     private :
/*	int * sums;
	int totalSums;
	int runningSums = 0;
	int averageSums = 0;
	int savedPerN = 0;
	int perN = 0;

	bool reachedAverage = false;

	int cycle = 0;
	int cycle_iteration = 0;
	int cycle_sums = 0;
	int iteration;


*/

     public :
        
	First(int * array, int length);

	int getLength();
	void init();
	

	void printArrayComma(int * array, int length);
	int inSums(int t);
	int fillSums(int * a, int length);
	void printCombination(int arr[], int n, int r);
	void combinationUtil(int arr[], int data[], int start, int end, int index, int r);
	void line(int * array, int length);

	int test;


	int N;
	int * sums;
        int totalSums;

        int runningSums;
        int averageSums;
        int savedPerN;
        int perN;

        bool reachedAverage;

        int cycle;
        int cycle_iteration;
        int cycle_sums;
        int iteration;

};

#endif

