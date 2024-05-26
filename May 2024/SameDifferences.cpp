#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

//need to count the pairs such that the difference in value is equal to the difference in index
//sort?
void solve(){
    int n; cin>>n;
    map<int, int> a;
    long long res = 0; 
    for(int i = 0; i<n; ++i){
        int x; cin >> x;

        x -= i; //turn x into x - i
        res += a[x];
        a[x]++;
    }
    cout << res << endl;
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}