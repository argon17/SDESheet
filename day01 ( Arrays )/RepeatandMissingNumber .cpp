#include<bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
   int n=A.size();
   int xo=0;
   for(int i=0;i<n;i++){
       xo=xo^A[i];
       xo=xo^(i+1);
   }
   int setbit=xo&(~(xo-1));
   int x=0,y=0;
   for(int i=0;i<n;i++){
       if(A[i]&setbit)
        x=x^A[i];
       else
        y=y^A[i];
       if((i+1)&setbit)
        x=x^(i+1);
     else y=y^(i+1);
   }
   vector<int> res(2);
   for(int i=0;i,n;i++){
       if(A[i]==x){
           res[0]=x;
           res[1]=y;
           break;
       }
       else if(A[i]==y){
            res[0]=y;
            res[1]=x;
            break;
       }
   }
   return res;
}
