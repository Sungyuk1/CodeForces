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

//Note that at each index we can add the element at i to the rolling total or 
//add the element at i to the rolling total then take the absolute value of the rolling total.
//Therefore, we want to pick option 2 at the most negative rolling total (Operation is redundant if
//the rolling total is positive)
//We only want to apply the operation once, at the most negative rolling total. 
void solve() {
  int n; cin >> n;
  vector<int> arr(n); for (int i = 0; i < n; ++i) cin >> arr[i];
  long long sum = 0, mn = 0;

  for (int i = 0; i < n; ++i){
    //The +=arr[i] simulates the first operation
    sum += arr[i];

    //We want to find the smallest rolling total that is negative. We can turn this rolling total
    //into all positive. 
    mn = min(mn, sum);
  }

  //-2 * mn because the amount that the rolling total takes away is switched to positive so it only
  //adds the same amount it was taking away to the sum. Basically simulating undoing the subtraction
  //and doing the addition
  cout << sum - 2 * mn << '\n';
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}