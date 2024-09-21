#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

void solve(){
    long long n; cin >> n;
    //we optimise our starting spot
    // n c 2 = val
    // n * (n-1) / 2 = val
    // val * 2 = n * (n - 1)
    long long strt = sqrt(n * 2), ans;
    //i is the number of balls
    for (long long i=strt; i<1e17; i++) {
        if (i * (i-1) / 2 == n) { cout << i << endl; return; }
        if(i * (i-1) / 2 > n) {
            //if answer is bigger than n, then that means we hit our
            //upper bound. So we calculate the lower bound. Find the 
            //difference between the current number of balls and the 
            //lower bound, which is the number of balls we doubled up on
            ans = (i-1) * (i-2) / 2;
            long long temp = n - ans; //exact number of balls we need - lower bound. 
            //We add temp since each ball we doubled up on adds exactly 1 unique combinations {x, x}
            cout << i - 1 + temp << endl; return;
            break;
        }
    }
    cout << ans << endl;
    return;
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}