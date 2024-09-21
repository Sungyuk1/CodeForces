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

//The last element of modification array has to be present in D. 
//All the elements which are different in B from A have to be present in D as well 
//to carry out the modification. Except for that any other element in D does not 
//matter because you could be changing that element in A to an intermediate number 
//but then you finally change it to what it is in B.
void solve(){
    long long n; cin>>n; 
    vector<long long>a(n);
    for(long long i = 0; i<n; ++i){
        cin>>a[i];
    }

    vector<long long>b(n); 
    for(long long i = 0; i<n; ++i){
        cin>>b[i];
    }

    long long m; cin>>m; 
    vector<long long>modifications(m); 
    for(long long i = 0; i<m; ++i){
        cin>>modifications[i];
    }

    //If the element that is placed in the last operation is not included in the
    //array b, then there is no way that the array a can be transformed into the array b
    //by performing the provided operations. For all other elements in the provided operations
    //that is not included in b, they can be placed on the same index as the last operation and then
    //"covered up" by the last operation. 
    bool found_last = false; 
    for(auto num: b){
        if(num == modifications.back()){
            found_last = true; 
            break; 
        }
    }
    if(!found_last){
        cout<<"NO"<<endl;
        return; 
    }

    map<int,int> diff;
    for(int i=0;i<m;i++) diff[modifications[i]]++;

    for(int i=0;i<n;i++){

        if(a[i]!=b[i]){
            if(diff[b[i]]==0){
                cout<<"NO"<<endl; 
                return;
            }else{
                diff[b[i]]--;
            }
        }
    }
    cout<<"YES"<<endl; 
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}