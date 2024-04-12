#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        long long n, k, q; cin>>n>>k>>q;
        long long ans = 0; 
        long long len = 0; 

        for(int i = 0; i<n; ++i){
            long long temp; cin>>temp;
            if(temp <= q){
                len += 1;
            }else{
                if(len >= k){
                    ans += (len - k + 1) * (len - k + 2) / 2;
                }
                len = 0;
            }
        }
        if(len >= k){
            ans += (len - k + 1) * (len - k + 2) / 2;
        }
        cout<<ans<<endl;


        }
    }