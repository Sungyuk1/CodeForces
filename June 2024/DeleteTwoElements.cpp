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
    long n; cin>>n; 
    vector<long>a(n);
    long double total = 0; 
    for(int i = 0; i<n; ++i){
        cin>>a[i];
        total+=a[i];
    }

    long double mean = (long double)total / (long double)n; 
    long double target = mean *2; 

    long long count = 0; 
    unordered_map<long double , int> counter; 
    for(int i = 0; i<n; ++i){
        long double find = target - a[i];
        if(counter.contains(find)){
            count+=counter[find];
        }
        counter[a[i]]++;
    }
    cout<<count<<endl; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}