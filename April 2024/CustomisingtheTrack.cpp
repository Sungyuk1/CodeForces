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
        int n; cin>>n;
        long long total = 0;
        
        for(int i = 0; i<n; ++i){
            int temp; cin>>temp; 
            total+=temp;
        }

        long long k = total%n;
        long long ans = k*(n-k);
        cout<<ans<<endl;

    }

}