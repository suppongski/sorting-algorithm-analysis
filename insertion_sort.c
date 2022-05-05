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
    int i, j, tmp;
    int n = ARR_SIZE;
    int arr[n];
    srand(time(NULL));
    for (int a=0; a<n; a++)
    {
        arr[a] = rand()%n;
    }

    for(i=1; i<n; i++)
    {    
        tmp = arr[i];
        for(j=i-1; j>=0 && arr[j]>tmp; j--)
        {
            arr[j+1] = arr[j];
        }

        arr[j+1] = tmp;
    }
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart)*1000);
}