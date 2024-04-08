#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//Longest range of consequtive factors
int main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        vector<int> array;
        long long count = 0;
        
        for(int i = 0; i<n; ++i){
            int temp; cin>>temp;
            if(temp == 0 && !array.empty() && array.back() != 0){
                count++;
            }
            array.push_back(temp);
        }

        if(!array.empty() && array.back() !=0){
            count++;
        }
        count = min(count, (long long)2);

        cout<<count<<endl;

    }


}