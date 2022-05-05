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

    srand(time(NULL));
    int n = ARR_SIZE;
    int arr[n];
    for (int a=0; a<n; a++)
    {
      arr[a] = rand()%33;
    }

    int tmp;
    for(int i=n-1; i>0; i--)
    {
      for(int j=0; j<i; j++)
      {
        if(arr[j]>arr[j+1])
        {
          tmp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = tmp;
        }
      }
    }

    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart)*1000);
}