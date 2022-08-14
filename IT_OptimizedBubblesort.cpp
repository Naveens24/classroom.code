// Optimized Bubble sort(takes round 3) is more efficient than the basic bubble sort(round 5)

#include<iostream>
using namespace std;

// void bubbleSort(int a[])
// {
//     int round=0;
//     for (int i = 0; i < 5; i++)
//     {
//         round++;
//         for (int j = 0; j < (5-i-1); j++)
//         {
//             if(a[j]>a[j+1])
//             {
//                 //swap(a[j], a[j+i]);
//                 int temp = a[j];
//                 a[j] = a[j+1];
//                 a[j+1]=temp;

//             }
//         }
                
//     }
//     cout<<"\nNo of Round : "<<round<<endl;

// }

void optimizedbubbleSort(int a[])
{
    int round=0;
    
    for(int i=0; i<5; i++)
    {
        round++;
        int flag=false;
        for (int j = 0; j<(5-i-1); j++)
        {
            if(a[j]>a[j+1])
            {
                flag=true;
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        if(flag==false)
        {
            break;
        }
        
    }
    cout<<"\nNo of Round : "<<round<<endl;

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

    optimizedbubbleSort(arr);
    cout<<endl<<"SORTED ARRAY ARE: "<<endl;
    for (int  i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}
