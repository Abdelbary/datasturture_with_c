
//version 1.0

/**
 * @brief tree structure to be used as the main
 * component to build the binary search tree
 * 
 */
typedef struct btree{
    int data;
    struct btree* left;
    struct btree* right;
    struct btree* parent;
}btree;
/**
 * @brief insert new node into the tree
 * 
 * @param tree      [input] pointer to node pointer passed from outside for the local change to be captured from callee side.
 * @param v         [input] value to be inserted in the created node.
 * @param parent    [input] pointer to the inserted node pointer to be saved as local data in the current node.
 */
void insert(btree** tree, int v, btree* parent);

/**
 * @brief delete a node from the tree
 * 
 * @param tree      [input] pointer to node pointer passed from outside for the local change to be captured from callee side.
 * @param v         [input] value to get and delete the carrieer node.
 */
btree* deleteNode(btree *tree, int v);

/**
 * @brief find the maxumim element in the tree
 * 
 * @param tree      [input] pointer to tree to search
 * @return btree*   pointer to the max element 
 */
btree * findMax(btree* tree);


/**
 * @brief find the maxumim element in the tree
 * 
 * @param tree      [input] pointer to tree to search
 * @return btree*   pointer to the max element 
 */
btree * findMin(btree* tree);



/**
 * @brief traverse tree in order
 * 
 * @param t     [input] tree to traverse
 */
void  traverse_tree(btree *t);

/**
 * @brief search the bst for a specific node with givien value
 * 
 * @param t     [input] btree to search in
 * @param v     [input] value of the node to search for
 * @return btree* return a pointer to the specified node null if none.
 */
btree * searchTree(btree *t , int v);

/**
 * @brief return the successor of the current node smallest element in the right tree 
 * null if none.
 * 
 * @param t        [input] pointer to the node that a we need to find the successor of
 * @return btree*  pointer to the successor
 */
btree* Successor(btree * t);


/**
 * @brief return the Predecessor of the current node smallest element in the right tree 
 * null if none.
 * 
 * @param t         [input] pointer to the node that a we need to find the Predecessor of
 * @return btree*   pointer to the Predecessor
 */
btree* Predecessor(btree *t);