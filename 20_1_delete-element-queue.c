// Algorithm
// Step 1: IF FRONT = -1 or FRONT > REAR
// Write UNDERFLOW
// ELSE
// SET VAL = QUEUE[FRONT]
// SET FRONT = FRONT + 1
// [END OF IF]
// Step 2: EXIT



int delete (int queue[], int max, int front, int rear)  
{  
    int y;   
    if (front == -1 || front > rear)   
   
    {  
        printf("underflow");  
    }  
    else   
    {  
        y = queue[front];  
        if(front == rear)  
        {  
            front = rear = -1;  
            else   
            front = front + 1;   
          
        }  
        return y;  
    }  
}   