// Algorithm
// Step 1: Allocate the space for the new node PTR
// Step 2: SET PTR -> DATA = VAL
// Step 3: IF FRONT = NULL
// SET FRONT = REAR = PTR
// SET FRONT -> NEXT = REAR -> NEXT = NULL
// ELSE
// SET REAR -> NEXT = PTR
// SET REAR = PTR
// SET REAR -> NEXT = NULL
// [END OF IF]
// Step 4: END


// code
// void insert(struct node *ptr, int item)
// {

//     ptr = (struct node *)malloc(sizeof(struct node));
//     if (ptr == NULL)
//     {
//         printf("\nOVERFLOW\n");
//         return;
//     }
//     else
//     {
//         ptr->data = item;
//         if (front == NULL)
//         {
//             front = ptr;
//             rear = ptr;
//             front->next = NULL;
//             rear->next = NULL;
//         }
//         else
//         {
//             rear->next = ptr;
//             rear = ptr;
//             rear->next = NULL;
//         }
//     }
// }