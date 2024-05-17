#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

void solve(){
    vector<pair<int, int>> lower_stack; 
    vector<pair<int, int>> upper_stack; 

    string input; cin>>input; 

    for(int i = 0; i<input.size(); ++i){
        if(isupper(input[i])){
            if(input[i] == 'B'){
                if(!upper_stack.empty()){
                    upper_stack.pop_back();
                }
            }else{
                upper_stack.push_back({i, input[i]});
            }
        }else{
            if(input[i] == 'b'){
                if(!lower_stack.empty()){
                    lower_stack.pop_back();
                }
            }else{
                lower_stack.push_back({i, input[i]});
            }
        }
    }

    lower_stack.insert( lower_stack.end(), upper_stack.begin(), upper_stack.end() );
    sort(lower_stack.begin(), lower_stack.end());
    string output = "";
    for(auto & p: lower_stack){
        output+=p.second;
    }
    //cout<<"ans : "<<output<<endl; 
    cout<<output<<endl;




}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }
}
