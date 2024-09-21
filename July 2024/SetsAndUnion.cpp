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
    int n; cin>>n;  
    vector<set<int>>sets;
    set<int>total_set; 
    int max_elems = 0; 

    for(int i = 0; i<n; ++i){
        int k; cin>>k;
        set<int>temp_set; 
        for(int j = 0; j<k; ++j){
            int temp; cin>>temp; 
            temp_set.insert(temp);
            total_set.insert(temp);
        }
        sets.push_back(temp_set);
    }

    //Iterate through each element in the union of all the sets
    //For each element, union together all the sets that do not 
    //contain the current element. 
    for(auto num: total_set){
        set<int>current_set; 
        for(int j = 0; j<n; ++j){
            if(!sets[j].contains(num)){
                current_set.insert(sets[j].begin(), sets[j].end());
            }
        }
        max_elems = max(max_elems, (int)current_set.size());
    }
    cout<<max_elems<<endl; 
}


int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}