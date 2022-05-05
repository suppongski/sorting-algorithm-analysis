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

    int gap, key, j;
    for (gap = n/2; gap > 0; gap = gap/2)
    {
        if ((gap%2) == 0)
        {
            gap++;
        }
        for (int a = 0; a < gap; a++)
        {
            for (int i = a+gap; i <= n-1; i=i+gap)
            {
                key = arr[i];
                for (j = i-gap; j>=a && arr[j]>key; j = j-gap)
                {
                    arr[j+gap] = arr[j];
                }
                arr[j+gap] = key;
            }
        }
    }
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart)*1000);
}