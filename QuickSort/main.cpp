//
//  main.cpp
//  QuickSort
//
//  Created by AS on 2/12/19.
//  Copyright © 2019 a_s1316. All rights reserved.
//

#include <iostream>
using namespace std;

void quick_sort(int[],int,int);
int partition(int[],int,int);

int main()
{
    int array[50],n,i;
    cout << "Enter the number of elements :";
    cin >> n;
    cout <<"Enter array elements:" << endl;
    
    for( i=0 ; i < n ; i++ )
        cin >> array[i];
    
    quick_sort(array,0,n-1);
    cout<<"Array after sorting:" << endl;
    
    for( i=0 ; i < n ; i++ )
        cout << array[i] << " ";
    cout << endl;
    return 0;
}

void quick_sort(int array[],int l,int u)
{
    int j;
    if( l < u )
    {
        j=partition(array,l,u);
        quick_sort(array,l,j-1);
        quick_sort(array,j+1,u);
    }
}

int partition(int array[],int l,int u)
{
    int v,i,j,temp,count=0;
    v=array[l];
    i=l;
    j=u+1;
    
    do
    {
        do
        {
            count++;
            i++;
        }while(array[i] < v && i <= u);
        do
        {
            count++;
            j--;
        } while( v < array[j]);
        if(i<j)
        {
            //count++;
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
        cout << "COUNT 3 is : " <<count << endl;
    }while( i < j );
    
    array[l]=array[j];
    array[j]=v;
    return(j);
}
