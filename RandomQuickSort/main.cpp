#include<iostream>

using namespace std;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int a[], int low, int high)
{
    int pivot, index, i,count=0;
    index = low;
    pivot = high;
    for(i=low; i < high; i++)
    {
        if(a[i] < a[pivot])
        {
            count++;
            swap(&a[i], &a[index]);
            index++;
        }
    }
    swap(&a[pivot], &a[index]);
    cout << "COUNT 3 IS :" <<count<<endl;
    return index;
}

int RandomPartition(int a[], int low, int high)
{
    int pvt,n,count=0;
    n = rand();
    count++;
    pvt = low + n%(high-low+1);
    swap(&a[high], &a[pvt]);
    cout <<"Count 2 is :" <<count<<endl;
    return Partition(a, low, high);
}
int RandomQuickSort(int a[], int low, int high)
{
    int pindex;
    if(low < high)
    {
        pindex = RandomPartition(a, low, high);
        RandomQuickSort(a, low, pindex-1);
        RandomQuickSort(a, pindex+1, high);
    }
    return 0;
}
int main()
{
    int n, i;
    cout << "Total number of elements :";
    cin >> n;
    int array[n];
    cout << "Enter array elements :" <<endl;
    for(i = 0; i < n; i++)
    {
        cin >>  array[i];
    }
    RandomQuickSort(array, 0, n-1);
    cout<<"Sorted Array:" <<endl;
    for (i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
    return 0;
}

