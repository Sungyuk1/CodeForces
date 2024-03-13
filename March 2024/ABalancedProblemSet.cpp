#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int x, n;
        cin>>x>>n;
        int ans = 1;

        //1) find all the divisors of x
        for(int i = 1; i*i <= x; ++i){
            if(x%i == 0){
                
                if(n<=x/i){
                    ans = max(ans, i);
                }
                if(n<=i){
                    ans = max(ans, x/i);
                }
            }
        }
        cout<<ans<<endl;

    }

}