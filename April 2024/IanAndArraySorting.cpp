#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <math.h> 

using namespace std;

//each index must differ between a and b
//sumnation of a and b must be equal

//Maybe make sure that we have at least n/2 unique numbers
int main(){
    int t; cin>>t;

    while(t--){
        long long n; cin>>n;
        vector<long long>a(n);
        long long int altsum = 0; 
        for(int i = 0; i<n; ++i){
            cin>>a[i];
            if(i%2==0){
                altsum-=a[i];
            }else{
                altsum+=a[i];
            }
        }

        if(n%2 == 1 ||altsum >=0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl; 
        }

    }

}