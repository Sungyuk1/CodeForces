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
    int n, x; cin>>n>>x; 
    vector<int> A(n);
    for(auto & a: A){
        cin>>a;
    }

    int segments = 1; 

    //The factors array will hold all the factors of x in the current segment
    vector<int>factors = {1}; 

    for(auto &a: A){
        //a is not a factor of x. Therefore a cannot be used as a product to create x. 
        //Therefore, add a to the current segment without worring about it contributing to a
        //product of x
        if(x%a != 0){
            continue; 
        }

        vector<int>new_factors = factors; 

        //We iterate through all the existing factors of x in our segment
        //If the product of the current number and an exisiting factor of x is also a 
        //product of x, add the product to the new_factors array
        //Note that 1 is included in factors array, so all numbers that are already factors 
        //of x will be added to the factors array. 
        for(int f : factors){
            int product = f * a;

            if(x% product == 0){
                new_factors.push_back(product);
            }
        }

        //Get rid of duplicate factors
        factors.swap(new_factors);
        sort(factors.begin(), factors.end());
        factors.erase(unique(factors.begin(), factors.end()), factors.end());

        //xmodx == 0 but xmod(Any number > x) will be just x. Therefore, if adding this 
        //number creates x, we know that we need to start a new segment. 
        if(factors.back() == x){
            segments++;
            factors = {1, a};
        }
    }
    cout<<segments<<endl; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}