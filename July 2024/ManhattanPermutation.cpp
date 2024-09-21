#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

void solve(){
    long long n, k; cin>>n>>k; 

    //Let's say that you have two numbers to swap from the identity permutation to try and make a bigger answer
    //Swapping 2 even values = even difference
    //Swapping 2 odd values = odd - odd = even, odd - odd = even, so even + even = even
    //swapping an even value and an odd value = odd - even = odd, even - odd = odd, so odd + odd = even
    //If you make any swaps your results always change in multiples of 2. Therefore, if k is odd there is no valid 
    //permutation we can make
    if(k%2 == 1){
        cout<<"NO"<<endl; 
        return; 
    }

    //calculate the max value possible. The max value would be created by the reverse of the identity permutation
    //If k is bigger than the maximum value we can get, then it is not possible to make a valid permutation 
    long long max_val = 0; 
    long long curr_n = n; 
    for(long long i = 1; i<=n; ++i){
        max_val += abs(curr_n - i);
        curr_n--;
    }

    if(k > max_val){
        cout<<"NO"<<endl; 
        return; 
    }
    
    cout<<"YES"<<endl; 
    if(k == max_val){
        for(long long i = n; i>0; --i){
            cout<<i<<" ";
        }cout<<endl; 
        return; 
    }

    //Now use two pointer approach to solve this problem. 
    vector<int>ans(n); //will nold our answer
    if(n%2 == 0){
        long long edge_val = n-1; //Stores the maximum 
        long long start_index = 0; //stores the start index of the current window
        long long end_index = n-1; //stores the end index of the current window
        long long min = 1; //stores the smallest number in the current window
        long long max = n; //stores the biggest number in the current window

        while(start_index <= end_index){
            if(k>= edge_val*2){
                ans[start_index] = max;
                ans[end_index] = min;
                start_index++;
                end_index--;
                max--;
                min++;
                k-=(edge_val*2);
                edge_val-=2;
            }else{
                if(k%4 == 0){
                    ans[end_index] = max;
                    end_index--;
                    max--;
                    edge_val--;
                }else{
                    ans[start_index] = min;
                    min++;
                    ans[end_index] = max; 
                    max--; 
                    start_index++;
                    end_index--;
                    edge_val-=2;
                }
            }
        }
    }else{
        long long edge_val = n-1; 
        long long start_index = 0; //stores the start index of the current window
        long long end_index = n-1; //stores the end index of the current window
        long long min = 1; //stores the smallest number in the current window
        long long max = n; //stores the biggest number in the current window

        while(start_index <= end_index){
            if(k>= edge_val*2){
                ans[start_index] = max;
                ans[end_index] = min;
                start_index++;
                end_index--;
                max--;
                min++;
                k-=(edge_val*2);
                edge_val-=2;
            }else{
                if(k%4 != 0){
                    ans[end_index] = max; 
                    end_index--; 
                    max--; 
                    edge_val--;
                }else{
                    ans[start_index]=min;
                    ans[end_index]=max; 
                    min++;
                    max--; 
                    start_index++;
                    end_index--;
                    edge_val-=2;
                }
            } 
        }

    }
    for(auto num: ans){
        cout<<num<<" ";
    }cout<<endl; 
    return; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}