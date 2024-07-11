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
    string S; cin>>S; 
    string T; cin>>T; 

    //Base case when the strings are already equal
    if(S == T){
        cout<<0<<endl; 
        return; 
    }

    int cnt_S_T_diff = 0; 
    for(int i = 0; i<n; ++i){
        if(S[i] != T[i]){
            cnt_S_T_diff++;
        }
    }
    long long ans_even = (2*cnt_S_T_diff) - (cnt_S_T_diff%2);

    
    reverse(T.begin(), T.end());
    int cnt_S_REVT_diff = 0; 
    for(int i = 0; i<n; ++i){
        if(S[i] != T[i]){
            cnt_S_REVT_diff++;
        }
    }

    //Base case when the reverse of T is equal to S. 
    //In this case Alice does not make a move (aka replace
    //letter with identical letter), and then waits for 
    //Bob to reverse a string. Afterwards the two strngs will
    //be the same. 
    if(cnt_S_REVT_diff == 0){
        cout<<2<<endl; 
        return; 
    }
    long long ans_odd = (2*cnt_S_REVT_diff) - (1-(cnt_S_REVT_diff%2));

    cout<<min(ans_even, ans_odd)<<endl; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}