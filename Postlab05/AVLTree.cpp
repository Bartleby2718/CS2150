#include "AVLTree.h"
#include <iostream>
#include <string>
#include "AVLNode.h"

using namespace std;

AVLTree::AVLTree()
{
    root = NULL;
}

AVLTree::~AVLTree()
{
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string &x)
{
    root = insert(root, x);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string &x)
{
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string &x) const
{
    if (!find(x))
    {
        return "";
    }
    string path = root->value;
    AVLNode *node = root;
    while (x != node->value)
    {
        node = (x < node->value) ? (node->left) : (node->right);
        path += ' ' + node->value;
    }
    return path;
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string &x) const
{
    AVLNode *node = root;
    while (node != nullptr && x != node->value)
    {
        node = (x < node->value) ? (node->left) : (node->right);
    }
    return node != nullptr;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const
{
    return numDescendants(root);
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode *&n)
{
    //Note that balance factor here is assumed to be height of right - left subtree
    int factor;
    while (factor = getBalanceFactor(n), (factor > 2 || factor < -2))
    {
        n = (factor > 0) ? (n->right) : (n->left);
    }
    if (factor == 2)
    {
        if (getBalanceFactor(n->right) < 0)
        {
            n->right = rotateRight(n->right);
        }
        n = rotateLeft(n);
    }
    else if (factor == -2)
    {
        if (getBalanceFactor(n->left) > 0)
        {
            n->left = rotateLeft(n->left);
        }
        n = rotateRight(n);
    }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode *AVLTree::rotateLeft(AVLNode *&n)
{
    AVLNode *newPivot = n->right;
    n->right = newPivot->left;
    newPivot->left = n;
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);
    newPivot->height = 1 + max(height(newPivot->left), height(newPivot->right));
    balance(newPivot);
    return newPivot;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode *AVLTree::rotateRight(AVLNode *&n)
{
    AVLNode *newPivot = n->left;
    n->left = newPivot->right;
    newPivot->right = n;
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);
    newPivot->height = 1 + max(height(newPivot->left), height(newPivot->right));
    balance(newPivot);
    return newPivot;
}

// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode *AVLTree::remove(AVLNode *&n, const string &x)
{
    if (n == NULL)
    {
        return NULL;
    }
    // first look for x
    if (x == n->value)
    {
        // found
        // no children
        if (n->left == NULL && n->right == NULL)
        {
            delete n;
            n = NULL;
            return NULL;
        }
        // single child
        if (n->left == NULL)
        {
            AVLNode *temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        }
        if (n->right == NULL)
        {
            AVLNode *temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        }
        // two children -- tree may become unbalanced after deleting n
        string sr = min(n->right);
        n->value = sr;
        n->right = remove(n->right, sr);
    }
    else if (x < n->value)
    {
        n->left = remove(n->left, x);
    }
    else
    {
        n->right = remove(n->right, x);
    }
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);
    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode *node) const
{
    // go to bottom-left node
    if (node->left == NULL)
    {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode *node) const
{
    if (node == NULL)
    {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == nullptr)
    {
        return;
    }
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode *root, Trunk *prev, bool isRight)
{
    if (root == NULL)
    {
        return;
    }

    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
    {
        trunk->str = "---";
    }
    else if (isRight)
    { // github user @willzhang05 pointed out that I forgot to change this from isLeft to isRight on my first commit
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << "(" << root->height << ")" << endl;

    if (prev)
    {
        prev->str = prev_str;
    }
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

void AVLTree::printTree()
{
    printTree(root, NULL, false);
}

int AVLTree::numDescendants(AVLNode *node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + numDescendants(node->left) + numDescendants(node->right);
    }
}

int AVLTree::getBalanceFactor(AVLNode *node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    return height(node->right) - height(node->left);
}

AVLNode *AVLTree::insert(AVLNode *&n, const string &x)
{
    if (n == nullptr)
    {
        n = new AVLNode();
        n->value = x;
        return n;
    }

    if (x == n->value)
    {
        return n;
    }

    if (x < n->value)
    {
        n->left = insert(n->left, x);
    }
    else if (x > n->value)
    {
        n->right = insert(n->right, x);
    }
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);
    return n;
}
