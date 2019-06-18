//
// Created by bartl on 06/06/2019.
//

#include "BinaryNode.h"

BinaryNode::BinaryNode()
{
    value = "";
    left = nullptr;
    right = nullptr;
}

BinaryNode::~BinaryNode()
{
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
}
