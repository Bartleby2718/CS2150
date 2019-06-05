// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include <iostream>
#include "TreeCalc.h"

using namespace std;

//Constructor
TreeCalc::TreeCalc()
{
}

//Destructor- frees memory
TreeCalc::~TreeCalc()
{
    if (!mystack.empty())
    {
        cleanTree(mystack.top());
    }
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode *ptr)
{
    if (ptr == nullptr)
    {
        return;
    }
    if (ptr->left != nullptr)
    {
        cleanTree(ptr->left);
    }
    if (ptr->right != nullptr)
    {
        cleanTree(ptr->right);
    }
    delete ptr;
}

//Gets data from user
void TreeCalc::readInput()
{
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
           || response[0] == '-' || response[0] == '+')
    {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string &val)
{
    // insert a value into the tree
    auto *node = new TreeNode(val);
    if (val == "+" || val == "-" || val == "*" || val == "/")
    {
        auto *right = mystack.top();
        node->right = right;
        mystack.pop();
        auto *left = mystack.top();
        node->left = left;
        mystack.pop();
    }
    mystack.push(node);
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode *ptr) const
{
    // print the tree in prefix format
    if (ptr == nullptr)
    {
        return;
    }
    cout << ptr->value << ' ';
    if (ptr->left != nullptr)
    {
        printPrefix(ptr->left);
    }
    if (ptr->right != nullptr)
    {
        printPrefix(ptr->right);
    }
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode *ptr) const
{
    // print tree in infix format with appropriate parentheses
    if (ptr == nullptr)
    {
        return;
    }

    if (ptr->left == nullptr && ptr->right == nullptr)
    {
        cout << ptr->value;
    }
    else
    {
        cout << '(';
        printInfix(ptr->left);
        cout << ' ' << ptr->value << ' ';
        printInfix(ptr->right);
        cout << ')';
    }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode *ptr) const
{
    // print the tree in postfix form
    if (ptr == nullptr)
    {
        return;
    }
    if (ptr->left != nullptr)
    {
        printPostfix(ptr->left);
    }
    if (ptr->right != nullptr)
    {
        printPostfix(ptr->right);
    }
    cout << ptr->value << ' ';
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const
{
    if (mystack.size() != 0 && mystack.top() != NULL)
    {
        cout << "Expression tree in postfix expression: ";
        // call your implementation of printPostfix()
        printPostfix(mystack.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        // call your implementation of printInfix()
        printInfix(mystack.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        // call your implementation of printPrefix()
        printPrefix(mystack.top());
        cout << endl;
    }
    else
    {
        cout << "Size is 0." << endl;
    }
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode *ptr) const
{
    // Traverse the tree and calculates the result
    // Case 1. null check (child of a leaf)
    if (ptr == nullptr)
    {
        return 0;
    }

    // Case 2. leaf (number)
    if (ptr->left == nullptr && ptr->right == nullptr)
    {
        return stoi(ptr->value);
    }

    // Case 3. non-leaf (operator)
    int left = calculate(ptr->left);
    int right = calculate(ptr->right);
    if (ptr->value == "+")
    {
        return left + right;
    }
    if (ptr->value == "-")
    {
        return left - right;
    }
    if (ptr->value == "*")
    {
        return left * right;
    }
    if (ptr->value == "/")
    {
        return left / right;
    }
    return 0;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate()
{
    int i = 0;
    // call private calculate method here
    if (!mystack.empty())
    {
        i += calculate(mystack.top());
    }
    return i;
}
