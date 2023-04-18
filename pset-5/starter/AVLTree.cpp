/*
 * Filename: AVLTree.cpp
 * Josh Bialkin
 * 4/15/23
 * Contains: Implementation of AVL Trees for CPSC 223
 * Part of: Homework assignment "AVL Trees" for CPSC 223
 */

#include <iostream>

#include "AVLTree.h"
#include "pretty_print.h"

#include <cassert>

using namespace std;

/*
 * Input: data (the value to store), multiplicity of the node, height of the
 *      node, left and right child pointers
 * Returns: avl tree node.
 * Does: creates a new node with values given as input parameter
 */
static Node *new_node(int data, int multiplicity, int height, Node *left, Node *right)
{
    Node *node = new Node();

    node->data = data;
    node->count = multiplicity;
    node->height = height;
    node->left = left;
    node->right = right;

    return node;
}

/*
 * Input: data (the value to store)
 * Returns: avl tree node.
 * Does: calls a helper function to create a new node with default
 *        values parameter
 */
static Node *new_node(int data)
{
    return new_node(data, 1, 0, NULL, NULL);
}

/********************************
 * BEGIN PUBLIC AVLTREE SECTION *
 ********************************/

AVLTree::AVLTree()
{
    root = nullptr;
}

AVLTree::AVLTree(const AVLTree &source)
{
    root = pre_order_copy(source.root);
}

AVLTree::~AVLTree()
{
    post_order_delete(root);
}

// assignment overload
AVLTree &AVLTree::operator=(const AVLTree &source)
{
    // check for self-assignment
    if (this == &source) {
        return *this;
    }
    // delete current tree if it exists
    post_order_delete(root);
    // use pre-order traversal to copy the tree
    root = pre_order_copy(source.root);
    
    return *this;
}

int AVLTree::find_min() const
{
    return find_min(root)->data;
}

int AVLTree::find_max() const
{
    return find_max(root)->data;
}

bool AVLTree::contains(int value) const
{
    return contains(root, value);
}

void AVLTree::insert(int value)
{
    root = insert(root, value);
}

void AVLTree::remove(int value)
{
    root = remove(root, value);
}

int AVLTree::tree_height() const
{
    return tree_height(root);
}

int AVLTree::node_count() const
{
    return node_count(root);
}

int AVLTree::count_total() const
{
    return count_total(root);
}

void AVLTree::print_tree() const
{
    print_pretty(root, 1, 0, std::cout);
}

/*************************
 * BEGIN PRIVATE SECTION *
 *************************/

