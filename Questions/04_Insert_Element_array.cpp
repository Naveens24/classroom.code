 #include<iostream>
using namespace std;

int main()
{
    int arr[100],i, n, size=0;
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"Enter Element on Array :  "<<endl;
    for( i=0; i<size-1; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Enter the Element to Insert: ";
    cin>>n;
    arr[i]=n;

    cout<<"Updated Array is: ";
    for(i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

