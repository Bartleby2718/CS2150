//
// Created by bartl on 06/06/2019.
//

#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    delete root;
    root = nullptr;
}

void BinarySearchTree::insert(const string &x)
{
    root = insert(x, root);
}

void BinarySearchTree::remove(const string &x)
{
    root = remove(root, x);
}

void BinarySearchTree::printTree()
{
    printTree(root, nullptr, false);
}

string BinarySearchTree::pathTo(const string &x) const
{
    string path;
    if (find(x))
    {
        path = pathTo(x, root);
        return path.substr(1, path.length() - 1);
    }
    else
    {
        return path;
    }
}

bool BinarySearchTree::find(const string &x) const
{
    return find(x, root);
}

int BinarySearchTree::numNodes() const
{
    return numNodes(root);
}

BinaryNode *BinarySearchTree::remove(BinaryNode *&n, const string &x)
{
    if (n == nullptr)
    {
        return n;
    }
    else if (x == n->value)
    {
        if (n->left != nullptr && n->right != nullptr) // 2 children
        {
            string nextSmallest = min(n->right);
            auto *newNode = new BinaryNode();
            newNode->value = nextSmallest;
            newNode->left = n->left;
            newNode->right = remove(n->right, nextSmallest);
            delete n;
            n = nullptr;
        }
        else if (n->left != nullptr && n->right == nullptr) // 1 child
        {
            BinaryNode *temp = n;
            n = n->left;
            delete temp;
        }
        else if (n->left == nullptr && n->right != nullptr) // 1 child
        {
            BinaryNode *temp = n;
            n = n->right;
            delete temp;
        }
        else // no child
        {
            delete n;
            n = nullptr;
        }
    }
    else if (find(x, n->left))
    {
        n->left = remove(n->left, x);
    }
    else if (find(x, n->right))
    {
        n->right = remove(n->right, x);
    }
    return n;
}

string BinarySearchTree::min(BinaryNode *node) const
{
    if (node == nullptr)
    {
        return "";
    }
    else if (node->left == nullptr)
    {
        return node->value;
    }
    else
    {
        return min(node->left);
    }
}

// code taken from https://github.com/aaronbloomfield/pdr/blob/master/labs/lab05/code/inlab/BinarySearchTree.cpp#L89
void showTrunks(Trunk *p)
{
    if (p == nullptr)
    {
        return;
    }
    showTrunks(p->prev);
    cout << p->str;
}

// code taken from https://github.com/aaronbloomfield/pdr/blob/master/labs/lab05/code/inlab/BinarySearchTree.cpp#L97
void BinarySearchTree::printTree(BinaryNode *root, Trunk *prev, bool isRight)
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
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev)
    {
        prev->str = prev_str;
    }
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

BinaryNode *BinarySearchTree::insert(const string &x, BinaryNode *node)
{
    if (node == nullptr)
    {
        node = new BinaryNode();
        node->value = x;
    }
    else if (x < node->value)
    {
        node->left = insert(x, node->left);
    }
    else if (x > node->value)
    {
        node->right = insert(x, node->right);
    }
    return node;
}

string BinarySearchTree::pathTo(const string &x, BinaryNode *node) const
{
    // assumes that x is somewhere in the tree that has "node" as its root
    string path = " " + node->value;
    if (x == node->value)
    {
        return path;
    }
    else if (find(x, node->left))
    {
        return path + pathTo(x, node->left);
    }
    else if (find(x, node->right))
    {
        return path + pathTo(x, node->right);
    }
    else // shouldn't get here because of the assumption
    {
        return path;
    }
}

bool BinarySearchTree::find(const string &x, BinaryNode *node) const
{
    if (node == nullptr)
    {
        return false;
    }
    else if (x == node->value)
    {
        return true;
    }
    else if (x < node->value)
    {
        return find(x, node->left);
    }
    else // x > node->value)
    {
        return find(x, node->right);
    }
}

int BinarySearchTree::numNodes(BinaryNode *node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + numNodes(node->left) + numNodes(node->right);
    }
}



