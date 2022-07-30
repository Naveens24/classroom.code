#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    cout<<"Programme to print the greatest among three number"<<endl;
    cout<<"Enter the first number:"<<endl;
    cin>>a;
    cout<<"Enter the second number:"<<endl;
    cin>>b;
    cout<<"Enter the third number:"<<endl;
    cin>>c;

    if(a>b && a>c){
        cout<<a<<" is greater than "<<b<<" and "<<c<<endl;
    }
    else if(b>a && b>c){
        cout<<b<<" is greater than "<<a<<" and "<<c<<endl;
    }
    else{
        cout<<c<<" is greater than "<<a<<" and "<<b<<endl;
    }

}
