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
        int n, k; cin >> n >> k; k--; //k is 1 indexed. Just decrement at the start
        vector<int> cows(n);
        for (int i = 0; i < n; i++) {
            cin >> cows[i];
        }

        //1) find the first cow in front of you that is bigger
        int first_bigger_cow = find_if(cows.begin(), cows.end(), [&](int cow) { return cow > cows[k]; }) - cows.begin();
        vector<int> pos(n); iota(pos.begin(), pos.end(), 0);

        int win_count = 0;
        //for 0 and first bigger cow
        for (int i : {0, first_bigger_cow}) {
            //continue if no cow is bigger than you
            if (i == n) {
                continue;
            }
            swap(pos[i], pos[k]);
            vector<int> stt(n);
            for (int j = 1, u = pos[0]; j < n; j++) {
                int v = pos[j];
                u = (cows[u] > cows[v] ? u : v);
                stt[u]++;
            }
            swap(pos[i], pos[k]);
            win_count = max(win_count, stt[k]);
        }



        
        

        cout<<win_count<<endl; 
        //6 4
        //938234363 5154597 980882739 7015826 563366955 493376626
        //ans should be 1



    }

}