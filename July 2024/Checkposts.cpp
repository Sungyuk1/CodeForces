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

//Global Variable for the next unused id value that we can assign a node
int id;

//A vector which indicates if a node has been visited yet in the current iteration of dfs
vector<bool>visited;

//We assign ids to nodes using this vector. Also keeps track of if a node has never been visited before in
//any dfs iteration since the id will be unassigned.
vector<int>ids;

//The lowest id of a node in a nodes strongly connected component
//All nodes in the same strongly connected component will have the same
//value in low
vector<int>low;

//Stack we use for dfs
vector<int>stack;

//Map where each key is a strongly connected component (represented by the lowest id value) and
//value is a pair representing the lowest cost to build a checkpoint in all of the nodes 
//in the strongly connected component as well as the number of nodes in the strongly
//connected component with the same cost to build as the lowest cost to build
map<int, pair<long long, long long>>scc_to_min_build_cost_and_count; 

void dfs(int at, vector<vector<int>>&adj_dict){
    //Assign the id and low link of the current node to id
    //Then increment id. Also add the node to the visited set
    //and push the node onto the stack
    ids[at] = id;
    low[at] = id; 
    id++;
    stack.push_back(at);
    visited[at] = true; 

    //Iterate through all the neighbors of the current node, if that neighbor has not been assigned an
    //id yet, recursively call dfs on that neighbor node. If we have visited that neighbor, set the low link
    //value of the current node to the min of the current node's low link value and the neighbors low link value 
    for(auto nei: adj_dict[at]){
        if(ids[nei] == -1){
            dfs(nei, adj_dict);
        }
        if(visited[nei]){
            low[at] = min(low[at], low[nei]);
        }
    }

    //After iterating though all the neighbors, if the id of the current node
    //is still equal to the low link of the current node, then this node is the root of 
    //a strongly connected component. This means that this node has the lowest id of all the
    //nodes in the strongly connected component. 
    if(ids[at] == low[at]){
        //Pop from the stack until we reach the current node
        while(!stack.empty()){
            int node = stack.back();
            stack.pop_back();
            visited[node] = false; 
            //set the low link value of the node at the top of the stack to the current node's it.
            low[node] = low[at];
            if(node == at){
                break; 
            }
        }
    }
}
void solve(){
    int n; cin>>n; 
    vector<int>build_cost(n);
    for(int i = 0; i<n; ++i){
        cin>>build_cost[i];
    }

    visited = vector(n, false);
    ids=vector(n, -1);
    low = vector(n, INT_MAX);
    stack.clear();
    id = 0; 
    scc_to_min_build_cost_and_count.clear();
    
    int m; cin>>m; 
    vector<vector<int>>adj_dict(n, vector<int>());
    for(int i = 0; i<m; ++i){
        int u, v; cin>>u>>v;
        adj_dict[u-1].push_back(v-1);
    }

    //We will run Tarjan's algoritm to find strongly connected components

    //Iterate through all the nodes. If a node has not been assigned an id yet, it has never been visited before
    //in any dfs iteration, so dfs from this node. 
    for(int i = 0; i<n; ++i){
        if(ids[i] == -1){
            dfs(i, adj_dict);
        }
    }

    //In this implementation of Tarjan's algorithm, two nodes are in the same strongly 
    //connected component if they have the same value in the low array (aka same lowest link).

    //Iterate through all the strongly connected components, and find the node with the
    //lowest cost to build a checkpoint in the strongly connected component. 
    //Also count the number of nodes in the strongly connected component with the 
    //lowest cost to build
    for(int j = 0; j<n; ++j){
        if(!scc_to_min_build_cost_and_count.contains(low[j])){
            scc_to_min_build_cost_and_count[low[j]] = {build_cost[j], 1};
        }else if(build_cost[j] < scc_to_min_build_cost_and_count[low[j]].first){
            scc_to_min_build_cost_and_count[low[j]] = {build_cost[j], 1};
        }else if(build_cost[j] == scc_to_min_build_cost_and_count[low[j]].first){
            scc_to_min_build_cost_and_count[low[j]].second++;
        }
        
    }

    //Add up all the lowest costs to build for each strongly connected component
    //to get the minimum cost to ensure security for all the junctions
    //Also calculate the number of ways to ensure security for all the junctions at the 
    //minimum cost. This is the number of elements with the minimum cost to build in each strongly 
    //connected component multiplied. 
    long long min_cost = 0; 
    long long number_of_ways = 1; 
    for(auto p: scc_to_min_build_cost_and_count){
        min_cost+=p.second.first; 
        number_of_ways*=p.second.second;
        number_of_ways = number_of_ways%1000000007; 
    }
    cout<<min_cost<<" "<<number_of_ways<<endl; 
}

int main(){
    solve();
}