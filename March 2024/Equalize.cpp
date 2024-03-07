#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int main(){
    int number_test_cases;
    cin>>number_test_cases;

    while(number_test_cases--){

        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        //remove duplicate values since permutations have no duplicates
        a.resize(unique(a.begin(), a.end()) - a.begin());
        int pnt = 0, ans = 0;
        for (int i = 0; i < a.size(); i++) {
            while(a[i] - a[pnt] >= n) {
                pnt++;
            }
            ans = max(ans, i - pnt + 1);
        }
        cout << ans << endl;

    }
    return 0;
}