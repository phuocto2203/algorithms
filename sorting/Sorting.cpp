#include "Sorting.h"

Sorting::Sorting() {
	srand(time(NULL));
}

Sorting::~Sorting() {
	
}

///
// Quick Sort

int Sorting::qpartition(int* arr, int start, int end, int pivotIndex) {
	int pivot = arr[pivotIndex], storeIndex = start;
	
	// Swap pivot to the end of the array
	swap(arr, pivotIndex, end);
	
	// Loop through all elements in the array until the pivot (which is now at the end)
	// pushing any element less than the pivot below the storeIndex (which will be the new pivot we are returning)
	for(int i = start; i < end; i++) {
		if(arr[i] < pivot) {
			swap(arr, i, storeIndex);
			storeIndex++;
		}
	}

	// Move the pivot to it's final position (the right most side of this sublist)
	swap(arr, storeIndex, end);

	return storeIndex; // Return the index of the new pivot
}

void Sorting::quickSort(int* arr, int start, int end) {
	if(start < end) {
		int pivotIndex = (end+start)/2; // Choosing midpoint as pivot
	
		// Get new index of pivot (all elements below this pivotIndex will be less than the pivot value)
		pivotIndex = qpartition(arr, start, end, pivotIndex);

		// Sort all elements less than the pivot (left side)
		quickSort(arr, start, pivotIndex - 1);
	
		// Sort all elements greater than the pivot (right side)
		quickSort(arr, pivotIndex + 1, end);
	}
}

///
// Merge Sort
void Sorting::mergeSort(int* arr, int low, int high) {
	if(low < high) {
		int mid = floor((low+high) / 2);
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		merge(arr, low, high);
	}
}

void Sorting::merge(int* arr, int low, int high) {
	int mid = floor((low+high)/2);
	int a = 0;
	int b = low;
	int c = mid+1;

	int *temp = new int[high-low+1];

	// Merge both
	while(b <= mid && c <= high) {
		if(arr[b] < arr[c]) {
			temp[a] = arr[b];
			a++;
			b++;
		} else {
			temp[a] = arr[c];
			a++;
			c++;
		}
	}

	// Merge left leftovers
	while(b <= mid) {
		temp[a] = arr[b];
		a++;
		b++;
	}

	// Merge right leftovers
	while(c <= high) {
		temp[a] = arr[c];
		a++;
		c++;
	}

	// Copy sorted elements in temp back into the original array
	for(int i = low; i <= high; i++) {
		arr[i] = temp[i-low];
	}

	delete temp;
}

/**
 * Insertion Sort
 * Idea: Left side of the array is considered 'sorted' whereas the rightside is 'unsorted'.
 * Starting at the 2nd element in the array (the key), look at all elements to the left. Any elements greater than the key
 * are shifted one position to the right of the key. The leftover space becomes the correct position for the key at that time
 * The next element in the array becomes the new key and the process is repeated
 */
void Sorting::insertionSort(int* arr, int len) {
	if(len < 2)
		return;

	// Loop through the array starting at the 2nd element (left side of the array will be considered 'sorted')
	for(int i = 1; i < len; i++) {
		int key = arr[i], j = i-1;

		// Check all elements below the key's current position. Move elements greater than the key to the right
		while(j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}

		// Insert the key at j+1 (the correct space, after shifting all greater elements to the right)
		arr[j+1] = key;
	}
}

void Sorting::recursiveInsertionSort(int* arr, int len) {
	if(len > 1) {
		recursiveInsertionSort(arr, len-1); // Start at the base case of 1 element
		recursiveInsert(arr, len-1); // Work way up the array finding correct position for element at i+1
	}
}

void Sorting::recursiveInsert(int* arr, int k) {
	int key = arr[k]; // Choose the right most element in the array
	int i = k - 1;

	// Keep decrementing through the array and pushing all larger elements than the key to the end
	while(i >= 0 && arr[i] > key) {
		arr[i+1] = arr[i]; // Push each element that is greater one space to the right
		i--; // Decrement index
	}
	arr[i+1] = key; // Found the correct position for the key
}

/**
 * Selection Sort
 * Idea: Array is divided into sorted (on left) and unsorted (right). For every iteration, the smallest element in the unsorted portion of the
 * array is found and added to the sorted portion of the array
 */
void Sorting::selectionSort(int* arr, int len) {
	int minIdx = 0;
	for(int i = 0; i < len-1; i++) {
		// Find the smallest element in the unsorted portion of the array
		for(int j = i+1; j < len; j++) {
			if(arr[j] < arr[minIdx])
				minIdx = j;
		}
		
		// Now swap the smallest element to the end of the sorted portion (i represents the end of the sorted portion)
		swap(arr, minIdx, i);
	}
}

// Exchange the values at indexes a and b
void Sorting::swap(int* arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void Sorting::initRandArray(int* arr, int len, int low, int high) {
    for(int i = 0; i < len; i++)
        arr[i] = low + rand() % high;
}

void Sorting::printArray(int* arr, int len) {
	for(int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}