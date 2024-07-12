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
    string n_str = to_string(n);
    int n_len = n_str.size();
    vector<pair<int, int>>solutions; 

    //Iterate through the possible lengths of valid answers since 
    //Max result of (n*a) - b is less than 1 million so will have 6 digits
    for(int len = 1; len <=6; ++len){
        //We use the fact that the answer to (n*a) - b has to be a prefix of the 
        //concatenation of n multiple times. This way we can calcualte the value we 
        //are looking for.
        string value_str; 
        for(int i = 0; i<len; ++i){
            //if the length of n is not 0, the modulus lets us concatenate the characters of n 
            //1 by 1 in order as i increases
            value_str+=n_str[i%n_len];
        }

        //Convert to value we are looking for into a string
        int value = stoi(value_str);

        //Iterate over all the possible values of a. We can then use algebra to calculate the values of b.
        //This allows us to iterate 10000 * 6 rather than 10 million times to check every a b pair
        for(int a = 1; a<= 10000; ++a){
            int b = (n*a) - value; 

            if(1<=b && b<=10000 && n_len*a -b == len ){
                solutions.push_back({a, b});
            }
        }
    }

    cout<<solutions.size()<<endl; 
    for(auto &[a, b] : solutions){
        cout<<a<<" "<<b<<'\n';
    }
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}