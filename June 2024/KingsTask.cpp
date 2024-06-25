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

void solve(){
    int n; cin >> n;
    vector<int> v(n << 1);
    for (int &x : v){ cin >> x; }
        
    if (n & 1){
        //If n is odd, then the length of the cycle is 2n. For example, the first element of the 
        //permutation moves in the following cycle: 1 → 2 → (n + 2) → (n + 3) → 3 → 4 → . . . → 2n → n → (n + 1) → 1.
        for (int k = 0; k < n << 1; k++){
            if (is_sorted(v.begin(), v.end())){
                cout << min(k, (n << 1) - k) << endl;
                return;
            }

            for (int i = 0; i < n; i++){
                //Both operations are self-inverse, i.e. if you apply the same operation twice, 
                //you get the initial permutation. So, if you make a sequence of operations, these 
                //operations must have alternating types.
                if (k & 1)
                    swap(v[2 * i], v[2 * i + 1]);
                else
                    swap(v[i], v[i + n]);
            }
        }
    }else{
        //If n is even, then the length of the cycle is 4. For example, the first element of 
        //the permutation moves in the following cycle: 1 → 2 → (n+2) → (n+1) → 1.
        for (int k = 0; k < 4; k++){
            if (is_sorted(v.begin(), v.end())){
                cout << min(k, 4 - k) << endl;
                return;
            }
            for (int i = 0; i < n; i++)
                if (k & 1)
                    swap(v[2 * i], v[2 * i + 1]);
                else
                    swap(v[i], v[i + n]);
        }
    }
    cout << "-1\n";
}

int main(){
    solve();
}