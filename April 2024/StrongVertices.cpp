#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(){
    //get parent by division by 2
    //seg tree to get count smaller
    int t; cin>>t;

    while(t--){
        long long n; cin>>n;
        vector<int>a(n, 0);
        vector<int>b(n, 0);

        for(int i = 0; i<n; ++i){
            cin>>a[i];
        }

        for(int i = 0; i<n; ++i){
            cin>>b[i];
        }

        //find maximum difference for a[i] - b[i]
        int mx=INT_MIN;
        for(int i=0;i<n;i++)mx=max(mx,a[i]-b[i]);

        //Count the number of indexes with the maximum difference
        int c=0;
        for(int i=0;i<n;i++)c+=(a[i]-b[i]==mx);

        cout<<c<<"\n";
        for(int i=0;i<n;i++)if(a[i]-b[i]==mx)cout<<i+1<<' ';
        cout<<"\n";
    }

}