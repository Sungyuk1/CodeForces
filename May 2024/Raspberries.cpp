#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int n, k; cin>>n>> k; 
        int min_diff = k;
        int even_count = 0; 

        for(int i = 0; i<n; ++i){
            int temp; cin>>temp; 
            if(temp%2==0){
                even_count++;
            }
            int diff = temp%k; 
            if(diff == 0){
                min_diff = 0;
            }else{
                min_diff = min(min_diff, k - diff);
            }
        }
        if(k!=4){
            cout<<min_diff<<endl; 
        }else{
            //min of turning 1 number into 4, or turning two numbers even
            cout<<min(min_diff, max(0, 2-even_count))<<endl; 
        }

    }

}