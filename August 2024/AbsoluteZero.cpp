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
#include <cstring>

using namespace std;

const int MAX_N = 2e5 + 5;
int n, a[MAX_N];

void solve() {
    cin >> n;
    bool has_odd = false, has_even = false;
    for (int i = 1; i <= n; i++) { 
        cin >> a[i]; 

        if(a[i]%2==0) has_even = true;
        else has_odd = true;
    }

    if (has_even && has_odd){
        cout << -1 << '\n';
        return;
    }

    vector<int> operations;

    //Subtract 2^i from each element in the array starting from 2^29
    //Note we don't need the minimum number of operations, 
    //just any set of operations that will turn the elements all 0
    for (int i = 29; i >= 0; i--){
        operations.push_back(1 << i);
    }

    if (has_even){ operations.push_back(1); }

    cout << operations.size() << '\n';
    for (int op : operations)
        cout << op << ' ';
    cout << '\n';
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}