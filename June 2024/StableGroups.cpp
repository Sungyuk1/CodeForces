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

void solve(){
    long long n, k, x; cin>>n>>k>>x;
    vector<long long>students(n); 
    for(long long i = 0; i<n; ++i){
        cin>>students[i];
    }
    sort(students.begin(), students.end());

    vector<pair<long long, long long>>intervals; 

    pair<long long, long long> current_interval;
    current_interval.first = students[0];
    current_interval.second = students[0];

    for(long long i = 1; i<students.size(); ++i){
        if(current_interval.second + x < students[i]){
            //new group
            intervals.push_back({current_interval.first, current_interval.second});
            current_interval.first = students[i];
            current_interval.second = students[i];
        }else{
            current_interval.second = students[i];
        }
    }
    intervals.push_back(current_interval);

    long long stable_groups = intervals.size();

    vector<long long>gap_costs; 
    for(long long i = 0; i<stable_groups-1; ++i){
        long long cost = (intervals[i+1].first - intervals[i].second)/x;
        if((intervals[i+1].first - intervals[i].second)%x == 0){
            cost--;
        }
        gap_costs.push_back(cost);
    }
    sort(gap_costs.rbegin(), gap_costs.rend());

    while(k>0){
        if(gap_costs.empty()){
            cout<<1<<endl; 
            return;
        }

        long long cheapest_gap = gap_costs.back(); gap_costs.pop_back();
        if(k<cheapest_gap){
            cout<<stable_groups<<endl; 
            return; 
        }else{
            //merge group
            stable_groups--;
            k-=cheapest_gap;
        }
    }

    cout<<stable_groups<<endl; 
    return; 
}

int main(){
    solve();
}