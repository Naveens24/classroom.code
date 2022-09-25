// This program first sort(using bubble sort in ascending) the array of 5 element in an array and then search the element of array using binary search.

#include<iostream>
using namespace std;

void bubbleSort(int a[])
{
        // int round = 0;
        for(int i=0; i<5; i++)
        {
                // round++;
                for (int j = 0; j < (5-i-1); j++)
                {
                        if(a[j]>a[j+1])
                        {
                           swap(a[j], a[j+1]);
                        }
                }
                
        }
}

int binarySearch(int ar[], int left, int right, int x)
{
        while (left <= right)
        {
                int mid = left + (right - left)/2;
                
                if(ar[mid] == x)
                {
                        return mid;
                }

                else if(ar[mid]<x)
                {
                        left = mid + 1;
                }

                else
                {
                        right = mid -1;
                }
        }
        return -1;
}

int main(){
        int arr[5];
        int n;
        int ans;
        int search;
        cout<<"Enter the 5 element to store in array: ";
        for(int i=0; i<5; i++)
        {
                cin>>arr[i];
        }
        cout<<endl;
        cout<<"Unsorted Array is : ";
        for(int i=0; i<5; i++)
        {
                cout<<arr[i];
        }
        cout<<endl;
        bubbleSort(arr);
        cout<<"\nSorted array is: ";
        for(int i=0; i<5; i++)
        {
                cout<<arr[i];
        }
        cout<<endl;
        
        //Using Binary search to search element in an array
        
        cout<<"\nPlease Enter an element which you want to search"<<endl;
        cin>>search;
        
        ans = binarySearch(arr,0,5, search);
       
        if(ans== -1 )
        {
                cout<<"No Match Found"<<endl;
        }
        else
        {
                cout<<"Match found at position: "<< ans+1 <<endl;
        }
        
return 0;
}
