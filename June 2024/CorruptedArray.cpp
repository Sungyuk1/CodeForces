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
    long long n; cin>>n; 
    vector<long long>b(n+2);
    long long total = 0; 
    for(int i = 0; i<n+2; ++i){
        cin>>b[i];
        total+=b[i];
    }

    //Sort so that the last two elements in b are the biggest 2
    sort(b.begin(), b.end());
    
    //Note that the element that is the sum will either be at the last or second to last index
    // since it is the equal to the sum of the first n elements. Only case when the sum of first n
    //is not at the last index is when the random added integer is larger. 
    //We check if removing any of the elements gives us the last element
    for(long long i = 0; i<n+1; ++i){
        //cout<<"current val : " <<total -b[i] - b[n+1]<<endl; 
        if(total - b[i] - b[n+1] == b[n+1]){
            for(long long j = 0; j<n+1; ++j){
                if(j == i){
                    continue;
                }
                cout<<b[j]<<" ";
            }
            cout<<endl; 
            return; 
        }
    }

    //Check edge case where the random integer x that was added is larger than the sum of the first n elements
    if(total - b[n+1] - b[n]== b[n]){
        for(long long i = 0; i<n; ++i){
            cout<<b[i]<<" ";
        }
        cout<<endl; 
        return; 
    }

    cout<<-1<<endl; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}