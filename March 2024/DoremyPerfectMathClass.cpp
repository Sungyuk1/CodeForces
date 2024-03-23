#include <iostream>
#include <vector>
#include <algorithm>  
#include <unordered_set>

using namespace std;

//given three numbers, check if we can make them all equal with 3 splits
int main(){
    int t;cin>>t;

    while(t--){
        int n; cin>>n;
        vector<int> nums_in_set;
        unordered_set<int> nums_set;

        for(int i = 0; i<n; ++i){
            int temp; cin>>temp;
            if(!nums_set.contains(temp)){
                nums_set.insert(temp);
                nums_in_set.push_back(temp);
            }
        }

        sort(nums_in_set.begin(), nums_in_set.end());

    }

}