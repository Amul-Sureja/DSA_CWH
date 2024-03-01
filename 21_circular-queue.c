// Operations on Circular Queue
// Front: It is used to get the front element from the Queue.
// Rear: It is used to get the rear element from the Queue.
// enQueue(value): This function is used to insert the new value in the Queue. The new element is always inserted from the rear end.
// deQueue(): This function deletes an element from the Queue. The deletion in a Queue always takes place from the front end.


// Algorithm to insert an element in a circular queue
// Step 1: IF (REAR+1)%MAX = FRONT
// Write " OVERFLOW "
// Goto step 4
// [End OF IF]

// Step 2: IF FRONT = -1 and REAR = -1
// SET FRONT = REAR = 0
// ELSE IF REAR = MAX - 1 and FRONT ! = 0
// SET REAR = 0
// ELSE
// SET REAR = (REAR + 1) % MAX
// [END OF IF]

// Step 3: SET QUEUE[REAR] = VAL

// Step 4: EXIT




// Algorithm to delete an element from the circular queue
// Step 1: IF FRONT = -1
// Write " UNDERFLOW "
// Goto Step 4
// [END of IF]

// Step 2: SET VAL = QUEUE[FRONT]

// Step 3: IF FRONT = REAR
// SET FRONT = REAR = -1
// ELSE
// IF FRONT = MAX -1
// SET FRONT = 0
// ELSE
// SET FRONT = FRONT + 1
// [END of IF]
// [END OF IF]

// Step 4: EXIT