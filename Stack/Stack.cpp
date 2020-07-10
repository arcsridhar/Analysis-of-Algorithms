// File Name: StackDriver.cpp
//
// Author: Jill Seaman
// Date: 4/14/2019
// Assignment Number: 6
// CS 2308.255 and CS 5301 Spring 2019
// Instructor: Jill Seaman
//
// A demo driver for Stack.
//

#include <iostream>
#include <cassert>
#include "Stack.h"
Stack :: Stack ()
{
    head = NULL;
}
void Stack :: push(string x)
{
    Node *newNode;
    newNode = new Node;
    newNode->value = x;
    
    if(!isEmpty())
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}
string Stack :: pop()
{
    string result;
    if(!isEmpty())
    {
        result = head->value;
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    return result;
}
bool Stack :: isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
