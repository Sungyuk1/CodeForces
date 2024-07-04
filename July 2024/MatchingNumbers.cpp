#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cmath>

using namespace std;

//I realized all the sums have to be different mod n so if I increase 
//one of the numbers by 1 and decrease the other by 2 it it will 
//always be different mod n.
void solve(){
    int n; cin >> n;

    //No Solution if n is even
    if (n % 2 == 0) {cout << "NO" << endl; return;}

    int a = n * 2;
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " " << a << endl;
        a -= 2;
        if (a <= n) a += n;
    }
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}