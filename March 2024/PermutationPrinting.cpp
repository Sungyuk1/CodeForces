#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int main(){
    int t;cin>>t;

    while(t--){
        int n; cin>>n;

        //an even number cannot divide an odd number. Be careful of 1
        long long left=1, right=n;
        for(long long i=1;i<=n;i++){
            if(i&1){
                cout<<left<<" ";
                left++;
            }
            else{
                cout<<right<<" ";
                right--;
            }
        }cout<<endl;
    }
}