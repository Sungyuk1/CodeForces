#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

void solve(){
    int n, c, d; cin>>n>>c>>d; 
        vector<int>b(n*n);
        unordered_map<int, int> counter; 

        for(int i = 0; i<n*n; ++i){
            cin>>b[i];
            counter[b[i]]++;
        }

        //Numbers only get bigger as we go from top left to bottom right. This i because c and d are 
        //guaranteed to be positive. The smallest element will be the top left, and the largest the bottom right
        //sort(b.begin(), b.end());

        int first_num_in_row = *min_element(b.begin(), b.end());

        for(int i = 0; i<n; ++i){
            int curr_num = first_num_in_row;
            if(!(counter.contains(curr_num)) || counter[curr_num] == 0){
                cout<<"NO"<<endl; 
                return; 
            }
            //cout<<curr_num<<" ";
            counter[curr_num]--;

            for(int j = 1; j<n; ++j){
                curr_num+=d;
                if(!(counter.contains(curr_num)) || counter[curr_num] == 0){
                cout<<"NO"<<endl; 
                return; 
                }
                counter[curr_num]--;
                //cout<<curr_num<<" ";
            }

            first_num_in_row+=c;
        }
        cout<<"YES"<<endl;
        return; 

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }

}