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
    for(int i = 0; i<n; ++i){cin>>a[i];}

    //Note we cannot change the last two elements with provided operation
    if(a[n-2] > a[n-1]){
        cout<<-1<<endl; 
        return; 
    }

    if(a[n-1] < 0){
        if(is_sorted(a.begin(), a.end())){
            cout<<0<<endl; 
        }else{
            cout<<-1<<endl; 
        }
    }else{
        cout<<n-2<<endl; 
        for(int i = 1; i<=n-2; ++i){
            cout<<i<<' '<<n-1<<' '<<n<<endl;         
        }
    }
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}