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
    int n, m, k; cin>>n>>m>>k; 
    
    //Biggest m numbers first in desending order
    //This makes sure that the biggest values are included for all fs the most times
    //And ensure that the most g results have as many 0s as possible; 
    for(int i = n; i>m; --i){
        cout<<i<<" ";
    }

    //Then print in increasing order from 1 to make the most gs have the smallest numbers
    //the most often
    for(int i = 1; i<=m; ++i){
        cout<<i<<" ";
    }cout<<endl; 

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}