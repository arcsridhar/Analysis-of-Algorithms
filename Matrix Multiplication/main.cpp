#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
const int SIZE = 7;
int m[10][10], s[10][10];

void MatrixChainOrder(int *p,int (*m)[10],int (*s)[10],int length)
{
    int i,j,k,l;
    int n = length-1;
    int num = 0;
    for (i = 1; i < length; i++)
    {
        m[i][i] = 0;
    }
    for(l = 2; l <= n; l++)
    {
        for(i = 1;i <= n-l; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            
            for (k = i; k <= j-1; k++)
            {
                num = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if(num < m[i][j])
                {
                    m[i][j] = num;
                    s[i][j] = k;
                }
            }
        }
    }
}

void display(int (*m)[10],int (*s)[10],int matrix[])
{
    cout << "Matrix Dimensions :";
    cout << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << "[" << i << "]" << " = " <<matrix[i] << "  " << endl;
    }
    cout << endl << endl;
    cout << "Matrix M[I][J] "<< endl << "  ";
    
    cout << endl;
    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << setw(5) << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Matrix S[I][J] "<< endl;
    cout << "  ";
    
    cout << endl;
    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << setw(5) << s[i][j] << " ";
        }
        cout << endl;
    }
    int total=0;
    cout << endl;
    cout << "Maximum number of Multiplications are : ";
    int sum = 0;
    for (int k = 0; k < 4; k++)
    {
        sum = matrix[0] * matrix[k+2] * matrix[k+3];
        total += matrix[0] * matrix[k+1] * matrix[k+2] + sum;
    }
    cout << total << endl;
    
}

int main()
{
    cout << "Enter the total :"
    
    int arr1[SIZE] = {30, 35, 15, 05, 10, 20, 25};
    int arr2[SIZE] = {25, 15, 05, 10, 15, 25, 15};
    int arr3[SIZE] = {10, 30, 05, 15, 20, 10, 25};
    int arr4[SIZE] = {10, 25, 15, 30, 05, 20, 15};
    int arr5[SIZE] = {05, 10, 15, 20, 25, 30, 20};
    
    
    MatrixChainOrder(arr1,m,s,SIZE);
    display(m,s,arr1);
    cout << endl;

    MatrixChainOrder(arr2,m,s,SIZE);
    display(m,s,arr2);
    cout << endl;
    
    MatrixChainOrder(arr3,m,s,SIZE);
    display(m,s,arr3);
    cout << endl;
    
    MatrixChainOrder(arr4,m,s,SIZE);
    display(m,s,arr4);
    cout << endl;
   
    MatrixChainOrder(arr5,m,s,SIZE);
    display(m,s,arr5);
    cout << endl;
    
    return 0;
}


