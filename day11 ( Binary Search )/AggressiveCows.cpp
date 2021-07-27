#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int cows, int minDist) {
    int cntCows = 1; 
    int lastPlacedCow = a[0];
    for(int i = 1;i<n;i++) {
        if(a[i] - lastPlacedCow >= minDist) {
            cntCows++;
            lastPlacedCow = a[i]; 
        }
    }
    if(cntCows >= cows) return true;
    return false; 
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, cows;
        cin >> n >> cows;
        int a[n];
        for(int i = 0;i<n;i++) cin >> a[i]; 
        sort(a,a+n); 
        
        int l = 0, r = a[n-1] - a[0], ans; 
        
        while(l <= r) {
            int mid = (l + r) >> 1; 
            
            if(isPossible(a,n,cows,mid)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1; 
            }
        }
        cout << ans << endl; 
    }
    return 0;
} 