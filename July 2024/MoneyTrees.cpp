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
    int n, k; cin>>n>>k; 

    vector<int>fruits(n); 
    vector<int>heights(n); 
    for(int i = 0; i<n; ++i){
        cin>>fruits[i];
    }
    for(int i = 0; i<n; ++i){
        cin>>heights[i];
    }

    int max_len = 0; 

    int right_pointer = n-1; 
    int current_sum = fruits.back(); 
    if(current_sum <= k){
        max_len = 1; 
    }

    for(int left_pointer = n-2; left_pointer>=0; --left_pointer){
        if(heights[left_pointer] % heights[left_pointer+1] != 0){
            //start new window if h[i] is not divisble by h[i+1]
            current_sum = fruits[left_pointer];
            right_pointer = left_pointer;
        }else{
            current_sum+=fruits[left_pointer];
        }
        while(current_sum > k){
            //make the window smaller while we have too many fruits in the window
            current_sum-=fruits[right_pointer];
            right_pointer--;
        }

        max_len = max(max_len, right_pointer-left_pointer+1);
    }
    cout<<max_len<<endl; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}