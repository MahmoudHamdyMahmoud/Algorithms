#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	clock_t t;
	t = clock();
	double time_insert = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("The array is sorted using insertion sort in %f seconds.\n", time_insert);	
}
/* Function to sort an array using quick sort*/

void quicksort(int arr[],int first,int last){
	int i, j, pivot, temp;
		if(first<last){
			pivot=first;
			i=first;
			j=last;
			while(i<j){
				while(arr[i]<=arr[pivot]&&i<last)
					i++;
				while(arr[j]>arr[pivot])
					j--;
				if(i<j){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				}
			}
			temp=arr[pivot];
			arr[pivot]=arr[j];
			arr[j]=temp;
			quicksort(arr,first,j-1);
			quicksort(arr,j+1,last);
		}

	}
void quickandtime(int arr[], int first, int last){
	quicksort(arr, first, last);
	clock_t t;
	t = clock();
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("The array is sorted using quick sort in %f seconds\n", time_taken);
}

/* The main programm */
int main()
{
	int i, m;
	m = 100000;
	int arr[m];
	time_t t;
	/* Intializes random number generator */
	srand((unsigned) time(&t));
	/* Putting 100000 random numbers from 0 to 100000 in arr*/
	for( i = 0 ; i < m ; i++) {
	  arr[i] = rand()%100000;
	}
	/*Initialized Array*/
	printf("\nArray of %d random numbers is initialized.\n", m);
	insertionSort(arr, m);
	for( i = 0 ; i < m ; i++) {
	  arr[i] = rand()%100000;
	}
	quickandtime(arr, 0, m - 1);	
    
	return 0;
}

