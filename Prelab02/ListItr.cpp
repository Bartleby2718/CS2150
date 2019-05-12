//
// Created by bartl on 05/10/2019.
//
#include "ListItr.h"

ListItr::ListItr() = default;            //Constructor
ListItr::ListItr(ListNode *theNode)
{
    current = theNode;
}    // One parameter constructor
bool ListItr::isPastEnd() const
{
    return current->next == NULL;
}    //Returns true if past end position
// in list, else false
bool ListItr::isPastBeginning() const
{
    return current->previous == NULL;
}//Returns true if past first position
// in list, else false
void ListItr::moveForward()
{
    current = current->next;
}    //Advances current to next position in list
//(unless already past end of list)
void ListItr::moveBackward()
{
    current = current->previous;
}    //Moves current back to previous position
// in list (unless already past beginning of
// list)
int ListItr::retrieve() const
{
    return current->value;
}    //Returns item in current position
