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
    long long n; cin>>n; 
    vector<long long >ans; 

    //edge case where only 1 bit set
    long long temp = n; 
    int set_bit_count = 0; 
    while(temp){
        if(temp&1){
            set_bit_count++;
        }
        temp>>=1;
    }
    if(set_bit_count == 1){
        cout<<1<<endl; 
        cout<<n<<endl; 
        return;
    }
    
    //going to an arbitrary number that is guaranteed to be bigger than the number 
    //of bits in n given the bounds
    ans.push_back(n); //n will always be included in the longest possible sequence
    for(int i = 0; i<62; ++i){
        //check if the ith bit is set
        long long x = 1LL<<i; //Note need to do 1LL<<i instead of 1<<i. Causes overflow if you don't

        if((x&n) == x && x!= n){
            //add the number with the ith bit in n unset
            ans.push_back(n-x);
        }

    }
    cout<<set_bit_count+1<<endl; 
    for(int i = set_bit_count; i>=0; --i){
        cout<<ans[i]<<" ";
    }cout<<endl; 

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}