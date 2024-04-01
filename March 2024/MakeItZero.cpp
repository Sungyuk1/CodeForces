#include <iostream>
#include <vector>
#include <algorithm>  
#include <unordered_set>

using namespace std;

//You can xor a subarray, then replace each elemnent with the xor
//can do this up to 8 times

int main(){
    int t;cin>>t;

    while(t--){
        int n; cin>>n;
        vector<int>a;

        for(int i = 0; i<n; ++i){
            int temp; cin>>temp;
            a.push_back(temp);
        }

        if (n & 1) {
            cout << "4" << '\n';
            cout << "1 " << n - 1 << '\n';
            cout << "1 " << n - 1 << '\n';
            cout << n - 1 << ' ' << n << '\n';
            cout << n - 1 << ' ' << n << '\n';
	    } else {
            cout << "2" << '\n';
            cout << "1 " << n << '\n';
            cout << "1 " << n << '\n';
	    }

    }

}
