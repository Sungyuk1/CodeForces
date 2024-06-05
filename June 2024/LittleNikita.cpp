#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

void solve(){
    int n, m; cin>>n>>m;

    if(m > n){
        cout<<"No"<<endl;
    }else if(n%2 != m%2){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}