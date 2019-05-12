//
// Created by bartl on 05/10/2019.
//
#include "List.h"

List::List()  //Constructor
{
    head = new ListNode();
    tail = new ListNode();
    head->next = tail;
    head->previous = NULL;
    tail->previous = head;
    tail->next = NULL;
    count = 0;
}

List::List(const List &source)  //Copy Constructor
{
    // copied and pasted from index.html
    head = new ListNode;
    tail = new ListNode;
    head->next = tail;
    tail->previous = head;
    count = 0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd())
    {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List()  //Destructor
{
    delete head;
    delete tail;
}

List &List::operator=(const List &source)  //Equals Operator
{
    // copied and pasted from index.html
    if (this == &source)
    {
        return *this;
    }
    else
    {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd())
        {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const  //Returns true if empty{} else false
{
    return count == 0;
}

void List::makeEmpty()  //Removes all items except blank head and tail
{
    auto iter = ListItr(head->next);
    while (!iter.isPastEnd())
    {
        int valueToRemove = iter.retrieve();
        remove(valueToRemove);
        iter.moveForward();
    }
    head->next = tail;
    tail->previous = head;
    count = 0;
}

ListItr List::first()
{
    return head->next;
}        //Returns an iterator that points to
//the ListNode in the first position
ListItr List::last()
{
    return tail->previous;
}            //Returns an iterator that points to
//the ListNode in the last position
void List::insertAfter(int x, ListItr position)
{
    ListNode *beforeNewNode = position.current;
    ListNode *afterNewNode = beforeNewNode->next;
    auto *newNode = new ListNode();
    newNode->value = x;
    newNode->next = afterNewNode;
    newNode->previous = beforeNewNode;
    afterNewNode->previous = newNode;
    beforeNewNode->next = newNode;
    ++count;
}

//Inserts x after current iterator position p
void List::insertBefore(int x, ListItr position)
{
    ListNode *afterNewNode = position.current;
    ListNode *beforeNewNode = afterNewNode->previous;
    auto *newNode = new ListNode();
    newNode->value = x;
    newNode->next = afterNewNode;
    newNode->previous = beforeNewNode;
    afterNewNode->previous = newNode;
    beforeNewNode->next = newNode;
    ++count;
}

//Inserts x before current iterator position p
void List::insertAtTail(int x)
{
    auto iteratorTail = ListItr(tail);
    insertBefore(x, iteratorTail);
}    //Insert x at tail of list
void List::remove(int x)
{
    ListItr iterator = find(x);
    if (!iterator.isPastEnd())
    {
        ListNode *a = iterator.current;
        a->previous->next = a->next;
        a->next->previous = a->previous;
        delete a;
        --count;
    }
}        //Removes the first occurrence of x
ListItr List::find(int x)
{
    auto iterator = ListItr(head->next);
    while (!iterator.isPastEnd())
    {
        if (iterator.retrieve() == x)
        {
            return iterator;
        }
        iterator.moveForward();
    }
    return iterator;
}        //Returns an iterator that points to
// the first occurrence of x, else return a iterator to the dummy tail node

int List::size() const
{
    return count;
} //Returns the number of elements in the list

// printList: non-member function prototype
void printList(List &source, bool direction)
{
    if (direction)
    {
        ListItr iterator = source.first();
        while (!iterator.isPastEnd())
        {
            cout << iterator.retrieve() << " ";
            iterator.moveForward();
        }
    }
    else
    {
        ListItr iterator = source.last();
        while (!iterator.isPastBeginning())
        {
            cout << iterator.retrieve() << " ";
            iterator.moveBackward();
        }
    }
    cout << endl;
}