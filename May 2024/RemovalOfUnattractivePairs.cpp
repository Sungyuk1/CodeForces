#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

void solve(){
    long long n; cin>>n;
    string s; cin>>s;

    vector<long long> counter(26, 0);
    long long max_count = 0; 

    for(auto c: s){
        counter[c-'a']++;
        max_count = max(max_count, counter[c-'a']);
    }

    //Either the string is of an odd length and we have 1 character left, 
    //or the frequency of the most common character appears more than n/2 times
    //in which case we will have a final string left of only that character. 
    long long res = max(n%2, (2*max_count) - n);
    cout<<res<<endl; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}