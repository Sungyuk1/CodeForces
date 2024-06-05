#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

void solve(){
    int n; cin>>n; 

    int ans = 1e9;
    for(int ones = 0; ones <= 2; ones++){
        for(int threes = 0; threes <= 1; threes++){
            for(int sixes = 0; sixes <= 4; sixes++){
                for(int tens = 0; tens <= 2; tens++){
                    int brute_sum = 1*ones + 3*threes + 6*sixes + 10*tens;
                    if(brute_sum <= n && (n-brute_sum)%15 == 0){
                        ans = min(ans, ones + threes + sixes + tens + (n-brute_sum)/15);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}