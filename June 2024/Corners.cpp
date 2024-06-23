#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cmath>

using namespace std;

//An integer array which represents the matrix
int a[2000][2000];

void solve(){
    //count1 will store the number of 1s in the matrix
    int n, m, count1 = 0; cin>>n>>m;

    //Get all the inputs
    string row; 
    for(int i = 0; i<n; ++i){
        cin>>row; 
        for(int j = 0; j<m; ++j){
            a[i][j] = row[j] - '0';
            count1 += a[i][j];
        }
    }

    //Find an angle in the matrix with the minimal number of 1 in it, and which we can replace
    int minn = 1e9;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int cnt = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
            if (cnt == 0) continue;
            minn = min(minn, max(1, cnt - 1));
        }
    }

    //If there are no 1s in the matrix we cannot perform any operations
    if (count1 == 0){
        cout << "0\n";
    }else{
        //After the first operation, there will be at least one L with 2 zeros that we can use to perform
        //an operation that only removes 1 one. 
        cout << 1 + count1 - minn << "\n";
    }

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}