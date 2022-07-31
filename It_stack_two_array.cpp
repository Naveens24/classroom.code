#include<iostream>
#include<stdlib.h>

using namespace std;

class twoStacks{
    int* arr;
    int size;
    int top1, top2;

    //constructor
    public:
    twoStacks(int n){
        size = n;
        arr = new int[n];
        top1 = n/2+1;
        top2 = n/2;
    }

    void push1(int x){
        if(top1 > 0){
            top1--;
            arr[top1] = x;
        }
        else{
            cout<<"Stack Overflow"<<"By element: "<<x<<endl;
            return;
        }
    }

        void push2(int x)
        {
            if(top2 < size-1){
                top2++;
                arr[top2]=x;
            }
            else{
                cout<<"Stack Overflow"<<"By element : "<<x<<endl;
                return;
            }
        }

        int pop1(){
            if(top1 <= size/2){
               int x = arr[top1];
               top1++;
               return x;
            }
            else {
                cout<<"Stack UnderFlow";
                exit(1);
            }
        }

        int pop2(){
            if(top2 >= size/2+1){
                int x = arr[top2];
                top2--;
                return x;
            }
            else{
                cout <<"Stack Underflow";
                exit(1);
            }
        }
        

};

int main(){
    twoStacks st(5);
    st.push1(5);
    st.push1(4);
    st.push1(10);
    st.push2(21);
    st.push2(12);
    cout<<"Popped element from stack1 is :"<<st.pop1()<<endl;
    st.push2(32);
    cout<<"\n Popped element from stack2 is: "<<st.pop2()<<endl;
    return 0;
            
}
