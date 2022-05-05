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

    quickSort(arr, 0, n-1);
    
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart)*1000);
}

void quickSort(int arr[], int L, int R) {
      int left = L, right = R;
      int pivot = arr[(L + R) / 2];
      int tmp;
      do
      {
        while (arr[left] < pivot)
            left++;
        while (arr[right] > pivot)
            right--;
        if (left<= right)
        {
            tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
      } while (left<= right);
 
    if (L < right)
        quickSort(arr, L, right);
 
    if (left < R)
        quickSort(arr, left, R);
}