#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

void solve(){
    int prev_x = 0;
    int rem_count = 0; 
    int n; cin>>n;

    string s; cin>>s;
    
    for(auto c: s){
        if(c == 'x'){
            prev_x++;
        }else if(prev_x >= 3){
            rem_count+=prev_x-2;
            prev_x= 0;
        }else{
            prev_x= 0;
        }
    }

    if(prev_x >= 3){
        rem_count+=prev_x-2;
        prev_x= 0;
    }
    cout<<rem_count<<endl;

}

int main(){
    solve();    
}