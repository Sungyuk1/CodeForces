#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int k, n; cin>>k>>n; 
        vector<int> output;
        int diff = 1; 
        int elems_needed = k; 
        while(n-diff>=elems_needed-1 && output.size() < k){
            output.push_back(n);
            n-=diff; 
            diff++;
            elems_needed--;
        }

        while(n && elems_needed>0){
            output.push_back(n);
            n--;
            elems_needed--;
        }
        reverse(output.begin(), output.end());
        //cout<<"ans : ";
        for(auto num: output){
            cout<<num<<" ";
        }cout<<endl; 

    }

}