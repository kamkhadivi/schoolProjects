//
//  file.cpp
//  PJ6
//
//  Created by Kamran Khadivi-Dimbali 
//

#include "file.hpp"
#include "tree.h"
#include <iostream>
#include <iomanip>

using namespace std;

Tree::Tree(){
    start=NULL;
}

// Copy constructor
Tree::Tree(const Tree& other){
    start = NULL;
    copyOther(other);
}

//Destructor
Tree::~Tree()
{
    clearFrom(start);
}

// overloaded Assignment Operator
Tree& Tree::operator=(const Tree& other)
{
    start = new TreeNode;
    copyOther(other);
    return *this;
    
}

// Similar to insert function we discussed earlier
// creates node and inserts it at appropriate position.
void Tree::push(int value)
{
    TreeNode *node = new TreeNode;
    node->value = value;
    if(start == NULL)
        start = node;
    else
        pushFrom(start, node);
}

// Returns the address of the node containing the value.
TreeNode* Tree::find(int value) const
{
    return findFrom(start,value);
}

// Print the tree data
void Tree::print() const
{
    printFrom(start, 2);
    cout << endl;
}

// Deletes the node with value in the tree and deallocates its memory.
void Tree::deleteNode(int value)
{
    deleteFrom(start, value);
}


//copyOther
// you should implement and use this helper function inside your
// copy constructor and overloadedAssignment operator.
void Tree::copyOther(const Tree& other)
{
    clear();
    if(other.start == NULL) return;
    push(other.start->value);
    copyFrom(other.start->left);
    copyFrom(other.start->right);
}

// clear
// you should implement and use this function inside your
// destructor to delete all the nodes and free memory
void Tree::clear()
{
    clearFrom(start);
    start = NULL;
    
}

// pushFrom
// Recursively push a single element into a tree.
// Use it in your push function.
void Tree::pushFrom(TreeNode* startingPoint, TreeNode* nodeToPush)
{
    if(nodeToPush->value < startingPoint->value){
        if(startingPoint->left != NULL){
            pushFrom(startingPoint->left, nodeToPush);
        }
        else{
            startingPoint->left = nodeToPush;
        }
    }
    else if (nodeToPush->value >startingPoint->value){
        if (startingPoint->right != NULL) {
            pushFrom(startingPoint->right, nodeToPush);
        }
        else{
            startingPoint->right = nodeToPush;
        }
    }
}

// findFrom
// Recursively find a single element in a tree.
TreeNode* Tree::findFrom(TreeNode* startingPoint, int value) const
{
    if(startingPoint == NULL)
        return NULL;
    if(startingPoint->value == value)
        return startingPoint;
    else if (startingPoint->value < value)
        return findFrom(startingPoint->right, value);
    else
        return findFrom(startingPoint->left, value);
}

// printFrom
//
// Recursively print the values in a tree. Use
// pre-order traversal.
//
// If a tree looks like this:
//
//           6
//          /  \
//         /    \
//        5      8
//       /      / \
//      /      /   \
//     0      7     9
//
// then it should be printed like this:
//
// 6
//   5
//     0
//   8
//     7
//     9
//
//  Helper function that you should use inside your print function

void Tree::printFrom(TreeNode* startintPoint, int numSpaces) const
{
    if(startintPoint == NULL)
    {
        return;
    }
    
    cout << setw(numSpaces) << " " << startintPoint->value << endl;
    
    printFrom(startintPoint->left, numSpaces + 3);
    printFrom(startintPoint->right, numSpaces + 3);
}

// copyFrom
// Recursively copy another tree's nodes. Use
// pre-order traversal. Use this in CopyOther function.
void Tree::copyFrom(TreeNode* startintPoint)
{
    if(startintPoint == NULL) return;
    TreeNode *n = new TreeNode();
    n->value = startintPoint->value;
    pushFrom(start, n);
    copyFrom(startintPoint->left);
    copyFrom(startintPoint->right);
    
}

// deleteFrom
// should implement and use in the delete function.
// Deletes the node with the value specified in the below function.
void Tree::deleteFrom(TreeNode* startintPoint, int value)
{
    if(startintPoint == NULL) return;
    TreeNode* node = startintPoint;
    TreeNode* parent = NULL;
    
    while(node != NULL)
    {
        if(node->value == value)
            break;
        else
        {
            parent = node;
            if(value < node->value)
                node = node->left;
            else
                node = node->right;
        }
    }
    
    if(node == NULL)
        return;
    
    
    if(node->left == NULL && node->right == NULL)
    {
        if(parent == NULL)
        {
            start = NULL;
        }
        else
        {
            if(parent->left == node)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        delete node;
    }
    //left side
    else if(node->left != NULL && node->right == NULL)
    {
        if(parent == NULL)
        {
            start = node->left;
        }
        else
        {
            if(parent->left == node)
                parent->left = node->left;
            else
                parent->right = node->left;
        }
        delete node;
    }
    
    //right side
    else if(node->left == NULL && node->right != NULL)
    {
        if(parent == NULL)
        {
            start = node->right;
        }
        else
        {
            if(parent->left == node)
                parent->left = node->right;
            else
                parent->right = node->right;
        }
        delete node;
    }
    else
    {
        TreeNode* succParent = node;
        TreeNode* successor = node->right;
        while(successor->left != NULL)
        {
            succParent = successor;
            successor = successor->left;
        }
        
        int copyVal = successor->value;
        deleteFrom(start, copyVal);
        node->value = copyVal;
    }
}

// clearFrom
// Recursively delete nodes. Use post-order traversal.
// Use it in clear function.
void Tree::clearFrom(TreeNode* startingPoint)
{
    if(startingPoint == NULL)
        return;
    clearFrom(startingPoint->left);
    clearFrom(startingPoint->right);
    
    delete startingPoint;
    
}

