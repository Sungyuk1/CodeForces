#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

//sum of all the set bits need to equal x. But we cannot have two adjacent set bits. 
//if we have a set bit, we can get the same value by setting bit i+1 and setting to neg bit i-1. 
//2^(i+1) - 2^(i-1) = 2^(i)
void solve(){
    long long x; cin>>x;

    vector<int>res(31, 0);

/*We will iterate over the prefix of i bits and construct a correct answer for the number formed by 
the prefix bits of the number x.*/
    for(int i = 0; i<30; ++i){

        /*We are interested in considering only the one bits, as they are 
the only ones that affect the value of the number x.*/
        if((long long)1 & (x>>i)){

             /*If we have already placed a one at position i in the answer, we need to somehow add 2^i
 to the number. To do this, we simply zero out the i-th bit in the answer and set it at i+1. This will
 add 2*2^i = 2^(i+1). Now, the i-th position in the answer holds 0.*/
            if(res[i]){
                res[i+1] = 1;
                res[i] = 0;
            }
            //Let's consider what we placed at position i−1 in the answer.
            else if(i> 0){
                
                if(res[i-1] )

                //If it's 0, then everything is fine; we just place 1 at position i
                

            }else if(i == 0){

            }
        }
    }
    
    //sum of array has to be equal to x
    //so binary digits, and each can either be negative or positive
    //has to be gaps of zeros between set bits
    //elements can either be 1, 0, or -1


}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}