#include <iostream>
#include <list>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

struct node {
	int data;
	node* next;
};

void bubbleSort() {
	int number;
	bool flag;

	node* head;
	node* n;
	node* curr;

	//Gather User Input
	cout << "Enter value 1: ";
	cin >> number;

	n = new node;
	n->data = number;
	head = n;
	curr = n;

	for (int i = 2; i <= 10; i++) {
		cout << "Enter value " << i << ": ";
		cin >> number;

		n = new node;
		n->data = number;
		curr->next = n;
		curr = n;
	}

	curr->next = NULL;

	//Sort List
	n = head;
	curr = n;

	for (int i = 0; i < 9; i++) {
		flag = true;
		for (int j = 0; j < 9 - i; j++) {
			if (curr->data > curr->next->data) {
				int temp = curr->data;
				curr->data = curr->next->data;
				curr->next->data = temp;
				flag = false;
			}
			curr = n->next;
			n = curr;
		}
		curr = head;
		n = curr;
		if (flag) {
			break;
		}
	}

	//Output List
	cout << endl << endl << head->data << endl;
	n = head->next;
	curr = n;

	for (int i = 0; i < 9; i++) {
		cout << curr->data << endl;
		n = curr->next;
		curr = n;
	}
}

int RNG() {
	int arr1[1000], counter1 = 0;
	bool flag;

	srand(time(NULL));

	for (int i = 0; i < 1000; i++) {
		arr1[i] = rand();
	}

	for (int i = 0; i < 999; i++) {
		flag = true;
		for (int j = 0; j < 999 - i; j++) {
			if (arr1[j] > arr1[j + 1]) {
				int temp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;
				counter1 += 1;
			}
		}
		if (flag) {
			break;
		}
	}
	return counter1;
}

int shellSort(int arr[], int n)
{
	int counter = 0;
	// Start with a big gap, then reduce the gap 
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int gap = 8; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size. 
		// The first gap elements a[0..gap-1] are already in gapped order 
		// keep adding one more element until the entire array is 
		// gap sorted  
		for (int i = gap; i < n; i += 1)
		{
			// add a[i] to the elements that have been gap sorted 
			// save a[i] in temp and make a hole at position i 
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct  
			// location for a[i] is found 
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				cout << "Swapping " << arr[j - gap] << " for " << arr[j] << endl;
				arr[j] = arr[j - gap];
				counter += 1;
			}

			//  put temp (the original a[i]) in its correct location 
			arr[j] = temp;
			counter += 1;
		}
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return counter;
}

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element
	int counter = 0;

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(&arr[i], &arr[j]);
			counter++;
		}
	}
	swap(&arr[i + 1], &arr[high]);
	counter++;
	//cout << counter << endl;
	return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main() {
	int arr[18] = { 30, 5, 40, 11, 20, 9, 15, 2, 60, 25, 80, 3, 73, 35, 4, 75, 20, 6 };
	shellSort(arr, 18);
}