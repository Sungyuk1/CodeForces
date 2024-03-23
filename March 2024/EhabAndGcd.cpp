#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int x; cin>>x;
        //if x and x, then gcd is x and lcm is x. Addktion is 2x
        //if x and 2x then gcd is x and LCM is 2x. addition will be 3x
        //if x and 3x then gcd is x, and LCM is 3x. addition will be 4x

        if(x%2 ==0){
            cout<<x/2<<" "<<x/2<<endl;
        }else{
            cout<<1<<" "<<x-1<<endl;
        }



    }
}