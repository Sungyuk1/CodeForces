#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cmath>

using namespace std;

void solve(){
    int n; cin>>n; 

    vector<int>a(n);
    for(int i = 0; i<n; ++i){
        cin>>a[i];
    }

    //Calculate the sum of the number of twos in each element's prime factorization
    int total_two_count = 0; 

    //Store the number of twos in each index value's prime factorization
    vector<int>two_counts;

    for(int i = 0; i<n; ++i){
        //Calculate how many twos this current element adds to the total product's prime factorization
        int temp = a[i]; 
        while(temp%2 == 0){
            temp/=2;
            total_two_count++;
        }

        //Calculate the number of twos in each index value's prime factorization
        int index = i+1;
        int index_two_count = 0; 
        while(index %2 == 0){
            index/=2; 
            index_two_count++;
        }
        two_counts.push_back(index_two_count);
    }
    sort(two_counts.begin(), two_counts.end());

    //Greedily apply the operation to index values that have the most twos in their prime factorization
    int op_count = 0; 
    while(total_two_count < n && !two_counts.empty()){
        total_two_count+=two_counts.back();
        two_counts.pop_back();
        op_count++;
    }

    if(total_two_count >= n){
        cout<<op_count<<endl; 
    }else{
        cout<<-1<<endl; 
    }
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}