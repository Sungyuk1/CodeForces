#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

void solve() {
    int n; cin >> n;

    //base cases
    if (n == 1) {
        cout << "1" << endl;
        return;
    } else if (n == 2) {
        cout << "-1" << endl;
        return;
    }
    int current_odd_num = 1; 
    int current_even_num = 2; 
    int n_squared = n*n; 

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            if(current_odd_num <=n_squared){
                cout<<current_odd_num<<" ";
                current_odd_num+=2;
            }else{
                cout<<current_even_num<<" ";
                current_even_num+=2;
            }
        }
        cout<<endl; 
    }
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}