/*
 * Filename: AVLTree.cpp
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
    // TODO: Students write code here
}

AVLTree::AVLTree(const AVLTree &source)
{
    // check during office hours
    
    root = pre_order_copy(root);
    // TODO: Students write code here
}

AVLTree::~AVLTree()
{
    post_order_delete(root);
    // TODO: Students write code here
}

// assignment overload
AVLTree &AVLTree::operator=(const AVLTree &source)
{
    if (this == &source) {
        return *this;
    }

    Node *tree_copy = pre_order_copy(root);
    post_order_delete(root);
    root = tree_copy;
    // TODO: Students write code here
    // check for self-assignment

    // delete current tree if it exists

    // use pre-order traversal to copy the tree

    // don't forget to "return *this"
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

Node *AVLTree::find_min(Node *node) const
{
    assert(node != nullptr);
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
    // TODO: Students write code here

    // This line is in here so that the starter code compiles.
    // Remove or modify it when implementing.
    
}

Node *AVLTree::find_max(Node *node) const
{
    assert(node != nullptr);
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
    // TODO: Students write code here

    // This line is in here so that the starter code compiles.
    // Remove or modify it when implementing.
}

bool AVLTree::contains(Node *node, int value) const
{
    if (node == nullptr) {
        return false;
    }
    if (node->data > value) {
        contains(node->left, value);
    } else if (node->data < value) {
        contains(node->right, value);
    } else {
        return true;
    }
    // TODO: Students write code here

    // This line is in here so that the starter code compiles.
    // Remove or modify it when implementing.
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

int AVLTree::tree_height(Node *node) const
{
    // check during office hours

    // TODO: Students write code here

    // This line is in here so that the starter code compiles.
    // Remove or modify it when implementing.
    return root->height;
}

int AVLTree::node_count(Node *node) const
{
    if (node == nullptr) {
        return 0;
    }

    int left_nodes = node_count(node->left);
    int right_nodes = node_count(node->right);
    // TODO: Students write code here

    // This line is in here so that the starter code compiles.
    // Remove or modify it when implementing.
    return 1 + left_nodes + right_nodes;
}

int AVLTree::count_total(Node *node) const
{
    // check during office hours
    if (node == nullptr) {
        return 0;
    }

    int left_nodes = node_count(node->left);
    int right_nodes = node_count(node->right);

    int node_multiplicity = 0;
    if (node->count > 1) {
        node_multiplicity = node->count - 1;
    }
    // TODO: Students write code here

    // This line is in here so that the starter code compiles.
    // Remove or modify it when implementing.
    return 1 + left_nodes + right_nodes + node_multiplicity;
}

Node *AVLTree::pre_order_copy(Node *node) const
{
    if (node == NULL)
    {
        return NULL;
    }
    Node *new_node = new Node();
    new_node->data = node->data;

    new_node->left = pre_order_copy(node->left);
    new_node->right = pre_order_copy(node->right);
    // TODO: Students write code here
    // (hint: use a pre-order traversal to copy details from the
    // node to a new_node)

    return new_node;
}

void AVLTree::post_order_delete(Node *node)
{
    if (node == NULL) {
        return;
    }
    post_order_delete(node->left);
    post_order_delete(node->right);
    delete node;
    // TODO: Students write code here
}

Node *AVLTree::balance(Node *node)
{
    // TODO: Students write code here

    // This line is in here so that the starter code compiles.
    // Remove or modify it when implementing.
    return node;
}

Node *AVLTree::right_rotate(Node *node)
{
    // TODO: Students write code here

    // This line is in here so that the starter code compiles.
    // Remove or modify it when implementing.
    return node;
}

Node *AVLTree::left_rotate(Node *node)
{
    // TODO: Students write code here

    // This line is in here so that the starter code compiles.
    // Remove or modify it when implementing.
    return node;
}

int AVLTree::height_diff(Node *node) const
{
    // TODO: Students write code here

    // This line is in here so that the starter code compiles.
    // Remove or modify it when implementing.
    return 0;
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
