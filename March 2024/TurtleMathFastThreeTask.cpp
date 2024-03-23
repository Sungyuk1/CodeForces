#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

//given three numbers, check if we can make them all equal with 3 splits
int main(){
    int t;cin>>t;

    while(t--){
        int n; cin>>n;
        int count_mod_3_1 = 0;
        int total = 0;

        for(int i = 0; i<n; ++i){
            int temp; cin>>temp; 
            total+=temp;
            if(temp%3 == 1){
                count_mod_3_1++;
            }
        }

        if(total%3 == 0){
            cout<<0<<endl;
            continue;
        }
        if(total%3 ==2){
            cout<<1<<endl;
            continue;
        }
        if(total%3 == 1){
            if(count_mod_3_1 > 0){
                cout<<1<<endl;
            }else{
                cout<<2<<endl;
            }
        }
    }

}