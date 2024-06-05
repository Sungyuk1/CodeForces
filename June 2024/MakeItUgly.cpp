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
    vector<int>a(n);
    for(int i = 0; i<n; ++i){
        cin>>a[i];
    }

    int last = -1; //last index of element equal to first and last elements
    int ans = n; 

    //remove the entire prefix of numbers equal to 𝑎1;
    //choose two numbers that are not equal to 𝑎1, and remove all the numbers between them, so that these two numbers become adjacent.
    for(int i = 1; i<n; ++i){
        if(a[i] != a[0]){
            ans = min(ans, i-last-1);
            last = i;
        }
    }
    //option to remove the entire suffix of numbers equal to 𝑎1 (or 𝑎𝑛— they are equal to each other, since the given array is beautiful);
    ans = min(ans, n-last-1);
    if(ans == n){
        cout<<-1<<endl; 
    }else{
        cout<<ans<<endl;
    }

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}