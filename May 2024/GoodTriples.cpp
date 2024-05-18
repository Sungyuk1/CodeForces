#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

//A triplet is considered good only if each digit of the number n
// was obtained without carrying over during addition.
void solve(){
    long long n; cin>>n; 
    long long cnt = 1;

    //1) The answer for each digit x will be the number of digit triplets with the sum x
    while(n>0){
        //2) compute the answer for each individual digit, and multiple it to our cnt
        int digit = n%10; 
        // (n+1)(n+2)/2  = # of digits that sum up to a digit n. 
        // Note since digit n in this equation is less than 10
        n = n/10; 

        cnt*=((digit+1)*(digit+2))/2;
    }
    cout<<cnt<<endl; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}