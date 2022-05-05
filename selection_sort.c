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

    int min, tmp;
    for(int i=0; i<n-1; i++)
    {
        min = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min])
            min = j;
        }

        if(i != min)
        {
            tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart)*1000);
}