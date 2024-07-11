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

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) { cin >> a[i];}

    //We binary search on the answer range
    //AKA we binary search on the maximum difference between a toy pattern and the optimal carver for that pattern
    sort(a.begin(), a.end());
    int l = -1, r = 1e9;
    while (r - l > 1) {
        //m is the time we are checking if suitable. Aka maximum wait suffered by a customer
        int m = (l + r) >> 1;
        int i = 0;
        //scan from start to end until diff between the start and the end is greater than 2 * mid
        while (i + 1 < a.size() && a[i + 1] - a[0] <= 2 * m) {
            ++i;
        }

        //Scan from the end to the start until we find an index who's difference with the last element is 
        //greater than 2*mid
        int j = n - 1;
        while (j - 1 >= 0 && a.back() - a[j - 1] <= 2 * m) {
            --j;
        }

        //Add to i and decrease j so we get the first and last element in the middle section
        ++i; --j;
        //If the middle section overlaps, or if the difference between the elements in the middle section 
        //are smaller than 2*mid, we decrease the length of the maximum time to finish a task (wait suffered by a 
        //customer). Otherwise we increase the length of the maximum time to finish a
        // task to see if we can get a valid answer
        if (i > j || a[j] - a[i] <= 2 * m) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << "\n";

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}