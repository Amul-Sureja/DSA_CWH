#include <stdio.h>
 
void display(int arr[], int n)
{
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
 
void indDeletion(int arr[], int size, int index, int capacity)
{
    // code for Deletion
    if (index >= capacity-1)
    {
        printf("Sorry not deletion");
    }
    
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i + 1];
    }  
}
 
int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 3, capacity = 100;
    display(arr, size);
    indDeletion(arr, size, index, capacity);
    size -= 1;
    display(arr, size);
    return 0;
}
