#include<bits/stdc++.h>
#include <iostream>
using namespace std;

template <typename T>
class Stack {
    T* data;
    int nextIndex;
    int capacity;
    public:
    Stack(){
        data = new T[5];
        nextIndex = 0;
        capacity = 5;
    }

    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex == 0;
    }

    void push(T elem){
        if(nextIndex == capacity){
            T* newData = new T[2*capacity];
            for(int i=0; i<capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[nextIndex] = elem;
        ++nextIndex;
    }

    T pop(){
        if(isEmpty()){
            cout<<"argon dead ..(doge"<<'\n';
            return 0;
        }
        return data[--nextIndex];
    }

    T top(){
        return data[nextIndex - 1];
    }
};

int main(){
    Stack<char> st;
    st.push('a');
    st.push('r');
    st.push('g');
    st.push('o');
    st.push('n');
    cout<<"Stack size: "<<st.size()<<'\n';
    cout<<"Top Element in Stack: "<<st.top()<<'\n';
    cout<<"Popped element from stack: "<<st.pop()<<'\n';
    cout<<"Popped element from stack: "<<st.pop()<<'\n';
    cout<<"Popped element from stack: "<<st.pop()<<'\n';
    cout<<"Popped element from stack: "<<st.pop()<<'\n';
    cout<<"Popped element from stack: "<<st.pop()<<'\n';
    cout<<"Popped element from stack: "<<st.pop()<<'\n';
    cout<<"Stack size now: "<<st.size()<<'\n';

}