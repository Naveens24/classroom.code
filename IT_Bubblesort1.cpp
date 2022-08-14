/*
Working:-
1. Starting with the first element (index =0) compare the current element with the next element of the array.
2. If the current element is greater than the next element with the next element of the array , swap them.
3. If the current element iss less than the next element , move to the next element.
4. Repea the step 1, 2, 3 respectively till the list is sorted.
*/

#include<iostream>
using namespace std;

void bubbleSort(int a[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < (5-i-1); j++)
        {
            if(a[j]>a[j+1])
            {
                //swap(a[j], a[j+i]);
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]=temp;

            }
        }
         
    }

}

int main()
{
    int arr[5];
    
    cout<<"Enter the 5 element to store in the array "<<endl;
    for(int i=0; i<5; i++)
    {
        cin>>arr[i];
    }

    cout<<"UNSORTED ARRAY IS : "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }

    bubbleSort(arr);
    cout<<endl<<"SORTED ARRAY ARE: "<<endl;
    for (int  i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}
