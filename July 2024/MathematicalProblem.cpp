#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

void solve(){
    int n; cin>>n; 
    string s; cin>>s; 
    vector<int>digits(n); 

    //If there are only two digits, we cannot place any operators
    if(n==2){
        if(s[0]=='0'){cout<<s[1]<<endl; }
        else{ cout<<s<<endl; }
        return; 
    }
    
    for(int i = 0; i<n; ++i){ digits[i] = s[i] - '0';}
    
    //Brute force having every adjacent pair be the number with two digits
    //Then iterate through the digits to the front and to the back optimally
    int min_ans = INT_MAX; 
    for(int i = 0; i<n-1; ++i){
        int current_val = (digits[i]*10) + digits[i+1];

        if(current_val == 0){
            cout<<0<<endl;
            return; 
        }

        //Apply operations to digits in front optimally
        for(int j = 0; j<i; ++j){
            if(digits[j] == 0){
                cout<<0<<endl; 
                return; 
            }else if(digits[j] == 1 ){
                continue; 
            }else if(current_val == 1){
                current_val = digits[j];
            
            }else{
                current_val+=digits[j];
            }
        }

        //Apply operations to digits to the back optimally
        for(int j = i+2; j<n; ++j){
            if(digits[j] == 0){
                cout<<0<<endl; 
                return; 
            }else if(digits[j] == 1){
                continue; 
            }else if(current_val == 1){
                current_val = digits[j];
            
            }else{
                current_val+=digits[j];
            }
        }

        min_ans = min(min_ans, current_val);
    }
    cout<<min_ans<<endl; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}