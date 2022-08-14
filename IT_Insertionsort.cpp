/*
WORKING-
1. Pick the element.
2. Compare with all elements in the sorted sub-list on the left
3. shift all the elements in thesorted sub-list theat is greater than the value to be sorted.
4. Insert the value.
5. Repeat until list is sorted.

*/

#include<iostream>
using namespace std;

void insertionSort(int arr[])
{
    int j=0;
    int key=0;
    for(int i=1; i<5; i++)
    {
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j + 1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main()
{
    
    int myarr[5];
    
    cout<<"Enter the 5 Element of the Array "<<endl;
    for(int i=0; i<5; i++)
    {
        cin>>myarr[i] ;
    }

    cout<<"UNSORTED ARRAY"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<myarr[i]<<" ";
    }

    insertionSort(myarr);

    cout<<endl<<"SORTED ARRAY"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<myarr[i]<<" ";
    }


}
