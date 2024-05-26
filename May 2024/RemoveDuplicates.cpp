#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

int main(){
    int n; cin>>n; 
    vector<int>a(n);
    for(int i = 0; i<n; ++i){
        cin>>a[i];
    }

    unordered_set<int>visited;
    vector<int>ans; 
    for(int i = n-1; i>=0; --i){
        if(!visited.contains(a[i])){
            ans.push_back(a[i]);
            visited.insert(a[i]);
        }
    }
    cout<<ans.size()<<endl; 
    for(int i = ans.size()-1; i>=0; --i){
        cout<<ans[i]<<" "; 
    }cout<<endl;

}