#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
const int MAX = 200'007;
int res[MAX];

//calculates the sum of digits of a number x
int S(int x) {
	int res = 0;
	while (x) {
		res += (x % 10);
		x /= 10;
	}
	return res;
}

void solve(){
    int x; cin >> x;
	cout << res[x] << '\n';
}

int main(){
    //precomputation
    res[0] = 0;
	for (int i = 1; i < MAX; i++) {
        //sum of index is the sum of the digits in index, plus the sum of the previous numbers digit sums
		res[i] = res[i - 1] + S(i);
	}

    int t; cin>>t;
    while(t--){
        solve();
        
    }

}