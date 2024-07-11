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
    int n, m; cin>>n>>m; 
    string s; cin>>s; 
    priority_queue <int, vector<int>, greater<int> > min_indicies_pq; 
    for(int i = 0; i<m; ++i){
        int index; cin>>index;
        min_indicies_pq.push(index-1);
    }

    string c; cin>>c; 
    priority_queue <char, vector<char>, greater<char> > min_chars_pq;
    for(auto elem : c){
        min_chars_pq.push(elem);
    }

    for(int i = 0; i<s.size(); ++i){
        while(!min_indicies_pq.empty() && i > min_indicies_pq.top()){
            min_indicies_pq.pop();
        }

        if(min_indicies_pq.empty()){
            //no more updates can be made
            break;
        }

        if(min_indicies_pq.top() > i){
            continue; 
        }

        s[i] = min_chars_pq.top();
        min_chars_pq.pop();
        min_indicies_pq.pop();
    }

    cout<<s<<endl; 


}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}