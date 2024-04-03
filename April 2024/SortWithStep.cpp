#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//Longest range of consequtive factors
int main(){
    int t; cin>>t;

    while(t--){
        int n, k; cin>>n>>k;
        vector<int> a;
        
        for(int i = 0; i<n; ++i){
            int temp; cin>>temp; temp--;
            a.push_back(temp);
        }
        if(k == 1){
            cout<<0<<endl;
            continue;
        }

        int bad = 0;
        for (int i=0; i<n; i++) {
            if (a[i] % k != i % k) {
                bad++;
            }
        }

        if(bad == 0)
            cout << 0 << '\n';
        else if(bad == 2)
            cout << 1 << '\n';
        else
            cout << -1 << '\n';
    } 

}