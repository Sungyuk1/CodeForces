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

int n, m; 

void edit(int i, int j, vector<vector<int>>&matrix){
    int greatest_nei = -1;
    bool is_larger_than_all_nei = true; 
    if(i > 0){
        if(matrix[i-1][j] > matrix[i][j]){
            is_larger_than_all_nei = false; 
        }
        greatest_nei = max(greatest_nei, matrix[i-1][j]);
    }
    if(i < n-1){
        if(matrix[i+1][j] > matrix[i][j]){
            is_larger_than_all_nei = false; 
        }
        greatest_nei = max(greatest_nei, matrix[i+1][j]);
    }
    if(j > 0){
        if(matrix[i][j-1] > matrix[i][j]){
            is_larger_than_all_nei = false; 
        }
        greatest_nei = max(greatest_nei, matrix[i][j-1]);
    }
    if(j < m-1){
        if(matrix[i][j+1] > matrix[i][j]){
            is_larger_than_all_nei = false; 
        }
        greatest_nei = max(greatest_nei, matrix[i][j+1]);
    }

    if(is_larger_than_all_nei){
        //edit to be equal to greatest neigbor
        matrix[i][j] = greatest_nei;
    }

}
void solve(){
    cin>>n>>m; 
    vector<vector<int>>matrix(n, vector<int>(m, 0)); 
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            cin>>matrix[i][j];
        }
    }

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            edit(i, j, matrix);
        }
    }

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            cout<<matrix[i][j]<<" "; 
        }cout<<endl; 
    }

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}