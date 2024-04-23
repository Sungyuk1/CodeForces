#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void solve() {
   int n; cin >> n;
   string s, p;
   cin >> s >> p;
   string x;
   for (int i = 0; i < n; i++) {
      if (i % 2 == 0) x.push_back(p[i]);
      else x.push_back(s[i]);
   }
   for (int i = 0; i < n - 1; i++) {
      if (x[i] == '<' and x[i + 1] == '<') {
         cout << "NO\n";
         return;
      }
   }
   cout << "YES\n";
}

//Longest range of consequtive factors
int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }

}