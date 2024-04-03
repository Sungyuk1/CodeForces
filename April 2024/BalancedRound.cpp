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
        vector<int>a;
        for(int i = 0; i<n; ++i){
            int temp; cin>>temp;
            a.push_back(temp);
        }
        
        sort(a.rbegin(), a.rend());

        vector<int> bad_indexes;
        bad_indexes.push_back(-1);

        for(int i = 0; i<n-1; ++i){
            if(a[i]- a[i+1] > k){
                bad_indexes.push_back(i);
            }
        }
        bad_indexes.push_back(n-1);

        if(n == 1){
            cout<<0<<endl;
            continue;
        }

        /*cout<<"a : [";
        for(auto i: a){
            cout<<i<<" ";
        }cout<<"]"<<endl;

        cout<<"Bad Indexes : [ ";
        for(auto i: bad_indexes){
            cout<<i<<" ";
        }cout<<"]"<<endl;*/


        int min_remove = INT_MAX;
        for(int i = 1; i<bad_indexes.size(); ++i){
            min_remove = min(min_remove, n-(bad_indexes[i] - bad_indexes[i-1]));
        }
        //cout<<"min_remove : "<<min_remove<<endl;
        cout<<min_remove<<endl;

    }

}