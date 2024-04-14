#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int n, k; cin>>n>>k;
        vector<int> colors(n);
        for(int i = 0; i < n; i++){
            cin >> colors[i];
        
        int left_count = 0, right_count = 0, i = 0, j = n - 1;
        int k_left = k, k_right = k; //number of colors equal to c[0] and c[1]

        //f first and last have the same color, then we need to check that there are k-2
        // tiles of the first color between the first and the last tile.
        if (colors[0] == colors[n - 1]){
            k_left = k / 2;
            k_right = k - k_left;
        }

        //first loop goes from the start to the mid/end depending on if the end colors are the same
        //second loop goes from the right to the mid/start depending on if the end colors are the same

        for(; i < n && left_count < k_left; i++){
            if(colors[i] == colors[0]) left_count++;
        }
        for(; j >= 0 && right_count < k_right; j--){
            if(colors[j] == colors[n - 1]) right_count++;
        }
        //checks if the last elem in block1 is to the left of the first elem in block2 
        if((i - 1) < (j + 1)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }

}