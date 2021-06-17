#include<bits/stdc++.h>
#include <iostream>
using namespace std;

template <typename T>
class Queue {
    T* data;
    int frontIndex;
    int rearIndex;
    int capacity;
    public:
    Queue(){
        data = new T[5];
        frontIndex = 0;
        rearIndex = 0;
        capacity = 5;
    }

    int size(){
        return rearIndex - frontIndex;
    }

    bool isEmpty(){
        return rearIndex - frontIndex == 0;
    }

    void push(T elem){
        if(rearIndex - frontIndex + 1 == capacity){
            T* newData = new T[2*capacity];
            for(int i=0; i<capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[rearIndex%capacity] = elem;
        ++rearIndex;
    }

    T pop(){
        if(isEmpty()){
            cout<<"argon dead ..(doge"<<'\n';
            return 0;
        }
        return data[(frontIndex++)%capacity];
    }

    T front(){
        return data[frontIndex];
    }

    T rear(){
        return data[rearIndex - 1];
    }
};

int main(){
    Queue<char> q;
    q.push('a');
    q.push('r');
    q.push('g');
    q.push('o');
    q.push('n');
    cout<<"Queue size: "<<q.size()<<'\n';
    cout<<"Front Element in Queue: "<<q.front()<<'\n';
    cout<<"Rear Element in Queue: "<<q.rear()<<'\n';
    cout<<"Popped element from Queue: "<<q.pop()<<'\n';
    cout<<"Popped element from Queue: "<<q.pop()<<'\n';
    cout<<"Popped element from Queue: "<<q.pop()<<'\n';
    cout<<"Popped element from Queue: "<<q.pop()<<'\n';
    cout<<"Popped element from Queue: "<<q.pop()<<'\n';
    cout<<"Popped element from Queue: "<<q.pop()<<'\n';
    cout<<"Queue size now: "<<q.size()<<'\n';

}