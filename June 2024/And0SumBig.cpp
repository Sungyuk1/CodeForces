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
const int MOD=1e9+7;

void solve(){
    int n, k; cin>>n>>k;
    long long ans=1;

    //Actually do the multiplication so we can get the answer with the mod
    for(int i=0;i<k;i++) ans=(ans*n)%MOD;

    cout<<ans<<endl; 

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}