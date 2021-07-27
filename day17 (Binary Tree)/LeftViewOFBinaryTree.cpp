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

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   if(!root) return ans;
   queue<Node*> q;
   q.push(root);
   while(q.size()){
       int sz = q.size();
       ans.push_back(q.front()->data);
       while(sz--){
           Node* cur = q.front();
           q.pop();
           if(cur->left) q.push(cur->left);
           if(cur->right) q.push(cur->right);
       }
   }
   return ans;
}