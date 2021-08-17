#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        long tmp = 0;
        char sign = '+';
        for(unsigned int i=0; i<n; ++i){
            if(isDig(s[i])) tmp = tmp*10 + s[i] - '0';
            if(!isDig(s[i]) && !isSpace(s[i]) || i==n-1){
                if(sign=='+') st.push(tmp);
                else if(sign=='-') st.push(-tmp);
                else{
                    int res;
                    if(sign=='*') res = st.top()*tmp;
                    else res = st.top()/tmp;
                    st.pop();
                    st.push(res);
                }
                sign = s[i];
                tmp = 0;
            }
        }
        int ans = 0;
        while(st.size()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
private:
    bool isDig(char c){
        return (c>='0' && c<='9');
    }
    bool isSpace(char c){
        return c==' ';
    }
};