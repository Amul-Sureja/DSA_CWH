// Algorithm
// Step 1: IF REAR = MAX - 1
// Write OVERFLOW
// Go to step
// [END OF IF]
// Step 2: IF FRONT = -1 and REAR = -1
// SET FRONT = REAR = 0
// ELSE
// SET REAR = REAR + 1
// [END OF IF]
// Step 3: Set QUEUE[REAR] = NUM
// Step 4: EXIT


void insert (int queue[], int max, int front, int rear, int item)   
{  
    if (rear + 1 == max)  
    {  
        printf("overflow");  
    }  
    else  
    {  
        if(front == -1 && rear == -1)  
        {  
            front = 0;  
            rear = 0;  
        }  
        else  
        {  
            rear = rear + 1;   
        }  
        queue[rear]=item;  
    }  
}  