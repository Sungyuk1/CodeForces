#include <iostream>
#include <vector>
#include <algorithm>  
#include <unordered_set>

using namespace std;

//given three numbers, check if we can make them all equal with 3 splits
int main(){
    int t;cin>>t;

    while(t--){
        int k; cin>>k;
        if(k==1){
            cout<<"-1"<<endl;
        }else{
            int output = k-1;
            cout<<output<<endl;
        }

    }
}