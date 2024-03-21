#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

//given three numbers, check if we can make them all equal with 3 splits
int main(){
    int t;cin>>t;

    while(t--){
        long long n, k, x; cin>>n>>k>>x;

        //choose k distinct integers from 1-n such that there sum equals x
        //need to break x k times, and each piece has to be distinct

        //sumnation of range to range-k 
        long long sumnation_n = (n*(n+1))/2;
        long long sumnation_k = ((n-k)*(n-k+1))/2;
        long long biggest_poss = sumnation_n - sumnation_k;

        long long smallest_poss = (k*(k+1))/2;

        //cout<<"biggest poss : "<<biggest_poss<<endl;

        if(biggest_poss>=x && smallest_poss<=x){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }


    }

}