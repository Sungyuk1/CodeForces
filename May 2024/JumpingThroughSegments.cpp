#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

/*To check whether it is possible to pass the level with a certain k, 
we will maintain a segment in which we can find ourselves. After each move, it expands by k
in both directions and is reduced to the intersection with the segment where the 
player must be at that move. If at any point the intersection becomes empty, 
then it is impossible to pass the level with such k
.*/
bool check(int k, vector<pair<long long, long long>>& segments){
    long long left = 0, right = 0;
    for(auto segment: segments){
        //1) Calculate the most left you can be. You can go left up to prev left -k, but you are bound 
        //   by the left most boundary of the current segment.
        left = max(left -k,segment.first);

        //2) Calculate the most right you can be. You can go right up to prev right + k, but you are 
        //   bound by the right most boundary of the current segment.  
        right = min(right+k, segment.second);

        if(left > right){
            return false; 
        }
    }
    return true; 
}

void solve(){
    int n; cin>>n;
    vector<pair<long long, long long>> segments;
    for(int i = 0; i<n; ++i){
        long long l, r; cin>>l>>r;
        segments.push_back({l, r});
    }

    long long left = -1, right = 10e9;
    while(right -left > 1){
        int mid = (right+left)/2;
        if(check(mid, segments)){
            right = mid; 
        }else{
            left = mid; 
        }
    }

    cout<<right<<endl;

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}