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
#include <cstring>

using namespace std;

//Since each question is worth the same amount of points, and penalty occurs with amount of time passed
//it is optimal to just solve the quicker problems first
void solve(){
    int n, m, h; cin>>n>>m>>h; 
    vector<long long>times(m);

    vector<vector<long long>>scores; //points, penatly, index

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            cin>>times[j];
        }

        sort(times.begin(), times.end()); 
        long long total_solved = 0; 
        long long total_penalty = 0;
        long long current_time = 0;  
        while(total_solved < m && current_time + times[total_solved] <= h ){
            total_penalty+=current_time + times[total_solved];
            current_time+=times[total_solved];
            total_solved++;
        }
        scores.push_back({-total_solved, total_penalty, i+1}); //edge case same total solved and total penatly
    }

    sort(scores.begin(), scores.end());
    for(int i = 0; i<n; ++i){
        if(scores[i][2] == 1){
            cout<<i+1<<endl; 
            return; 
        }
    }
    return; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}