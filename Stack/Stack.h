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

#include <string>
using namespace std;

class Stack
{
    private:
        struct Node
        {
            string value;
            Node* next;
        };
        Node* head;
    
    public:
        Stack();
        void push(string x) ;
        string pop() ;
        bool isEmpty();
};
