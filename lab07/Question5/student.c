/*
Question 5: Selection Sort

Description:
Implement selection sort for an integer array.

Selection sort repeatedly finds the smallest element from the unsorted
portion of the array and swaps it with the first element of the unsorted
portion.

The function should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- You may write a helper function such as swap(...) if you want.
- Do not use any built-in sorting function.
*/
// Helper swap function (optional if already defined elsewhere)
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size) {
    if (size <= 1) return;

    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        // find the smallest element in the unsorted portion
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // swap it into the correct position
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}