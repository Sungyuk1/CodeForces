#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

void solve(){
    string current_cell; cin>>current_cell; 

    int curent_col = current_cell[0]-'a';
    int current_row = current_cell[1]-'0';

    for(int i = curent_col-1; i>=0; --i){
        char temp = i+'a';
        cout<<temp<<current_row<<endl; 
    }

    for(int i = curent_col+1; i<8; ++i){
        char temp = i+'a';
        cout<<temp<<current_row<<endl; 
    }

    for(int i = current_row-1; i>0; --i){
        cout<<current_cell[0]<<i<<endl; 
    }

    for(int i = current_row+1; i<9; ++i){
        cout<<current_cell[0]<<i<<endl; 
    }
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }
}
