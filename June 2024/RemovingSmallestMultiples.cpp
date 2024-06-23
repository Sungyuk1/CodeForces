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
    string T; cin>>T;

    //A set of all the numbers that needs to be removed from S
    unordered_set<int>needs_rem; 

    //A set of all the numbers that we need to keep in S
    unordered_set<int>keep; 

    for(int i = 0; i<n; ++i){
        if(T[i] == '0'){
            needs_rem.insert(i+1);
        }else{
            keep.insert(i+1);
        }
    }

    long long total_cost = 0; 
    
    //Iterate from 1-n like Sieve. Remove all multiples of the current number
    //until we encounter a multiple that belongs in the output. The cheapest cost to remove
    //a number will be the smallest number that is a factor.  
    for(int i = 1; i<=n; ++i){
        if(needs_rem.contains(i)){
            total_cost+=i;
            needs_rem.erase(i);
        }else if(keep.contains(i)){
            continue; 
        }

        //Sieve - remove all multiples of this number in S that needs removing until
        //we encounter a multiple that belongs in the output.
        for(int j = i+i; j<=n; j+=i){
            if(needs_rem.contains(j)){
                total_cost+=i; 
                needs_rem.erase(j);
            }else if(keep.contains(j)){
                //if the smallest multiple is in T, then we can no longer use i to remove 
                //the other multiples since a smaller multiple will always exist
                break; 
            }
        }
    }
    cout<<total_cost<<endl;
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}