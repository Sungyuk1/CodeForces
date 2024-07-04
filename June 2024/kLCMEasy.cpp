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
    int n, k; cin>>n>>k; 

    //we want to make lcm as small as possible with 3 numbers that add up to n.
    //We don't want numbers to be coprimes because that would make the numbers be bigger

    if(n&1){
        //if odd subtract 1, divide by 2. lcm will be the divide by 2
        int num1 = 1; 
        n--; 
        int num2 = n/2; 
        int num3 = n/2;

        cout<<num1<<" "<<num2<<" "<<num3<<endl; 
    }else if(n%4==0){
        //even and multiple of 4
        int num1 = n/2;
        int num2 = n/4; 
        int num3 = n/4; 
        cout<<num1<<" "<<num2<<" "<<num3<<endl; 

    }else{
        //even but not a multiple of 4
        int num1 = n/2 -1;
        int num2 = n/2 -1; 
        int num3 = 2; 

        cout<<num1<<" "<<num2<<" "<<num3<<endl; 
    }


}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}