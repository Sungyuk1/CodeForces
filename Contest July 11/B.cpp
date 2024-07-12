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

void solve(){
    int n, k; cin>>n>>k; 
    long long max_elem = 0; 
    int max_elem_index = -1; 
    vector<int>nums(k);
    for(int i = 0; i<k; ++i){
        cin>>nums[i];
        if(max_elem < nums[i]){
            max_elem = nums[i];
            max_elem_index = i; 
        }
    }
    long long moves_count = 0; 

    //cost to turn every thing except the biggest elem into 1
    for(int i = 0; i<k; ++i){
        if(max_elem_index != i){
            moves_count+=nums[i]-1; 
        }
    }

    //cost to merge everything back; 
    for(int i = 0; i<k; ++i){
        if(max_elem_index != i){
            moves_count+=nums[i];
        }
    }

    cout<<moves_count<<endl; 


    //priority_queue <int, vector<int>, greater<int> > min_heap; 
    /*for(int i = 0; i<k; ++i){
        int temp; cin>>temp;
        min_heap.push(temp); 
    }*/

    /*int one_count = 0; 
    int rest_count = k; 
    int moves_count = 0; 

    while(!min_heap.empty() && min_heap.top() == 1){
        min_heap.pop();
        one_count++;
    }

    //cut while necessary
    while(one_count >= rest_count){
        if(min_heap.top() == 2){
            min_heap.pop();
            one_count+=2; 
        }else{
            int top = min_heap.top();
            min_heap.pop();
            top--;
            one_count++;
            min_heap.push(top);
        }
        moves_count++;
    }*/



    

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}