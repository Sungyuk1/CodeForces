#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n; 
        vector<int> a(n);
        for(int j = 0; j < n; j++)
            cin >> a[j];
        
        int mn = 0, mx = int(1e9);

        // take the minimum over the pairs of one type. Take the maximum over the pairs of another type.
        for(int j = 0; j<n-1; j++)
        {
            int x = a[j];
            int y = a[j + 1];
            int midL = (x + y) / 2;
            int midR = (x + y + 1) / 2;
            if(x < y)
                mx = min(mx, midL);
            if(x > y)
                mn = max(mn, midR);
        }
        // If two resulting values are contradictory, then there is no answer. Otherwise, any value inside the resulting range of x
        //works.
        if(mn <= mx) cout << mn << endl;
        else cout << -1 << endl;


    }
}