//
//  main.cpp
//  Maximum SubArray
//
//  Created by AS on 2/5/19.
//  Copyright (c) 2019 a_s1316. All rights reserved.
//

#include <iostream>
#include <limits>
using namespace std;

int max(int a, int b)
{
    return (a > b)? a : b;
}
int max(int a, int b, int c)
{
    return max(max(a, b), c);
}
int maxCrossingSum(int arr[], int low, int mid, int high)
{
    int count=0;
    // Include elements on left of mid.
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= low; i--)
    {
        count++;
        sum = sum + arr[i];
        if (sum > left_sum)
        left_sum = sum;
    }
    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int j = mid+1; j <= high; j++)
    {
        count++;
        sum = sum + arr[j];
        if (sum > right_sum)
        right_sum = sum;
    }
    cout << "\n Count : "<<count;
    // Return sum of elements on left and right of mid
    return (left_sum+right_sum);
}


int maxSubArraySum(int arr[], int low, int high)
{
    //if there is only one element
    if (low == high)
    {
        return arr[low];
    }
    
    else
    {
        int mid = (low + high)/2;
        int left_sum=maxSubArraySum(arr,low,mid);
        int right_sum=maxSubArraySum(arr,mid+1,high);
        int cross_sum=maxCrossingSum(arr,low,mid,high);
        if(left_sum >= right_sum && left_sum >= cross_sum)
            return left_sum;
        else if (right_sum >= left_sum && right_sum >= cross_sum)
            return right_sum;
        else
            return cross_sum;
    }
}

int main() 
{
    int size,array[50],i;
    cout << "Enter the array size :";
    cin >> size;
    cout <<"Enter the elements :";
    for (i=0 ; i < size ; i++)
    {
        cin >> array[i];
    }
    cout << "\nOriginal Array : ";
    for (i=0 ; i < size ; i++)
    {
        cout << " " << array[i] ;
    }
    cout <<endl;
    int max_sum = maxSubArraySum(array,0,size-1);
    cout << "Maximum contagious sum is " << max_sum << endl;
}