#include <iostream>
#include <cmath>


//#####################################Insertionsort Begin############################################
/*
 * Insertion Sort
 */
void InsertionSort(int *a, int arraySize) {

    for (int i = 1; i < arraySize; i++) {

        // Assume first element is the smallest value
        int smallestValue = a[i];

        // Declare counter to control while loop
        int counter = i;

        /*
         * While counter is greater than zero and the element to
         * the left of the next value is greater swap positions
         */
        while (counter > 0 && a[counter - 1] > smallestValue) {
            a[counter] = a[counter - 1];
            counter = counter - 1;
        } // End while loop

        a[counter] = smallestValue;  // Assign smallest value to index 0

    } // End for loop

} // End insertion sort function
//#####################################Insertionsort End##############################################


//#####################################Partition Begin################################################
/*
 * Partition
 */
int Partition(int *array, int start, int end) {

    // Set pivot to last element in array
    int pivot = array[end];

    // Start partition index at index 0
    int partitionIndex = start;

    // Declare temporary variables for swapping values
    int swapArray_i, swapPartitionIndex;

    /*
     * Start at index array[i] and compare each element to pivot.
     * If element at index "i" is less than or equal to pivot,
     * swap the partition index and array[i] index values.
     */
    for (int i = start; i < end; i++) {
        if (array[i] <= pivot) {
            swapArray_i = array[i];
            swapPartitionIndex = array[partitionIndex];
            array[i] = swapPartitionIndex;
            array[partitionIndex] = swapArray_i;
            partitionIndex++;
        }
    }

    // After array is sorted swap end of array "pivot" with partition index
    swapArray_i = array[partitionIndex];
    swapPartitionIndex = array[end];
    array[end] = swapArray_i;
    array[partitionIndex] = swapPartitionIndex;

    return partitionIndex;
} // End Partition function
//#####################################Partition End#################################################


//#####################################QuickSort Begin###############################################
/*
 * QuickSort
 */
void QuickSort(int *array, int start, int end) {

    // Store array size
    int arraySize = (end + 1) - start;

    // If there exists more than one element in the array divide and conquer
    if (start < end) {
        // If array size is less than or equal to 16 call InsertionSort
        if (arraySize <= 16) {
            InsertionSort(array, arraySize);
        }
        // Else array size is greater then 16, call partition function
        else {
            int partitionIndex = Partition(array, start, end);
            QuickSort(array, start, partitionIndex - 1);
            QuickSort(array, partitionIndex + 1, end);
        }
    }

} // End QuickSort function
//#####################################QuickSort End#################################################


//#####################################Begin Main Method#############################################
int main() {

    clock_t tStart = clock();

    int start, end;

    start = 0;
    end = pow(2,16);

    int array[end];

   /* for (int i = start; i < end; i++) {
        array[i] = start + rand() % (end - start + 1);
    }

    QuickSort(array, start, end - 1);

    for (int i : array) {
        std::cout << i << ' ';
    }*/


    for(int i = 0; i < end; i++) {
        array[i] = i;
    }

    QuickSort(array, start, end - 1);

    for (int i = 0; i < end; i++) {
        std::cout << array[i] << ' ';
    }

    printf("\nTime taken: %.9fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
//#####################################End Main Method###############################################