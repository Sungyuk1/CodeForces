#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <math.h> 

using namespace std;

int main(){
    int t;cin>>t;

    while(t--){
        int num_traps; cin>>num_traps;
        long long ans = 2 * pow(10,9);

        for(int i = 0; i<num_traps; ++i){
            long long d_i, s_i; cin>>d_i>>s_i;
            ans = min(ans, d_i + (s_i-1)/2);
        }

        cout<<ans<<endl;;

    }

}