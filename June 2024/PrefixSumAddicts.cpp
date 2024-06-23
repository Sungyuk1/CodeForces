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
    vector<long long>endPS(k);
    for(int i = 0; i<k; ++i){
        cin>>endPS[i];
    }

    //Base Case : if k ==1, we can have the array be all 0s and then just the single value from 
    //the prefix sum at the end
    if(k == 1){
        cout<<"YES"<<endl; 
        return;
    }

    //We can calculate the last k-1 values of the array be doing prefixSum[i] - prefixSum[i-1]
    vector<long long>a;
    for(int i = k-1; i>0; --i){
        a.push_back(endPS[i] - endPS[i-1]);
    }

    //Check if the last k elements in the array provided by the prefixSum is sorted. If not 
    //return false
   for(int i = 0; i<a.size()-1; ++i){
        if(a[i] < a[i+1]){
            cout<<"NO"<<endl;
            return;
        }
    }

    //If the last element that we can obtain from the prefixSums multiplied by the remaining
    //indicies in the array is less than the last prefixSum, return false
    //This is because there is no way to split the last prefixSum value between the remaining slots
    //in the array to make every element less than the element n-k+1 in the array, 
    int diff = n - k; 
    if(a.back()*(diff+1) < endPS[0]){
        cout<<"NO"<<endl;
        return;
    }else{
        cout<<"YES"<<endl;
        return; 
    }

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}