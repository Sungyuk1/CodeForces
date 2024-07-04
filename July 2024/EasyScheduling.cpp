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
    int h, p; cin>>h>>p; 

    int current_height = 1;
    long long number_of_nodes_at_level = 1; 
    long long current_time = 0; 

    while(current_time < h){
        if(number_of_nodes_at_level <= p){
            current_height++;
            number_of_nodes_at_level*=2;
            current_time++;
        }else{
            break; 
        }
    }

    long long num_already_processed = pow(2, current_height-1)-1;
    //cout<<"Number already processed : "<<num_already_processed<<endl; 

    long long need_to_process = pow(2, h)-1 - num_already_processed;
    //cout<<"Total Number of nodes : "<<pow(2, h)-1<<endl; 
    //cout<<"Nodes we still need to process : "<<need_to_process<<endl; 
    current_time+=need_to_process/p;
    if(need_to_process%p > 0){
        current_time++;
    }

    cout<<current_time<<endl; 



}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}