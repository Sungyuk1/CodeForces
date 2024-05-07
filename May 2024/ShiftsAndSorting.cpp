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
        string s; cin>>s;

        long long left = 0, right = 0; 
        long long one_count = 0;
        long long cost = 0; 
        for (; right < s.size(); ++right){
            if(s[right] != '0'){
                one_count++;
            }else{
                if(one_count > 0){
                    cost+=right-left+1;
                }
                left++;
            }
        }

        cout<<cost<<endl; 
    }

}