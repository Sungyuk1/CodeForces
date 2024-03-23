#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int left, right, k; cin>>left>>right>>k;

        //base case - array has 1 element
        if(left == right && left!= 1){
            cout<<"YES"<<endl;
            continue;
        }

        //You can delete two nums and put back the product at most k times
        //We want to make the gcd of the array greater than 1

        //remove all prime numbers?
        int num_odd = (right-left+1) - (right/2 - ((left-1)/2));
        if(num_odd <= k){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }


    }

}