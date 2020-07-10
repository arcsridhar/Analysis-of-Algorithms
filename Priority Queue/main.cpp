#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

struct node
{
    string jobName;
    string submitter;
    int jobNumber;
    int priority;
} jobs[120];

int hsize = 0;

int parent(int i)
{
    return ceil(i / 2.0 - 1);
}

void decreaseKey(int i, node n)
{
    if(n.priority> jobs[i].priority)
    {
        cout<<"Error\n";
        return;
    }
    jobs[i] = n;
    while(i > 0 && jobs[parent(i)].priority > jobs[i].priority)
    {
        std:: swap(jobs[i], jobs[parent(i)]);
        i = parent(i);
    }
}

void minHeapify(int i){
    int largest;
    int l = 2*i +1;
    if (l < hsize && jobs[l].priority < jobs[i].priority)
        largest = l;
    else
        largest = i;
    int r = 2*i +2;
    if (r < hsize && jobs[r].priority < jobs[largest].priority)
        largest = r;
    if (largest != i)
    {
        swap(jobs[i], jobs[largest]);
        minHeapify(largest);
    }
}

void heapInsert(node n)
{
    ++hsize;
    jobs[hsize - 1].priority = INT_MAX;
    decreaseKey(hsize - 1, n);
}

node extractMin()
{
    if(hsize < 0)
        cout << "Heap Underflow" << endl;
    
    node min = jobs[0];
    jobs[0] = jobs[hsize - 1];
    --hsize;
    minHeapify(0);
    return min;
}

void printPriorityQueue()
{
    cout<<"Jobs in Ready Queue are :\n";
    cout<<"Job# \tJobName \tSubmitter \tPriority"<<endl;
    for(int i=0;i<hsize;i++)
    {
        cout<<jobs[i].jobNumber<<"\t\t"<<jobs[i].jobName<<"\t\t\t"<<jobs[i].submitter<<"\t\t\t\t"<<jobs[i].priority;
        cout<<endl;
    }
    
    
}

void remove()
{
    if(hsize>0)
    {
        node ext = extractMin();
        cout<<"The Job deleted is :"<<endl;
        cout<<"Job# \tJobName \tSubmitter \tPriority"<<endl;
        cout<<ext.jobNumber<<"\t\t"<<ext.jobName<<"\t\t\t"<<ext.submitter<<"\t\t\t\t"<<ext.priority;
        cout<<endl;
    }
    else
        cout<<"The Queue is empty"<<endl;
}


void readyQueue(){
    int i;
    if(hsize>0)
    {
        cout<<"Enter the number of jobs to be moved to Ready Queue:\n";
        cin>>i;
        cout<<"Below Jobs moved to Ready Queue"<<endl;
        node readyQueue[i];
        for(int j=0;j<i;j++)
            readyQueue[j]=extractMin();
        while(i!=0)
        {
            node ext = extractMin();
            cout<<ext.jobNumber<<"\t\t\t"<<ext.jobName<<"\t\t\t"<<ext.submitter<<"\t\t\t\t"<<ext.priority;
            cout<<endl;
            i--;
        }
    }else
        cout<<"Queue is empty!!!"<<endl;
}

void inputQueueItems()
{
    int i;
    cout << "Enter the total jobs :";
    cin >> i;
    while(i--)
    {
        node n;
        cout <<"Enter JobNumber, JobName, Submitter and Priority:\n";
        cin >> n.jobNumber;
        cin >> n.jobName ;
        cin >> n.submitter;
        cin >> n.priority;
        heapInsert(n);
    }
    cout<<"\nWait Queue after Heapify:\n";
    cout<<"Job# \tJobName \tSubmitter \tPriority"<<endl;
    for(int i=0 ; i < hsize ; i++)
    {
        cout<<jobs[i].jobNumber<<"\t\t"<<jobs[i].jobName<<"\t\t\t"<<jobs[i].submitter<<"\t\t\t\t"<<jobs[i].priority;
        cout<<endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << endl;
        cout <<"PRIORITY QUEUE USING HEAP" << endl << endl;
        cout<<"1.Insert" << endl;
        cout<<"2.Delete" << endl;
        cout<<"3.Display" << endl;
        cout<<"4.Ready Queue" << endl;
        cout<<"5.Quit" << endl << endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                inputQueueItems();
                break;
            case 2:
                remove();
                break;
            case 3:
                printPriorityQueue();
                break;
            case 4:
                readyQueue();
                break;
            case 5:
                break;
            default :
                cout<<"Wrong choice\n";
        }
    }while(choice != 4);
    return 0;
}

