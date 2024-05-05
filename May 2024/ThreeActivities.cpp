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
        vector<int> b(n);
        vector<int> c(n);
        for(int j = 0; j < n; j++)
            cin >> a[j];

        for(int j = 0; j < n; j++)
            cin >> b[j];

        for(int j = 0; j < n; j++)
            cin >> c[j];
        
        vector<int>a_pref_max(n);
        a_pref_max[0] = a[0];
        for(int j = 1; j < n; j++){
            a_pref_max[j] = max(a[j], a_pref_max[j-1]);
        }
        vector<int>a_suff_max(n);
        a_suff_max[n-1] = a[n-1]; 
        for(int j = n-2; j >=0; --j){
            a_suff_max[j] = max(a[j], a_suff_max[j+1]);
        }

        vector<int>b_pref_max(n);
        b_pref_max[0] = b[0];
        for(int j = 1; j < n; j++){
            b_pref_max[j] = max(b[j], b_pref_max[j-1]);
        }
        vector<int>b_suff_max(n);
        b_suff_max[n-1] = b[n-1]; 
        for(int j = n-2; j >=0; --j){
            b_suff_max[j] = max(b[j], b_suff_max[j+1]);
        }

        vector<int>c_pref_max(n);
        c_pref_max[0] = c[0];
        for(int j = 1; j < n; j++){
            c_pref_max[j] = max(c[j], c_pref_max[j-1]);
        }
        vector<int>c_suff_max(n);
        c_suff_max[n-1] = c[n-1]; 
        for(int j = n-2; j >=0; --j){
            c_suff_max[j] = max(c[j], c_suff_max[j+1]);
        }

        long long ans = 0; 
        for(int i = 1; i<n-1; ++i){
            ans = max(ans, (long long) c[i] + a_pref_max[i-1]+ b_suff_max[i+1]);
            ans = max(ans, (long long) c[i] + a_suff_max[i+1]+ b_pref_max[i-1]); 
            ans = max(ans, (long long) b[i] + a_pref_max[i-1]+ c_suff_max[i+1]);
            ans = max(ans, (long long) b[i] + a_suff_max[i+1]+ c_pref_max[i-1]); 
            ans = max(ans, (long long) a[i] + c_pref_max[i-1]+ b_suff_max[i+1]);
            ans = max(ans, (long long) a[i] + c_suff_max[i+1]+ b_pref_max[i-1]); 
        }

        cout<<ans<<endl; 

        
    }

}