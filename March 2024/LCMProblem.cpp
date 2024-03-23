#include <iostream>
#include <vector>
#include <algorithm>  
#include <unordered_set>

using namespace std;

//given three numbers, check if we can make them all equal with 3 splits
int main(){
    int t;cin>>t;

    while(t--){
        int left, right; cin>>left>>right;

        if(right < 2*left){
            cout<<-1<<" "<<-1<<endl;
        }else{
            cout<<left<<" "<<2*left<<endl;
        }

        //find two numbers between left and right such that their LCM is also between left and right

    }

}