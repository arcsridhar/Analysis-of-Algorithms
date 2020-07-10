//
//  Insertion sort
//  a_s1316
//  Archana Sridhar
//

#include <iostream>
#include <cstdlib>
using namespace std;

void insertion_sort(int arr[],int size)
{
    int i,j,temp;
    int count=0;
    for(i=0; i<size; i++)
    {
        count++;
        temp=arr[i];
        j=i-1;
        while ((temp < arr[j] && (j >=0)))
        {
            count++;
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
    cout<<"\nTotal no of iterations used to sort is : "<< count <<"\n";
}

void display(int arr[],int size)
{
    for(int i=0; i<size; i++)
    {
        cout<< arr[i] <<" ";
    }
    cout<<endl;
}

int main()
{
    int size, array[10], i;
    cout<<"Enter Array Size : ";
    cin>>size;
    cout<<"Enter Array Elements : ";
    for(i=0; i<size; i++)
    {
        cin>>array[i];
    }
    insertion_sort(array,size);
    cout<<endl;
    cout<<"\nThe Sorted Array is :" << endl;
    display(array,size);
    cout<<endl;
//    return 0;
}