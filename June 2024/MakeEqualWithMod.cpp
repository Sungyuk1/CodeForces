#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cmath>

using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i<n; ++i){ cin>>a[i];}

    sort(a.begin(), a.end());

    bool has_one = false; 
    bool has_consec = false; 
    for(int i = 0; i<n; ++i){
        if(a[i] == 1){
            has_one = true; 
        }
        if(i<n-1 && a[i]+1 == a[i+1]){
            has_consec = true; 
        }
    }
    cout<< ((has_one & has_consec) ? "NO" : "YES")<<endl; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}