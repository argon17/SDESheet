#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> sm, sa;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sm.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    // idea : reverse the stack, pop then again reverse ;)
    int pop() {
        while(sm.size()){
            sa.push(sm.top());
            sm.pop();
        }
        int x = sa.top();
        sa.pop();
        while(sa.size()){
            sm.push(sa.top());
            sa.pop();
        }
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        while(sm.size()){
            sa.push(sm.top());
            sm.pop();
        }
        int x = sa.top();
        while(sa.size()){
            sm.push(sa.top());
            sa.pop();
        }
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return sm.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */