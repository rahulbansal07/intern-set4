Ques 1: Union and Intersection of two sorted arrays

#include <bits/stdc++.h>
using namespace std;
 
void printIntersection(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else 
        {
            cout << arr2[j] << " ";
            i++;
            j++;
        }
    }
}
 
void printUnion(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            cout << arr1[i++] << " ";
 
        else if (arr2[j] < arr1[i])
            cout << arr2[j++] << " ";
 
        else {
            cout << arr2[j++] << " ";
            i++;
        }
    }
 
   
    while (i < m)
        cout << arr1[i++] << " ";
 
    while (j < n)
        cout << arr2[j++] << " ";
}
int main()
{
    int m,n;
    cin>>m>>n;
    int arr1[m];
    int arr2[n];
 

    printIntersection(arr1, arr2, m, n);
    printUnion(arr1, arr2, m, n);

 
    return 0;
}
************************************************************************************
Ques 2.
Write a function rotate(arr[], d, n) that rotates arr[] of size n by d elements.
Rotation of the above array by 2 will make array

#include <bits/stdc++.h>
using namespace std;
 

int gcd(int a, int b)
{
    if (b == 0)
        return a;
 
    else
        return gcd(b, a % b);
}
 

void leftRotate(int arr[], int d, int n)
{
    
    d = d % n;
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++) {
       
        int temp = arr[i];
        int j = i;
 
        while (1) {
            int k = j + d;
            if (k >= n)
                k = k - n;
 
            if (k == i)
                break;
 
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}
 

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
 

int main()
{   
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
         cin>>arr[i];
    }
 
 

    leftRotate(arr, 2, n);
    printArray(arr, n);
 
    return 0;
}