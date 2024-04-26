#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <math.h> 
#include <queue>
#include <set>

using namespace std;

//each index must differ between a and b
//sumnation of a and b must be equal

//Maybe make sure that we have at least n/2 unique numbers
int main(){
    int t; cin>>t;

    while(t--){
        long long n; cin>>n;
        set<long long> rights;
        vector<long long>lefts;
        //lefts.push_back(0);
        vector<long long>interval_lengths; 
        vector<long long>costs;

        for(int i = 0; i<n; ++i){
            long long temp; cin>>temp; 
            lefts.push_back(temp);

        } 
        for(int i = 0; i<n; ++i){
            long long temp; cin>>temp;
            rights.insert(temp);
        } 
        for(int i = 0; i<n; ++i){
            long long temp; cin>>temp;
            costs.push_back(temp);
        } 
        sort(lefts.begin(), lefts.end());

        for(int i = n-1; i>=0; --i){
            //find largest left that is still smaller than right
            auto it=rights.upper_bound(lefts[i]);
		    int interval =(*it)-lefts[i];
            rights.erase(it);
            interval_lengths.push_back(interval);
        }
        sort(interval_lengths.begin(), interval_lengths.end());
        sort(costs.rbegin(), costs.rend());

        long long min_cost = 0; 
        for(int i = 0; i<n; ++i){
            min_cost+=(interval_lengths[i] * costs[i]);
        }
        cout<<min_cost<<endl; 

    }

}