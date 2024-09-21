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
#include <cstring>

using namespace std;

//candy is tied to all ropes at once. Cut alll ropes where rope is < height
void solve(){
    int n; cin>>n; 
    int total_cut = 0; 

    for(int i = 0; i<n; ++i){
        int height, rope_length; cin>>height>>rope_length;
        if(rope_length < height){
            total_cut++;
        }
    }
    cout<<total_cut<<endl; 
    return; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}