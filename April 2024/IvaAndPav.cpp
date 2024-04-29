#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <math.h> 
#include <queue>
#include <set>

using namespace std;

//each index must differ between a and b
//sumnation of a and b must be equal

const int N =200003;
const int bits=30;
int pref[N][bits];
int a[N];
void Buildprefix(int n){ //Builds the prefix sums for each bit
    for(int i=0; i< n; i++){
        for(int j=0; j<30; j++){
            if(a[i]&(1<<j)){
                pref[i+1][j]=pref[i][j]+1;
            }
            else{
                pref[i+1][j]=pref[i][j];
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i=0; i< n; i++){
        cin >> a[i];
    }
    Buildprefix(n);
    int q;
    cin >> q;
    while(q--){
        int l, k;
        cin >> l >> k;
        if(a[l-1]<k){
            cout << -1 << '\n';
            continue;
        }
        int lo=l;
        int hi=n;
        int ans=l;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int num=0;
            for(int j=0; j< bits; j++){
                if(pref[mid][j]-pref[l-1][j]==mid-l+1){
                    num+=(1<<j);
                }
            }
            if(num>=k){
                lo=mid+1;
                ans=max(ans, mid);
            }
            else hi=mid-1;
        }
        cout << ans << '\n';
    }
}

//Maybe make sure that we have at least n/2 unique numbers
int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}