/*
* Input: Node root - the root of the tree
* Returns: The leftmost node of the tree, containing the minimum value
* Does: Traverses the tree until it reaches the leftmost node
*/
Node *AVLTree::find_min(Node *node) const
{
    assert(node != nullptr);
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

/*
* Input: Node root - the root of the tree
* Returns: The rightmost node of the tree, containing the maximum value
* Does: Traverses the tree until it reaches the rightmost node
*/
Node *AVLTree::find_max(Node *node) const
{
    assert(node != nullptr);
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

/*
* Input: Node root - the root of the tree
* Returns: False if the tree does not contain the node, true if it does
* Does: Traverses the tree until the value is found or the end of the tree is 
        reached. The function is recursively called on each node, the node to 
        the left or the right of the current node depending on whether the 
        value it is searching for is less than or greater than the current 
        node.
*/
bool AVLTree::contains(Node *node, int value) const
{
    if (node == nullptr) {
        return false;
    }
    if (node->data > value) {
        return contains(node->left, value);
    } else if (node->data < value) {
        return contains(node->right, value);
    }
    return true;
}

Node *AVLTree::insert(Node *node, int value)
{
    /* BST insertion start */
    if (node == NULL)
    {
        return new_node(value);
    }
    else if (value < node->data)
    {
        node->left = insert(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = insert(node->right, value);
    }
    else if (value == node->data)
    {
        node->count++;
        return node;
    }
    /* BST insertion ends */

    /* AVL maintenance start */
    node->height = 1 + max(tree_height(node->left), tree_height(node->right));
    node = balance(node);
    /* AVL maintenace end */

    return node;
}

Node *AVLTree::remove(Node *node, int value)
{
    /* BST removal begins */
    if (node == NULL)
    {
        return NULL;
    }

    Node *root = node;
    if (value < node->data)
    {
        node->left = remove(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = remove(node->right, value);
    }
    else
    {
        // We found the value. Remove it.
        if (node->count > 1)
        {
            node->count--;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                root = NULL;
                delete node;
                return root;
            }
            else if (node->left != NULL && node->right == NULL)
            {
                root = node->left;
                node->left = NULL;
                delete node;
            }
            else if (node->left == NULL && node->right != NULL)
            {
                root = node->right;
                node->right = NULL;
                delete node;
            }
            else
            {
                Node *replacement = find_min(node->right);
                root->data = replacement->data;
                root->count = replacement->count;
                replacement->count = 1;
                root->right = remove(root->right, replacement->data);
            }
        }
    }
    /* BST removal ends */

    /* AVL maintenance begins */
    if (root != NULL)
    {
        root->height = 1 + max(tree_height(root->left), tree_height(root->right));
        root = balance(root);
    }
    /* AVL maintenance ends */

    return root;
}

/*
* Input: Node
* Returns: The height of the node called, or -1 if the node is null
* Does: Checks whether the node called is null, and returns -1 if so. If not,
        returns the height of the node.
*/
int AVLTree::tree_height(Node *node) const
{
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

/*
* Input: Node
* Returns: The number of nodes in the tree
* Does: Recursively calls the function using pre-order traversal to count
        the number of nodes in the tree.
*/
int AVLTree::node_count(Node *node) const
{
    if (node == nullptr) {
        return 0;
    }

    int left_nodes = node_count(node->left);
    int right_nodes = node_count(node->right);

    return 1 + left_nodes + right_nodes;
}

/*
* Input: Node
* Returns: The numbers of the tree added up including multiplicity of nodes
* Does: Recursively calls the function using pre-order traversal, adding the
        multiplicity of each node multipied by its value to get the total
        sum of every node in the tree.
*/
int AVLTree::count_total(Node *node) const
{
    if (node == NULL) {
        return 0;
    }
    return (node->count * node->data) + count_total(node->left) + 
        count_total(node->right);
}

/*
* Input: Node node - a pointer to the root of the tree to copy
* Returns: a deep copy of the tree rooted at node
* Does: Performs a pre-order traversal of the tree rooted at node to
*      create a deep copy of it
*/
Node *AVLTree::pre_order_copy(Node *node) const
{
    if (node == NULL)
    {
        return NULL;
    }
    Node *new_node = new Node();
    *new_node = *node;

    new_node->left = pre_order_copy(node->left);
    new_node->right = pre_order_copy(node->right);

    return new_node;
}

/*
* Input: Node node - a pointer to the root of the tree to delete
* Returns: N/A
* Does: Performs a post-order traversal of the tree rooted at node to
*      delete every node in that tree
*/
void AVLTree::post_order_delete(Node *node)
{
    if (node == NULL) {
        return;
    }
    post_order_delete(node->left);
    post_order_delete(node->right);
    delete node;
}

/*
* Input: Node root - a node of the avl tree.
* Returns: the balanced subtree.
* Does: If unbalanced, balances the tree rooted at node.
*/
Node *AVLTree::balance(Node *node)
{
    int diff_in_height = height_diff(node);

    if (diff_in_height > 1 && tree_height(node->left->left) > 
        tree_height(node->left->right)) {
            return right_rotate(node);
    } else if (diff_in_height < -1 && tree_height(node->right->right) > 
        tree_height(node->right->left)) {
            return left_rotate(node);
    } else if (diff_in_height > 1) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    } else if (diff_in_height < -1) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    
    return node;
}

/*
* Input: Node node - a node of the avl tree.
* Returns: pointer to the root of rotated tree.
* Does: right rotate tree rooted at node
*/
Node *AVLTree::right_rotate(Node *node)
{
    Node *new_root = node->left;
    Node *new_left = new_root->right;
    new_root->right = node;
    node->left = new_left;

    node->height = 1 + max(tree_height(node->left), tree_height(node->right));
    new_root->height = 1 + max(tree_height(new_root->left), tree_height(new_root->right));

    return new_root;
}

/*
* Input: Node node - a node of the avl tree.
* Returns: pointer to the root of rotated tree.
* Does: left rotate tree rooted at node
*/
Node *AVLTree::left_rotate(Node *node)
{
    Node *new_root = node->right;
    Node *new_right = new_root->left;
    new_root->left = node;
    node->right = new_right;

    node->height = 1 + max(tree_height(node->left), tree_height(node->right));
    new_root->height = 1 + max(tree_height(new_root->left), 
        tree_height(new_root->right));
    
    return new_root;
}

/*
* Input: Node node - a node of the avl tree.
* Returns: integer value signifying the height difference.
* Does: calculates the difference in the height of the left and child
*       subtree of node
*/
int AVLTree::height_diff(Node *node) const
{    
    if (node == NULL) {
        return 0;
    }

    int left_node_height = tree_height(node->left);
    int right_node_height = tree_height(node->right);

    return left_node_height - right_node_height;
}

Node *AVLTree::find_parent(Node *node, Node *child) const
{
    if (node == NULL)
        return NULL;

    // if either the left or right is equal to the child,
    // we have found the parent
    if (node->left == child or node->right == child)
    {
        return node;
    }

    // Use the binary search tree invariant to walk the tree
    if (child->data > node->data)
    {
        return find_parent(node->right, child);
    }
    else
    {
        return find_parent(node->left, child);
    }
}
