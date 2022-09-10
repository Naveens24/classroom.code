#include<iostream>
using namespace std;

int main()
{

        int arr[20], size, i, del, count=0;

        cout<<"Enter array size( Max:20 ) :: "<<endl;
        cin>>size;
        cout<<"Enter array elements :: \n";

        for(i=0; i<size; i++)
        {
                cin>>arr[i];
        }
        cout<<endl;
        // Search that number if found then place the next element after 
        // the founded element to the back until the last.

        cout<<"Enter element to be delete :: "<<endl;
        cin>>del;

        for(i=0; i<size; i++)
        {
                if(arr[i]==del)
                {
                        for(int j=i; j<(size-1); j++)
                        {
                                arr[j]=arr[j+1];
                        }
                        count++;
                        break;
                }
        }
        if(count==0)
        {
                cout<<"Element not found..!!\n";
        }
        else
        {
                cout<<"Element deleted successfully..!!\n";
                cout<<"\nNow the new array is ::\n";
                for(i=0; i<(size-1); i++)
                {
                        cout<<arr[i]<<" ";
                }
        }
    cout<<"\n";

        return 0;
}
