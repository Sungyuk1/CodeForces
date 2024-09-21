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
#include <cstring>

using namespace std;

//grows exponentially so easy to check? every turn its prev_total + k^(t-1);

//7 is the smallest valid n
set<long long> nums;

void solve(){
    int n; cin>>n; 
    if (nums.count(n)) cout << "YES" << endl;
    else{
        cout<<"NO"<<endl; 
    }
}

int main(){
    int t; cin>>t;

    //precalculation
    for (long long k = 2; k <= 1000; ++k) {
        long long val = 1 + k;
        long long p = k*k;
        for (int cnt = 2; cnt <= 20; ++cnt) {
            val += p;
            if (val > 1e6) break;
            nums.insert(val);            
            p *= k;
        }
    }

    while(t--){
        solve();
        
    }

}