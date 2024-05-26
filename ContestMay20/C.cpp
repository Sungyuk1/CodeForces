#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;


/*void solve(){
    int n; cin>>n;
    vector<int>nums(n);
    for(int i = 0; i<n; ++i){
        cin>>nums[i];
    }

    long long ans = 0; 

    for(int i = 0; i<n-3;++i){
        for(int j = i+1; j<n-2; ++j){
            if(nums[i] == nums[j] && nums[i+1] == nums[j+1] && nums[i+2] != nums[j+2]){
                ans++;
            }else if(nums[i] == nums[j] && nums[i+1] != nums[j+1] && nums[i+2] == nums[j+2]){
                ans++;
            }else if(nums[i] != nums[j] && nums[i+1] == nums[j+1] && nums[i+2] == nums[j+2]){
                ans++;
            }
        }
    }
    cout<<ans<<endl; 
    //cout<<"ans : "<<ans<<endl; 

}*/

void solve(){
    int n; cin>>n;
    vector<int>nums(n);
    for(int i = 0; i<n; ++i){
        cin>>nums[i];
    }

    long long ans = 0; 

    map<int, map<int, map<int, int>>> first_two;
    map<int, map<int, map<int, int>>> ends;
    map<int, map<int, map<int, int>>> last_two;

    //add map to use binary search and speed up
    for(int i = 0; i<n-2;++i){
        first_two[nums[i]][nums[i+1]][nums[i+2]]++;
        ends[nums[i]][nums[i+2]][nums[i+1]]++;
        last_two[nums[i+1]][nums[i+2]][nums[i]]++;
    }

    for(auto &first: first_two){
        for(auto &second: first.second){
                long long bpairs = 0; 
                long long prev_elem = 0; 
                for(auto &it: second.second){
                    bpairs+=it.second*prev_elem;
                    prev_elem+=it.second; 
                }
                ans+=bpairs; 
        }
    }

    for(auto &first: ends){
        for(auto &second: first.second){
                long long bpairs = 0; 
                long long prev_elem = 0; 
                for(auto &it: second.second){
                    bpairs+=it.second*prev_elem;
                    prev_elem+=it.second; 
                }

                ans+=bpairs; 
        }
    }

    for(auto &first: last_two){
        for(auto &second: first.second){
                long long bpairs = 0; 
                long long prev_elem = 0; 
                for(auto &it: second.second){
                    bpairs+=it.second*prev_elem;
                    prev_elem+=it.second; 
                }

                ans+=bpairs; 
        }
    }
    cout<<ans<<endl; 
    //cout<<"ans : "<<ans<<endl; 

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}