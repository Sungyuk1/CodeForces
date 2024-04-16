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
        int n; cin>>n;
        int a = 1;
        
        for (int g = 2; g * g <= n; ++g) {
        if (n % g == 0) {
            a = n / g;
            break;
        }
        }
        cout << a << ' ' << n - a << '\n';

        
    }

}