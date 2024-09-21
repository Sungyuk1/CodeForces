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
#include <iomanip>

using namespace std;

//looks like you need to figure out how much area is overlapping in situations where there is an overlap
//Bottom is wider than the top, so the higher triangle will always show. 
//Calculate area of the total triangle, then area of the triangle that is hidden (the top part) and then
//subtract. What about nested areas? Nah just need to worry about the one aboce. 
void solve(){
    long long n, base_len, height; cin>>n>>base_len>>height; 
    vector<int>starts(n); 
    for(int i = 0; i<n; ++i){
        cin>>starts[i];
        starts[i]+=height; 
    }

    long double base_per_height = (long double)base_len/(long double)height;
    //cout<<"base_per_height : "<<base_per_height<<endl; 
    long double total = 0; 
    long double triangle_area = (height*base_len)/(long double)2.0;  
    //cout<<"Triangle Area : "<<triangle_area<<endl; 

    //First branch will always show
    //note case of loss when result is odd
    total+=triangle_area;

    for(int i = n-2; i>=0; --i){
        if(starts[i] > starts[i+1]-height){
            //cout<<"Overlap detected between branches that start at "<<i+1<<" and starts at "<<i<<endl; 
            //case : overlap
            
            //figure out overlap height
            long overlap_y = starts[i] - (starts[i+1]-height);
            //cout<<"height that overlaps : "<<overlap_y<<endl; 
            long double new_base = overlap_y * base_per_height; 
            //cout<<"base at the end of the overlap : "<<new_base<<endl; 
            long double covered_portion = overlap_y * new_base * 0.5; 
            //cout<<"Area that is covered : "<<covered_portion<<endl; 
            //cout<<"Area that is shown : "<<triangle_area - covered_portion<<endl; 
            
            total+=triangle_area - covered_portion; 

        }else{
            //cout<<"No over lap for branch that starts at "<<starts[i]<<endl; 
            total+=triangle_area;
        }
    }

    cout<< std::fixed << std::setprecision(6)<<total<<endl; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}