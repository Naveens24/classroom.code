#include<iostream>
using namespace std;

int main()
{
    int i;
    int a[5] = {2, 4, 6, 8, 10};
    
    cout<<"Programme to print the element of the array"<<endl;
    for(i=0; i<5; i++)
    {
        cout<<"position:"<< i <<", value:"<<a[i]<<endl;
    }
}
