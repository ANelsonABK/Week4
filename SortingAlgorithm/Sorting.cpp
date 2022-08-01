#include <chrono>
#include <iostream>
#include <algorithm>

void FillArray(int* array, size_t arraySize);
void MergeSort(int* array, int left, int right);
void Merge(int* arr, int left, int mid, int right);
void PrintArray(int* arr, size_t arraySize);
uint32_t GetNanos();

int main()
{
	// Seed the random generator
	srand(time(nullptr));

	// Generate a random size in the range 1 to 100
	const int arraySize = (rand() % 1000) + 1;
	int* array = new int[arraySize];

	// Fill array with random numbers
	FillArray(array, arraySize);

	std::cout << "Unsorted Array: " << std::endl;
	PrintArray(array, arraySize);

	// Sort the array using merge sort
	uint32_t startNanos = GetNanos();
	MergeSort(array, 0, arraySize - 1);
	uint32_t endNanos = GetNanos();

	std::cout << "Sorted Array: " << std::endl;
	PrintArray(array, arraySize);

	std::cout << "Time to sort array: " << (endNanos - startNanos) << "ns." << std::endl;

	// Release the memory
	delete[] array;
}

void FillArray(int* array, size_t arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % arraySize + 1;
	}
}

void MergeSort(int* array, int left, int right)
{
	// Base case: subarray has one element
	if (left >= right)
	{
		// Array is sorted so return
		return;
	}

	// Calculate the middle index
	int mid = left + (right - left) / 2;

	// Recursively sort left subarray
	MergeSort(array, left, mid);

	// Recursively sort right subarray
	MergeSort(array, mid + 1, right);

	// Merge the sorted halves
	Merge(array, left, mid, right);
}

void Merge(int* arr, int left, int mid, int right)
{

	const int size1 = mid - left + 1;
	const int size2 = right - mid;

	// Copy the two subarrays
	int* arr1 = new int[size1];
	int* arr2 = new int[size2];

	for (int i = 0; i < size1; i++)
	{
		arr1[i] = arr[left + i];
	}

	//std::cout << "Subarray 1: ";
	//PrintArray(arr1, size1);

	for (int j = 0; j < size2; j++)
	{
		arr2[j] = arr[mid + 1 + j];
	}

	//std::cout << "Subarray 2: ";
	//PrintArray(arr2, size2);
	
	// Pointers for each array
	int ptr1 = 0;
	int ptr2 = 0;
	int ptrA = left;

	// Loop while both arrays have elements
	while (ptr1 < size1 && ptr2 < size2)
	{
		// Compare the two numbers
		if (arr1[ptr1] <= arr2[ptr2])
		{
			arr[ptrA] = arr1[ptr1];
			ptr1++;
		}
		else
		{
			arr[ptrA] = arr2[ptr2];
			ptr2++;
		}

		// Move original array's pointer
		ptrA++;
	}

	// Copy any remaining values from arr1 to original array
	while (ptr1 < size1)
	{
		arr[ptrA] = arr1[ptr1];
		ptr1++;
		ptrA++;
	}

	// Copy any remaining values from arr2 to original array
	while (ptr2 < size2)
	{
		arr[ptrA] = arr2[ptr2];
		ptr2++;
		ptrA++;
	}

	//std::cout << "Merged Array: ";
	//PrintArray(arr, sizeof(arr));

	// Release the memory
	delete[] arr1;
	arr1 = nullptr;

	delete[] arr2;
	arr2 = nullptr;
}

void PrintArray(int* arr, size_t arraySize)
{
	for (size_t i = 0; i < arraySize; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

uint32_t GetNanos()
{
	using namespace std::chrono;
	return static_cast<uint32_t>(duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count());
	//return static_cast<uint32_t>(duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}