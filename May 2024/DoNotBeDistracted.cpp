#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

void solve(){
    int n; cin>>n; 
    string s; cin>>s;

    vector<int>visited(26, 0);
    vector<char>stack; 

    for(auto c : s){
        if(stack.empty()){
            stack.push_back(c);
            visited[c-'A'] = 1;
        }else if(stack.back()!= c){
            if(visited[c-'A'] == 1){
                cout<<"NO"<<endl; 
                return;
            }else{
                stack.push_back(c);
                visited[c-'A'] = 1;
            }
        }
    }
    cout<<"YES"<<endl; 

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}