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
    map<int, int>counter; 
    for(int i = 0; i<n; ++i){
        int temp; cin>>temp; 
        counter[temp]++;
    }

    vector<long long>frogs(n+1, 0);
    for(auto &p : counter){
        for(int i = p.first; i<n+1; i+=p.first){
            frogs[i]+=p.second;
        }
    }
    cout<<*max_element(frogs.begin(), frogs.end())<<endl; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}