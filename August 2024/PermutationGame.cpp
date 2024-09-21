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

vector<int>permutation; 
vector<int>values; 
int n, duration, start_bodya, start_sasha;

//Will dfs through the cycle and at each iteration calculate the score of
//just staying at that index. This is 
//score_getting_to_this_index + (value_of_index * remaining_time)
long long dfs(int start_index){
    vector<int>visited(n, -1);
    long long max_score = 0; 
    long long move_score = 0; //The score from hopping to get to this index
    long long remaining_time = duration; 
    int current_index = start_index; //renamed for readability

    while(visited[current_index] == -1 && remaining_time>0){
        long long score_stay_here = move_score + (remaining_time * values[current_index]);
        max_score = max(max_score, score_stay_here);

        //edit variables for next iteration
        move_score+=values[current_index];
        visited[current_index] = 1;
        current_index=permutation[current_index];
        remaining_time--;
    } 
    return max_score;
}

void solve(){
    cin>>n>>duration>>start_bodya>>start_sasha;

    //subtraction to make 1-indexed input into 0-indexed
    start_bodya--; 
    start_sasha--;

    permutation.clear();
    values.clear();

    for(int i = 0; i<n; ++i){
        int temp; cin>>temp; 
        permutation.push_back(temp-1);
    }
    for(int i = 0; i<n; ++i){
        int temp; cin>>temp; 
        values.push_back(temp);
    }

    long long best_score_sasha = dfs(start_sasha);
    long long best_score_bodya = dfs(start_bodya);

    if(best_score_sasha > best_score_bodya){
        cout<<"Sasha"<<endl; 
    }else if(best_score_bodya > best_score_sasha){
        cout<<"Bodya"<<endl; 
    }else{
        cout<<"Draw"<<endl; 
    }
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}