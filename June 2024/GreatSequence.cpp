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
    long long n, x; cin>>n>>x;
    vector<long long>a(n);
    unordered_map<long long, long long>counter; 
    for(long long i = 0; i<n; ++i){
        cin>>a[i];
        counter[a[i]]++;
    }

    //we want minimum number of integers that has to be added to make the sequence great. 
    //So count the number of integers that do not have a value that is greater than it
    sort(a.begin(), a.end());
    long long count = 0;
    for(long long i = 0; i<n; ++i){
        if(counter[a[i]] == 0){
            //was paired with a smaller number
            continue; 
        }

        if(counter.contains(a[i]*x) && counter[a[i]*x] > 0){
            //valid pairing
            if(x==1 && counter[a[i]] == 1){
                //need to add number
                counter[a[i]]--;
                count++;
            }else{
                counter[a[i]*x]--;
                counter[a[i]]--;
            }
        }else{
            //need to add number
            counter[a[i]]--;
            count++;
        }

    }
    cout<<count<<endl; 

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}