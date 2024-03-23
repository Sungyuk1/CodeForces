#include <iostream>
#include <vector>
#include <algorithm>  
#include <unordered_set>

using namespace std;

//given three numbers, check if we can make them all equal with 3 splits
int main(){
    int t;cin>>t;

    while(t--){
        int n; cin>>n;
        int odd_count = 0;
        int even_count = 0;
        int count = 0;
        int min_to_even_count = INT_MAX;
        int min_to_odd_count = INT_MAX;

        for(int i = 0; i<n; ++i){
            int temp; cin>>temp;
            count = 0;

            if(temp & 1){
                odd_count++;
                while(temp&1){
                    count++;
                    temp = temp/2;
                }
                if(count > 0){
                    min_to_even_count = min(min_to_even_count, count);
                }
            }else{
                even_count++;
                while(temp > 0 && temp%2 == 0){
                    count++;
                    temp = temp/2;
                }
                if(count > 0 && temp%2 == 1){
                    min_to_odd_count = min(min_to_odd_count, count);
                }
            }
        }
        if(odd_count %2 ==0){
            cout<<0<<endl;
        }else{
            cout<<min(min_to_even_count, min_to_odd_count)<<endl;
        }

    }
}