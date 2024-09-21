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

void solve() {
	int n;cin >> n;
	
    //Hold the count of the number of times each last digit occurs.
    int cnt[10] = {};
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		cnt[x % 10]++;
	}

    //Note that if a number appears more than 3 times in the array, we can ignore all copies that 
    //occur more than 3 times. 
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < min(cnt[i], 3); j++) {
			v.push_back(i);
		}	
	}

    //Brute force the creation of every possible triplet
	int m = v.size();
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			for (int k = j + 1; k < m; k++) {
				if ((v[i] + v[j] + v[k]) % 10 == 3) {cout << "YES\n"; return;}
			}
		}
	}
	cout << "NO\n";
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}