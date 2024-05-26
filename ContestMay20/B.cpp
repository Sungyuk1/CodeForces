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
    int n; cin>>n; 
    string b; cin>>b;

    vector<int>visited(26, -1); 
    vector<char>r;

    for(auto c: b){
        if(visited[c-'a'] == -1){
            visited[c-'a'] = 1;
            r.push_back(c);
        }
    }

    sort(r.begin(), r.end());

    int left = 0, right = r.size()-1; 
    
    unordered_map<char, char> mapping;
    while(left <= right){
        mapping[r[left]] = r[right];
        mapping[r[right]] = r[left];
        left++;
        right--;
    }

    string original = "";
    for(auto c: b){
        original+=mapping[c];
    }

    //cout<<"ans : "<<original<<endl; 
    cout<<original<<endl; 

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}