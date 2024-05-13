#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <stdio.h>
#include <cstring>

using namespace std;

void solve()
{
    int n;
	cin>>n;
	int S=1000;
	cout<<S<<" ";
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		S+=x;
		cout<<S<<" ";
	}
	cout<<"\n";
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }

}