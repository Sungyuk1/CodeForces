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
    long long n, m, k; cin>>n>>m>>k; 

    long long min_edges = n-1;
    long long max_edges = (n*(n-1))/2; 

    if(min_edges> m || max_edges< m){
        cout<<"NO"<<endl; 
        return; 
    }

    //graph is 1 node. Need to check before complete graph check since
    //one node is technically a complete graph
    if(n==1){
        //diameter is 0
        if(k>1){
            cout<<"YES"<<endl; 
        }else{
            cout<<"NO"<<endl; 
        }
        return; 
    }

    //Complete graph
    if(m == max_edges){
        //diamter is 1
        if(k>2){
            cout<<"YES"<<endl; 
        }else{
            cout<<"NO"<<endl; 
        }
        return; 
    }

    //tree 
    if(k>3){
        cout<<"YES"<<endl; 
    }else{
        cout<<"NO"<<endl; 
    }
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}