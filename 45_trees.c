// iomplemantation of trees
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

//=> Terminologies used in trees:
// Root: The topmost node of a tree is called the root. There is no edge pointing to it, but one or more than one edge originating from it. Here, A is the root node.
// Parent: Any node which connects to the child. Node which has an edge pointing to some other node. Here, C is the parent of H.
// Child: Any node which is connected to a parent node. Node which has an edge pointing to it from some other node. Here, H is the child of C.
// Siblings: Nodes belonging to the same parent are called siblings of each other. Nodes B, C and D are siblings of each other, since they have the same parent node A.
// Ancestors: Nodes accessible by following up the edges from a child node upwards are called the ancestors of that node. Ancestors are also the parents of the parents of …… that node. Here, nodes A, C and H are the ancestors of node I.
// Descendants: Nodes accessible by following up the edges from a parent node downwards are called the descendants of that node. Descendants are also the child of the child of …… that node. Here, nodes H and I are the descendants of node C.
// Leaf/ External Node: Nodes which have no edge originating from it, and have no child attached to it. These nodes cannot be a parent. Here, nodes E, F, G and I are leaf nodes.
// Internal node: Nodes with at least one child. Here, nodes B, D and C are internal nodes.
// Depth: Depth of a node is the number of edges from root to that node. Here, the depth of nodes A, C, H and I are 0, 1, 2 and 3 respectively.
// Height: Height of a node is the number of edges from that node to the deepest leaf. Here, the height of node A is 3, since the deepest leaf from this node is node I. And similarly, height of node C is 2.

//=> types of tree
// 1. Binary Tree
/*
Types of Binary Tree:
=> Binary Tree consists of following types based on the  number of children:
            1] Full or Strict Binary Tree
            2] Degenerate Binary Tree
            3] Skewed trees
=> On the basis of completion of levels, the binary tree can be divided into following types:
            1] Complete Binary Tree
            2] Perfect Binary Tree
            3] Balanced Binary Tree
*/
// 2. Ternary Tree
// 3. N-ary Tree (Generic Tree)

// Special Types of Trees in Data Structure based on the nodes’ values:
// 1. Binary Search Tree
// 2. AVL Tree
// 3. Red-Black Tree
// 4. B-Tree
// 5. B+ Tree
// 6. Segment Tree

// 7. Interval Tree
// 8. 2-3-4 Tree

//=> representation of trees:
// 1] array representation
// 2] linked represaentation
// Node-based Representation: This is the most common representation used in programming. Each node in the tree is represented as an object or struct, containing a value and references/pointers to its child nodes (e.g., left and right pointers in a binary tree).
// Array-based Representation: Trees can also be represented using arrays or lists. In this representation, the tree is stored in a contiguous block of memory, with each index corresponding to a node in the tree. The parent-child relationships are determined by the indices.
// Adjacency List Representation: This representation is commonly used in graph theory and can be applied to trees as well. Each node in the tree has a list of its adjacent nodes (i.e., children).
// Parenthesis or Bracket Notation: This is a concise and often human-readable way of representing trees. Each node is enclosed within parentheses, with its children listed inside.
// Level-order Traversal: In this representation, the nodes of the tree are listed in level-order traversal (i.e., from left to right, level by level). This representation is often used for serialization and deserialization of trees.
// Graphical or Visual Representation: This type of representation is used for conceptual understanding or visualization purposes. Trees can be represented graphically using various diagrams, such as hierarchical diagrams, tree plots, or tree structures in software tools like Visio or draw.io.
