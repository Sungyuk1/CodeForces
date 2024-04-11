#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool dfs(unordered_set<int>& visited, int current_n, int& m){
    if(current_n == m){
        return true;
    }
    
    if(m > current_n || current_n%3 != 0){
        return false;
    }

    int unit = current_n/3;
    bool output = false;

    if(!visited.contains(2*unit)){
        output = output | dfs(visited, 2*unit, m);
    }
    if(!visited.contains(unit)){
        output = output | dfs(visited, unit, m);
    }

    return output; 
}

int main(){
    int t; cin>>t;

    while(t--){
        int n, m; cin>>n>>m;

        unordered_set<int> visited;
        bool output = dfs(visited, n, m);
        
        if(output){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }


    }

}