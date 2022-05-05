#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#define ARR_SIZE pow(2, 5)
int main(void)
{
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
    int n = ARR_SIZE;
    int arr[n];
    srand(time(NULL));
    for (int a=0; a<n; a++)
    {
        arr[a] = rand()%n;
    }

	for (int i = 1; i < n; i++)
    {
		int child = i;
		do
        {
		    int root = (child - 1) / 2;
		    if (arr[root] < arr[child])
            {
			    int tmp = arr[root];
			    arr[root] = arr[child];
			    arr[child] = tmp;
		    }
			child = root;
		} while (child != 0);
	}

	for (int i = n - 1; i >= 0; i--)
    {
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		int root = 0;
		int child = 1;
		do
        {
			child = 2 * root + 1;
			if (arr[child] < arr[child + 1] && child < i - 1)
            {
				child++;
			}
			if (arr[root] < arr[child] && child < i)
            {
				int tmp = arr[root];
				arr[root] = arr[child];
				arr[child] = tmp;
			}
			root = child;
		} while (child < i);
	}
QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart)*1000);
}