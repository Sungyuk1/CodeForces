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
        long long n, m; cin>>n>>m;
        vector<long long> a;
        a.push_back(-1);
        for(int i=1;i<=n*m;++i){
            int temp; cin>>temp;
            a.push_back(temp);
        }

        sort(a.begin()+1,a.end());
        
        if(n>m){
            swap(n, m);
        }

        if(n==1){
            cout<<(m-1)*(a[n*m]-a[1])<<endl;
        }else{
            long long ans1=(n*m-1)*(a[n*m])-a[1]*(n*(m-1))-a[2]*(n-1);
            long long ans2=a[n*m]*(n*(m-1))+a[n*m-1]*(n-1)-a[1]*(n*m-1);
            cout<<max(ans1,ans2)<<endl;
	    }

    }

}