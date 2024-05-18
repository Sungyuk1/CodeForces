#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

void solve(){
    long long n; cin>>n;
    long long count = 0; 

    for(int i = 1; i<10; ++i){
        long long current_num = i; 
        while(current_num<=n){
            count++;
            current_num*=10;
            current_num+=i;
        }
    }
    cout<<count<<endl; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}