class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here    
        return n && !(n & (n-1));
        
    }
};