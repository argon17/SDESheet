#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

vector<int> topView(Node *root)
{
    //Your code here
    vector<int> ans;
    if(!root) return ans;
    map<int, int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(q.size()){
        Node* cur = q.front().first;
        int h = q.front().second;
        q.pop();
        if(!mpp[h]) mpp[h] = cur->data;
        if(cur->left) q.push({cur->left, h-1});
        if(cur->right) q.push({cur->right, h+1});
    }
    for(auto x : mpp){
        ans.push_back(x.second);
    }
    return ans;
}