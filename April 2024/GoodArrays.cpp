#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//each index must differ between a and b
//sumnation of a and b must be equal

//Maybe make sure that we have at least n/2 unique numbers
int main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        unordered_map<int, int> freq;
        vector<int> a(n);
        long long sum_a = 0;
        long long one_count = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            sum_a+=a[i];
            if(a[i] == 1){
                one_count++;
            }
        }

        if (sum_a >= one_count + n && n > 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

}