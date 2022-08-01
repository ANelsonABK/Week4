# Week4
## Sorting Algorithm
The sorting algorithm implemented is the Merge Sort Algorithm.

### Merge Sort
It incorporates the Divide and Conquer technique:
- Divide the problem (array) into two equal sub-problems (two subarrays).
  - Divide the subarray into two parts by finding the middle index.
- Conquer by solving both of the sub-problems recursively.
  - Recursively sort the left subarray
  - Recursively sort the right subarray
- Combine the sorted subarrays into a final sorted array.
  - Merge the two sorted subarrays into a larger sorted array
- The base case for the recursion is when the size of the subarray is one (which is already sorted).

### Merge
Using the two pointers approach, each subarray is looped through and one element from each subarray is compared to. The smaller of the two elements is inserted into a larger subarray. When either pointer reaches the end of their respective array, if the other has any elements left, those elements are inserted into the larger array (those are already sorted).

### Big O
