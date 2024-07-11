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
    vector<long long>nums(n);

    //Group together elements with the same mod k. 
    map<long long, vector<long long>>mod_k_counter; 
    for(long long i = 0; i<n; ++i){
        cin>>nums[i];
        mod_k_counter[nums[i]%k].push_back(nums[i]);
    }
    
    //Base Case : if the array is 1 element, it is already a palindrome
    if(n==1){
        cout<<0<<endl; 
        return; 
    }

    long long total_operations = 0; 

    //Holds the total number of elements that do not have another element with the same mod k
    //to pair with in a palindrome.
    long long no_pair_count = 0; 

    //iterate through all the groups of elements that share mod k values. 
    for(auto& p: mod_k_counter){
        //if there is an odd number of elements in the group, there will be an additional
        //element that cannot pair up with another element of the same mod k
        if(p.second.size()%2==1){
            no_pair_count++;
        }
        if((n%2 == 0 && no_pair_count>0) || (n%2==1 && no_pair_count > 1)){
            cout<<-1<<endl; 
            return; 
        }

        //Two elements will take the least number of operations to make equal if they are close in value
        sort(p.second.begin(), p.second.end());

        if(p.second.size()%2==1){
            //cout<<"Number of elements with this value of mod k is odd"<<endl; 
            //One element will remain unpaired.
            //After one element is removed, it breaks down into the even case
            
            //Prefix Sum of costs of pairs starting from the front
            //Last element not incluced
            vector<long long>prefixPairs;
            prefixPairs.push_back(0);
            for(long long i = 0; i<p.second.size()-1; i+=2){
                prefixPairs.push_back(prefixPairs.back()+(p.second[i+1] - p.second[i])/k);
            }

            //Suffix Sum of costs of pairs starting from the back
            //First element not included
            vector<long long>SuffixPairs;
            SuffixPairs.push_back(0);
            for(long long i = p.second.size()-1; i>0; i-=2){
                SuffixPairs.push_back(SuffixPairs.back()+(p.second[i]- p.second[i-1])/k);
            } 

            long long min_cost = INT_MAX; 
            for(long long i = 1; i<p.second.size()-1; i++){
                if(i%2==1){
                    //If the index is even (1-indexed), then there is an odd number of elements to the front and back
                    long long cost = 0;

                    long long num_pairs_front = (i-1)/2; 
                    cost+=prefixPairs[num_pairs_front];

                    long long num_pairs_back = (p.second.size() - i-1)/2;
                    cost+=SuffixPairs[num_pairs_back];

                    cost+=(p.second[i+1] - p.second[i-1])/k; 
                    min_cost = min(min_cost, cost);
                }else{
                    //If the index is odd (1-indexed), then there is an even number of elements to the front and back. 
                    long long cost = 0;

                    long long num_pairs_front = i/2; 
                    cost+=prefixPairs[num_pairs_front];

                    long long num_pairs_back = (p.second.size()-i)/2;
                    cost+=SuffixPairs[num_pairs_back];

                    min_cost = min(min_cost, cost);
                }
            }
            //Cost if first index is removed
            min_cost = min(min_cost, SuffixPairs.back());

            //Cost if last index is removed
            min_cost = min(min_cost, prefixPairs.back());

            total_operations+=min_cost; 
        }else{
            //Even number of elements with the same mod k
            //Just pair up adjacent elements starting from the front
            for(long long i = 0; i<p.second.size(); i+=2){
                total_operations+=(p.second[i+1] - p.second[i])/k;
            }
        }
    }
    cout<<total_operations<<endl; 

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}