// // 1] Insertion operation: It is used to add a new node to a particular location in a specific situation.

// Insertion (L, Key)  
// local update [0...Max_Level + 1]  
// a = L → header  
// for i = L → level down to 0 do.  
//        while a → forward[i] → key  forward[i]  
// update[i] = a  
  
// a = a → forward[0]  
// lvl = random_Level()  
// if lvl > L → level then  
// for i = L → level + 1 to lvl do  
//       update[i] = L → header  
//       L → level = lvl  
  
// a = makeNode(lvl, Key, value)  
// for i = 0 to level do  
//       a → forward[i] = update[i] → forward[i]  
// update[i] → forward[i] = a  






// // 2] Deletion operation: It is used to delete a node in a specific situation.

// Deletion (L, Key)
// local update [0... Max_Level + 1]  
// a = L → header  
// for i = L → level down to 0 do.  
//    while a → forward[i] → key forward[i]  
//       update[i] = a  
// a = a → forward[0]  
// if a → key = Key then  
//    for i = 0 to L → level do  
//         if update[i] → forward[i] ? a then break  
//         update[i] → forward[i] = a → forward[i]  
//    free(a)  
//    while L → level > 0 and L → header → forward[L → level] = NIL do  
//         L → level = L → level - 1  





// //  3] Search Operation: The search operation is used to search a particular node in a skip list.

// Searching (L, SKey)  
//         a = L → header  
//         loop invariant: a → key level down to 0 do.  
//              while a → forward[i] → key forward[i]  
//         a = a → forward[0]  
//        if a → key = SKey then return a → value  
//        else return failure