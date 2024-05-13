#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <cmath>

using namespace std;

bool solve(){
    int n; cin>>n; 
    string s; cin>>s;
    vector<int>translation(26, -1);

    translation[s[0] - 'a'] = 1;

    for(int i = 1; i<n; ++i){
        if(translation[s[i] - 'a'] == -1){
            translation[s[i] - 'a'] = !translation[s[i-1] - 'a'];
        }else{
            if(translation[s[i] - 'a'] == translation[s[i-1] - 'a']){
                return false; 
            }
        }
    }
    return true;


}
int main(){
    int t; cin>>t;

    while(t--){
        bool res = solve();
        if(res){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl; 
        }
    
    }

}