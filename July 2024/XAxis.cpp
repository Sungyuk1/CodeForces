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
    int x1, x2, x3; cin>>x1>>x2>>x3; 

    int min_dist = INT_MAX;
    for(int i = 1; i<=10; ++i){
        min_dist = min(min_dist, abs(i-x1) + abs(i-x2) + abs(i-x3));
    }

    //cout<<"ans : "<<min_dist<<endl; 
    cout<<min_dist<<endl; 

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}