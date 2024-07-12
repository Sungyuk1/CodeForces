#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

void solve(){
    vector<int>nums(3);
    cin>>nums[0]; 
    cin>>nums[1];
    cin>>nums[2];

    for(int i = 0; i<5; ++i){
        sort(nums.begin(), nums.end());
        nums[0]++;
    }
    long long ans = nums[0] * nums[1] * nums[2];
    cout<<ans<<endl; 

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}