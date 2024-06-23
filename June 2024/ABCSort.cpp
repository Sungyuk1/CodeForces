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
    int n; cin>>n;
    vector<int>a(n);
    for(int i = 0; i<n; ++i){ cin>>a[i]; }

    for(int i = n-1; i>=1; i-=2){
        if(a[i] < a[i-1]){
            int temp = a[i];
            a[i] = a[i-1];
            a[i-1] = temp; 
        }
    }
    
    if(is_sorted(a.begin(), a.end())){
        cout<<"YES"<<endl; 
    }else{
        cout<<"NO"<<endl; 
    }
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}