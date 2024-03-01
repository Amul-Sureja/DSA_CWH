// Algorithm
// Step 1: IF FRONT = NULL
// Write " Underflow "
// Go to Step 5
// [END OF IF]
// Step 2: SET PTR = FRONT
// Step 3: SET FRONT = FRONT -> NEXT
// Step 4: FREE PTR
// Step 5: END


// code 
// void delete (struct node *ptr)  
// {  
//     if(front == NULL)  
//     {  
//         printf("\nUNDERFLOW\n");  
//         return;  
//     }  
//     else   
//     {  
//         ptr = front;  
//         front = front -> next;  
//         free(ptr);  
//     }  
// }   