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
        int n; cin>>n;
        vector<vector<int>>perm(n, vector<int>(n - 1)); //holds all the provided permutatoins with 1 missing value
        vector<int>p(n, 0); //holds ans
        
        //count the number of occurrences of each first character
        vector<int>cnt(n + 1, 0);
        for(int i = 0; i < n; i++){
            p[i] = i + 1;
            for(int j = 0; j < n - 1; j++){
                cin >> perm[i][j];
                if(j == 0) cnt[perm[i][j]]++;
            }
        }
        //iterate through all first number counts and find the first character
        for(int i = 1; i <= n; i++){
            if(cnt[i] == n - 1){
                p[0] = i;
                break;
            }
        }
        //find the provided permutation missing the first elem, and copy to answer
        for(int i = 0; i < n; i++){
            if(perm[i][0] != p[0]){
                for(int j = 0; j < n - 1; j++){
                    p[j + 1] = perm[i][j];
                }
            }
        }
        for(int i = 0; i < n; i++) cout << p[i] << ' ';
        cout << endl;


    }

}