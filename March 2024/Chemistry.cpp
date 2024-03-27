#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

//You can flip an index at most once if i = A and i+1=B
//AB = 1
//AAB -> 
int main(){
    int t; cin>>t;

    while(t--){
        int n, k; cin>>n>>k;
        string s; cin>>s;

        vector<int>counter(26, 0);

        for(int i = 0; i<n; ++i){
            counter[s[i]-'a']++;
        }

        if(k>n){
            cout<<"NO"<<endl;
            continue;
        }else if(k == n || k == n-1){
            cout<<"YES"<<endl;
            continue;
        }

        int odd_count = count_if(counter.begin(), counter.end(), [](int elem) { return (elem&1) == 1; });
        //int odd_count = 0; 
        //int odd_sum = 0
        if(odd_count >k+1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
        //remove all odds
        //k-=odd_count;
        //can just remove by 2s until we remove 1 for the middle elem

        //if(k)
    }

}