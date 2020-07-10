//
//  Queue.h
//  Queue
//
//  Created by AS on 4/19/19.
//  Copyright © 2019 a_s1316. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
#include <string>
using namespace std;

class Queue
{
    private:
    static const int SIZE = 10;
    int arr[10];
    int numItems;
    int front;
    int rear;
    int count;      
    
    public:
    Queue();
    void enqueue(string);
    string dequeue();
    bool isEmpty();
    int size();  //returns the number of elements in the queue
};

#endif /* Queue_h */
