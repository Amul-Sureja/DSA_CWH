//************************************************using main function
#include <stdio.h>
#include <stdlib.h>

int main() {
    int initialCapacity = 5;
    int *array = (int *)malloc(initialCapacity * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int size = 0; // Current size of the array
    int i;

    // Add some elements to the array
    for (i = 0; i < initialCapacity; i++) {
        array[size++] = i;
    }

    // Print the original array
    printf("Original array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Increase the size of the array
    int newSize = initialCapacity * 2; // New size of the array
    array = (int *)realloc(array, newSize * sizeof(int));
    if (array == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    // Add more elements to the resized array
    for (i = initialCapacity; i < newSize; i++) {
        array[size++] = i;
    }

    // Print the resized array
    printf("Resized array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(array);

    return 0;
}


// //*************************************************using function
// #include <stdio.h>
// #include <stdlib.h>

// // Function to increase the size of the array
// int* increaseArraySize(int* arr, int currentSize, int newSize) {
//     // Allocate memory for the new array
//     int* newArr = (int*)malloc(newSize * sizeof(int));
    
//     // Check if memory allocation was successful
//     if (newArr == NULL) {
//         printf("Memory allocation failed.\n");
//         exit(1);
//     }
    
//     // Copy elements from the old array to the new array
//     for (int i = 0; i < currentSize; i++) {
//         newArr[i] = arr[i];
//     }
    
//     // Free memory occupied by the old array
//     free(arr);
    
//     // Return the new array
//     return newArr;
// }

// int main() {
//     int size = 5;  // Initial size of the array
//     int* array = (int*)malloc(size * sizeof(int));
    
//     // Populate the initial array
//     for (int i = 0; i < size; i++) {
//         array[i] = i;
//     }
    
//     // Increase the size of the array
//     int newSize = 10;  // New size of the array
//     array = increaseArraySize(array, size, newSize);
    
//     // Print the elements of the new array
//     for (int i = 0; i < newSize; i++) {
//         printf("%d ", array[i]);
//     }
//     printf("\n");
    
//     // Free memory occupied by the new array
//     free(array);
    
//     return 0;
// }
