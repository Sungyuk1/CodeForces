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

//helper function which returns if a bit is set
bool isSet(long long x, long long bit) {return ((x >> bit) & 1LL) == 1LL;}

void solve(){
    long long n, m; cin>>n>>m; 
    long long left = max(0LL, n-m);
    long long right = n+m; 
    long long ans = 0; 
    long long val = 1;

    //Iterate through all the digits in our binary number answer
    for (int i = 0; i <= 32; ++i) {
		//if our range of ors is greater than the value of consecuitve results, one of the digits
        //is bound to be 1. Otherwise, if one of the edges of the consecutive results is a 1, the bit 
        //will also be a 1. 
        if(right - left >= val) ans+=val; 
        else if(isSet(left, i)) ans+=val;
        else if (isSet(right, i)) ans+=val; 

        val*=2; 
	}
    cout<<ans<<endl; 

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}