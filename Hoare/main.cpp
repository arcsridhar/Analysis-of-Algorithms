#include<iostream>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int count=0;
    int pivot = arr[high];  // pivot
    int i = (low - 1);     // Index of smaller element
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            count++;
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    cout << "COUNT 1 is :"<<count <<endl;
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    int count=0;
    if (low < high)
    {
        count++;
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    cout << "COUNT 2 is :" <<count<<endl;
}
// Driver program to test above functions
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
    quickSort(array, 0, n-1);
    cout<<"Sorted Array:" <<endl;
    for (i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
    return 0;
}
