#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n;

        //need to find 3 distinct integers that sum up to n where gcd(a, b) = c
        //c has to be smaller than either a or b
        //a = x*c, b = y*c 
        if((n-1)%2 == 1){
            cout<<n-3<<" "<<2<<" "<<1<<endl;
        }else{
            cout<<n-4<<" "<<3<<" "<<1<<endl;
        }


    }

}