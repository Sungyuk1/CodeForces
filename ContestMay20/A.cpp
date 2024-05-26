#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

void solve(){
    long long one, four; cin>>one>>four; 

    long long screens_for_four = four/2; 
    //cout<<"screens for four : "<<screens_for_four<<endl;
    long long extra_spaces_after_fours = screens_for_four * 7;
    //cout<<"extra spaces after fours : "<<extra_spaces_after_fours<<endl; 

    if(four%2){
        screens_for_four++;
        extra_spaces_after_fours+=11;
    }
    //cout<<"screens for four : "<<screens_for_four<<endl;
    //cout<<"extra spaces after fours : "<<extra_spaces_after_fours<<endl; 

    long long ans = screens_for_four;
    if(extra_spaces_after_fours < one){
        one-=extra_spaces_after_fours;
        ans+=one/15;
        if(one%15){
            ans+=1;
        }
    }

    //cout<<"ans : "<<ans<<endl; 
    cout<<ans<<endl; 


}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}