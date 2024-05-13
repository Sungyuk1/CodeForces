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
        int n, q; cin>>n>>q;

        vector<long long>prefixSums(n+1, 0);
        for(int i = 1; i<=n; ++i){
            cin>>prefixSums[i];
            prefixSums[i]+=prefixSums[i-1];
        }
        
        /*cout<<"prefixSums : ";
        for(auto num: prefixSums){
            cout<<num<<" ";
        }cout<<endl; */

        for(int i = 0; i<q; ++i){
            int L, R, K; cin>>L>>R>>K;
            L--;
            R--;
            long long new_total = prefixSums[L] + (prefixSums.back() - prefixSums[R+1]) + (K*(R-L+1));
            //cout<<"prefix from left of "<<L<<" : "<<prefixSums[L]<<endl; 
            //cout<<"total from right of "<<R<<" : "<<(prefixSums.back() - prefixSums[R+1])<<endl; 
            //cout<<"Result from replacement : "<<(K*(R-L+1))<<endl; 
            if(new_total & 1){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl; 
            }
        }


    }

}