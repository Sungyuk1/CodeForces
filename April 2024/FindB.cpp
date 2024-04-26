#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int n, q; cin>>n; cin>>q;

        vector<long long> prefixSum;
        vector<long long>cnt1;
        prefixSum.push_back(0);
        cnt1.push_back(0);

        for(int i = 0; i<n; ++i){
            int temp; cin>>temp;
            prefixSum.push_back(prefixSum.back() + temp);
            cnt1.push_back(cnt1.back() + (temp == 1));
        }

        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            --l; //sub left to make it easier to use with ps arrays
            int cur_cnt1 = cnt1[r] - cnt1[l];
            long long cur_sum = prefixSum[r] - prefixSum[l];
            
            if((r - l) + cur_cnt1 <= cur_sum && r - l > 1){
                cout << "YES"<<endl;;
            }
            else{
                cout<<"NO"<<endl; 
            }
        }
        

    }
}