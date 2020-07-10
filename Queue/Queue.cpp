//
//  Queue.cpp
//  Queue
//
//  Created by AS on 4/19/19.
//  Copyright © 2019 a_s1316. All rights reserved.
//

#include <iostream>
#include "Queue.h"
Queue :: Queue()
{
    front = 0;
    rear = -1;
    numItems = 0;
    count = 0;
}
int Queue :: size()
{
    return count;
}
bool Queue :: isEmpty()
{
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Queue :: enqueue (string x)
{
    assert (isEmpty());
    
    Node *temp = new Node;
    temp->value = x;
    temp->next = NULL;
    
    if(isEmpty())
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}
string Queue :: dequeue()
{
    string result;
    if(!isEmpty())
    {
        result = front->value;
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    return result;
}
