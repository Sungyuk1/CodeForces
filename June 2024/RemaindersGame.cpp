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
    int n, k; cin>>n>>k; 
    vector<int>numbers(n);
    for(int i = 0; i<n; ++i){
        cin>>numbers[i];
    }

    for(int i = 0; i<n; ++i){
        if(numbers[i] == k){
            cout<<"YES"<<endl; 
            return;
        }

        if(k%numbers[i] == 0){
            cout<<"YES"<<endl; 
        }
    }
    cout<<"NO"<<endl; 
}

int main(){
    solve();    
}