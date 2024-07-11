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

vector<vector<bool>> visited;
vector<vector<int>> tin, low;
int timer;
vector<pair<int, int>>articulation_vertices; 
int n, m;
int node_count; 

void dfs(int i, int j, vector<vector<char>>&graph, int parent_i = -1, int parent_j = -1){
    visited[i][j] = true; 
    tin[i][j] = low[i][j] = timer++; 
    int children = 0; 
    
    //check 4 neighbors
    if(i > 0 && graph[i-1][j] == '#'){
        if(!(i-1 == parent_i && j == parent_j)){
            if(visited[i-1][j]){
                low[i][j] = min(low[i][j], tin[i-1][j]);
            }else{
                dfs(i-1, j, graph, i, j);
                low[i][j] = min(low[i][j], low[i-1][j]);
                if(low[i-1][j] >= tin[i][j] && parent_i != -1 && parent_j != -1){
                    articulation_vertices.push_back({i, j});
                }
                children++;
            }
        }
    }
    if(i < n-1 && graph[i+1][j] == '#'){
        if(!(i+1 == parent_i && j == parent_j)){
            if(visited[i+1][j]){
                low[i][j] = min(low[i][j], tin[i+1][j]);
            }else{
                dfs(i+1, j, graph, i, j);
                low[i][j] = min(low[i][j], low[i+1][j]);
                if(low[i+1][j] >= tin[i][j] && parent_i != -1 && parent_j != -1){
                    articulation_vertices.push_back({i, j});
                }
                children++;
            }
        }
    }
    if(j > 0 && graph[i][j-1] == '#'){
        if(!(i == parent_i && j-1 == parent_j)){
            if(visited[i][j-1]){
                low[i][j] = min(low[i][j], tin[i][j-1]);
            }else{
                dfs(i, j-1, graph, i, j);
                low[i][j] = min(low[i][j], low[i][j-1]);
                if(low[i][j-1] >= tin[i][j] && parent_i != -1 && parent_j != -1){
                    articulation_vertices.push_back({i, j});
                }
                children++;
            }
        }
    }
    if(j <m-1 && graph[i][j+1] == '#'){
        if(!(i == parent_i && j+1 == parent_j)){
            if(visited[i][j+1]){
                low[i][j] = min(low[i][j], tin[i][j+1]);
            }else{
                dfs(i, j+1, graph, i, j);
                low[i][j] = min(low[i][j], low[i][j+1]);
                if(low[i][j+1] >= tin[i][j] && parent_i != -1 && parent_j != -1){
                    articulation_vertices.push_back({i, j});
                }
                children++;
            }
        } 
    }
    if(parent_i == -1 && parent_j == -1 && children>1){
        articulation_vertices.push_back({i, j});
    }
}

void solve(){
    node_count = 0; 
    cin>>n>>m; 
    vector<vector<char>>graph(n, vector<char>()); 
    for(int i = 0; i<n; ++i){
        string row; cin>>row; 
        for(auto c: row){
            graph[i].push_back(c);
            if(c=='#'){
                node_count++;
            }
        }
    }

    //There is no way to break a connected component into 2 components if it has less than 3 node
    if(node_count <3){
        cout<<-1<<endl; 
        return; 
    }

    timer = 0;
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    tin = vector<vector<int>>(n, vector<int>(m, -1));
    low = vector<vector<int>>(n, vector<int>(m, -1));
    articulation_vertices.clear();

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            if(graph[i][j] == '#' && visited[i][j] == false){
                dfs(i, j, graph);
            }
        }
    }

    if(articulation_vertices.size() > 0){
        cout<<1<<endl; 
    }else{
        cout<<2<<endl; 
    }

}

int main(){
    solve();    
}