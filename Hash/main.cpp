#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;
int IDs[125];

void generate_Records(int);
struct Node
{
    double key;
    Node *next;
};
class NumberList
{
    private:
        Node *head;
        int length;
    public:
        NumberList();
        void displayList();
        void insertItem(Node * newNode);
        int getItem(int nodeKey);
        int getLength();
        ~NumberList();
};
NumberList::NumberList()
{
    head = NULL;
    length = 0;
}
void NumberList::displayList()
{
    Node *nodePtr;
    nodePtr = head;
    while(nodePtr!=NULL)
    {
        cout<<" "<<nodePtr->key;
        nodePtr = nodePtr->next;
    }
}
void NumberList::insertItem(Node * newNode )
{
    Node *nodePtr;
    if(!head)
    {
        head = newNode;
        length++;
    }
    else
    {
        nodePtr = head;
        while(nodePtr->next)
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;
        newNode->next = NULL;
        length++;
    }
}
int NumberList::getItem(int itemKey)
{
    Node * nodePtr = head;
    int count = 1;
    while (nodePtr)
    {
        if ((nodePtr != NULL) && (nodePtr -> key == itemKey))
        {
            return nodePtr->key;
        }
        nodePtr = nodePtr -> next;
        count++;
    }
    return 0;
}
int NumberList::getLength()
{
    return length;
}
NumberList::~NumberList()
{
    Node *p = head;
    while(head)
    {
        head = p->next;
        delete p;
        p=head;
    }
}
class DHash
{
    private:
        NumberList * array;
        int length;
        int hash(int itemKey);
    public:
        DHash(int tableLength = 125);
        void insertItem(Node * newItem);
        int getItemByKey(int itemKey);
        void printRecords();
        void printKeyTable();
        int getLength();
        int getNumberOfItems();
        ~DHash();
};
DHash::DHash(int tableLength)
{
    if (tableLength <= 0)
        tableLength = 125;
    array = new NumberList[tableLength];
    length = tableLength;
}
int DHash::hash(int itemKey)
{
    return (itemKey % 47);
}
void DHash::insertItem(Node * newItem)
{
    int index = hash( newItem -> key );
    array[index].insertItem(newItem);
}
int DHash::getItemByKey(int itemKey )
{
    int index = hash(itemKey);
    int res = array[index].getItem(itemKey);
    return res;
}
void DHash::printRecords()
{
    cout << endl << "Hash Table: ";
    for ( int i = 0; i < 43; i++ )
    {
        cout << "Bucket " << i + 1 << ": ";
        array[i].displayList();
    }
}
void DHash::printKeyTable()
{
    cout << endl << "Hash Table Contains "<< getNumberOfItems() <<" records" << endl;
    for ( int i = 0; i < 43; i++ )
    {
        cout <<"Key "<<i + 1 << ":\t";
        array[i].displayList();
        cout << endl;
    }
}
int DHash::getLength()
{
    return length;
}
int DHash::getNumberOfItems()
{
    int itemCount = 0;
    for ( int i = 0; i < length; i++ )
    {
        itemCount += array[i].getLength();
    }
    return itemCount;
}
DHash::~DHash()
{
    delete [] array;
}
class MHash
{
    private:
        NumberList * array;
        int length;
        int mhash(int itemKey);
    public:
        MHash(int tableLength = 125);
        void insertData( Node * newItem );
        int getItemByKey(int itemKey );
        void printRecords();
        void printKeyTable();
        int getLength();
        int getNumberOfItems2();
        ~MHash();
};
MHash::MHash(int tableLength)
{
    if (tableLength <= 0)
        tableLength = 125;
    array = new NumberList[tableLength];
    length = tableLength;
}
int MHash::mhash(int k)
{
    double a = 0.61803398875;
    int hashCode = fmod((k*fmod(a,1.0)),13);
    return (hashCode);
}
void MHash::insertData(Node * newItem)
{
    int index = mhash(newItem -> key);
    array[index].insertItem(newItem);
}

int MHash::getItemByKey(int itemKey)
{
    int index = mhash(itemKey);
    int res = array[index].getItem(itemKey);
    return res;
}
void MHash::printRecords()
{
    cout << endl << "Hash Table:";
    for ( int i = 0; i < 43; i++ )
    {
        cout << "Bucket " << i + 1 << ": ";
        array[i].displayList();
    }
}
void MHash::printKeyTable()
{
    cout << "Hash Table Contains " << getNumberOfItems2() << " records" << endl;
    for ( int i = 0; i < 43; i++ )
    {
        cout <<"Key "<<i + 1 << " : \t";
        array[i].displayList();
        cout << endl;
    }
}
int MHash::getLength()
{
    return length;
}
int MHash::getNumberOfItems2()
{
    int itemCount = 0;
    for (int i = 0; i < length; i++)
    {
        itemCount += array[i].getLength();
    }
    return itemCount;
}
MHash::~MHash()
{
    delete [] array;
}
void generate_Records(int records)
{
    cout << "Generating 125 student IDs randomly: " << endl << endl;
    cout << "The student IDs are: " << endl;
    for(int i=0 ;i < records ; i++)
    {
        int id = rand() % 9999;
        if(id < 999)
            id = rand() % 9999;
        if(id > 999)
        {
            IDs[i] = id;
            cout << "STUDENT ID " << i+1 << setw(5) << " = " << setw(5) << id << endl;
        }
    }
}
int main()
{
    generate_Records(125);
    
    Node * array[125];
    Node * array2[125];
    
    for(int k=0 ;k < 125; k++)
    {
        array[k] = new Node{static_cast<double>(IDs[k]), NULL};
        array2[k] = new Node{static_cast<double>(IDs[k]), NULL};
    }
    DHash table1;
    MHash table2;
    
    cout << endl << "Division Method " << endl;
    for(int k = 0 ;k < 125 ; k++)
    {
        table1.insertItem(array[k]);
    }
    table1.printKeyTable();
    
    int searchID;
    for(int i=0;i<10;i++)
    {
        cout << endl << "Enter ID to be searched: ";
        cin >> searchID;
        int result = table1.getItemByKey(searchID);
        if(result <= 0)
            cout << "ID not found." << endl;
        else
            cout << endl << "ID found      : " << result << endl;
    }
    cout << endl << "Multiplication Method " << endl;
    for( int k=0 ;k < 125 ; k++)
    {
        table2.insertData(array2[k]);
    }
    table2.printKeyTable();
    int search;
    for(int i=0 ;i < 10; i++)
    {
        cout<<endl<<"Enter ID to be searched: ";
        cin>>search;
        int result = table2.getItemByKey(search);
        if(result <= 0)
            cout << "ID not found." << endl;
        else
            cout << endl << "ID found       : " << result << endl;
    }
    return 0;
}


