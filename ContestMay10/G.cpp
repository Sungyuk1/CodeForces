#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
 
using namespace std;
 
 
void solve(){
    int n; cin >> n;
    vector<int> a(n);

    //Group all the elements that share all bits in their binary representation, except for the last 2 bits
    //This is needed to ensure that the xor of the numbers in the same group are all less than 4
    map<int, priority_queue<int>> mp;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        //Key in the map is the binary representation except for the last two bits
        mp[a[i]>>2].push(-a[i]); //The neg is so we can get a min heap
    }
    
    //itereate through the list. For each element, replace it with the smallest unused element in the same group
    for(int i = 0; i < n; i++){
        cout << -mp[a[i]>>2].top() << " ";
        mp[a[i]>>2].pop();
    }
    cout << endl;
}
 
int main(){
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}