#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>

using namespace std;

int main(){
    int t;cin>>t;

    while(t--){
        int n; cin>>n;
        vector<long long> rows, cols;
        
        for(int i = 0; i<n; ++i){
            long long temp; cin>>temp;
            rows.push_back(temp);
        }
        for(int i = 0; i<n; ++i){
            long long temp; cin>>temp;
            cols.push_back(temp);
        }

        long long min_row = *min_element(rows.begin(), rows.end());
        long long sum_row = accumulate(rows.begin(), rows.end(), 0LL);
        long long min_cols = *min_element(cols.begin(), cols.end());
        long long sum_cols = accumulate(cols.begin(), cols.end(), 0LL);
        long long ans = min(min_row * n + sum_cols, min_cols * n + sum_row);   

        cout<<ans<<endl;
    }

}