#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <stdio.h>
#include <cstring>

using namespace std;

void solve()
{
 
}

int main(){
    int t; cin>>t;

    while(t--){
        string s; cin>>s;
        vector<char>stack;

        for(auto c: s){
            if(stack.empty() || c != stack.back()){
                stack.push_back(c);
            }
        }
        if(stack.size() == 1){
            cout<<1<<endl;
        }else if(stack.size() == 2){
            if(stack[0] == '0'){
                cout<<1<<endl; 
            }else{
                cout<<2<<endl; 
            }
        }else{
            cout<<stack.size()-1<<endl; 
        }
        
    }

}