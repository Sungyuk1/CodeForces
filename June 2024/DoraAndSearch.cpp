#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

//find first element with a smaller element to the right, and find first element with bigger element to the left?
void solve(){
    int n; cin>>n;
    vector<int>a(n); 
    for(int i = 0; i<n; ++i){
        cin>>a[i];
    }

    //two pointers with ends
    int left = 0; int right = n-1;
    int mini = 1, maxi = n; 

    while(left <= right){
        if(a[left] == mini){
            left++;
            mini++;
        }else if(a[left] == maxi){
            left++;
            maxi--;
        }else if(a[right] == mini){
            right--;
            mini++;
        }else if(a[right] == maxi){
            right--;
            maxi--;
        }else{
            break;
        }
    }

    if(left<=right){
        cout<<left+1<<" "<<right+1<<endl; 
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