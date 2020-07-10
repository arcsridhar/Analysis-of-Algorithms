//
//  main.cpp
//  Queue
//
//  Created by AS on 4/19/19.
//  Copyright © 2019 a_s1316. All rights reserved.
//


#include "Queue.h"

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct RollerCoaster
{
    string people;
    int number;
};

int main()
{
    struct RollerCoaster riders[10];
    int seats,num;
    string name;
    int count = 0;
    ifstream inputFile;
    inputFile.open("/Users/Arjun/Documents/C++/Projects/Stack/Queue/Queue/riders.txt");
    if(!inputFile)
    {
        cout << "Unable to open the file" << endl;
        return 0;
    }
    else
    {
        while (!inputFile.eof() && inputFile >> seats)
        {
            inputFile >> ws;
            getline (inputFile, name);
            inputFile >> num;
            
            riders[count].people = name;
            riders[count].number = num;
            count++;
        }
        inputFile.close();
        
    }
}
