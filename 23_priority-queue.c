// Representation of priority queue
// Now, we will see how to represent the priority queue through a one-way list.

// We will create the priority queue by using the list given below in which INFO list contains the data elements, PRN list contains the priority numbers of each data element available in the INFO list, and LINK basically contains the address of the next node.

// functions:

// int parent(int i): This function returns the index of the parent node of a child node, i.e., i.
// int left_child(int i): This function returns the index of the left child of a given index, i.e., i.
// int right_child(int i): This function returns the index of the right child of a given index, i.e., i.
// void moveUp(int i): This function will keep moving the node up the tree until the heap property is restored.
// void moveDown(int i): This function will keep moving the node down the tree until the heap property is restored.
// void removeMax(): This function removes the element which is having the highest priority.
// void insert(int p): It inserts the element in a priority queue which is passed as an argument in a function.
// void delete(int i): It deletes the element from a priority queue at a given index.
// int get_Max(): It returns the element which is having the highest priority, and we know that in max heap, the root node contains the element which has the largest value, and highest priority.
// int get_Min(): It returns the element which is having the minimum priority, and we know that in max heap, the last node contains the element which has the smallest value, and lowest priority.
