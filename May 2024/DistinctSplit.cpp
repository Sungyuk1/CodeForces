#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n; 
        string s; cin>>s;  
        
        vector<long long>counter_left(26, 0);
        vector<long long>counter_right(26, 0);
        long long count_left=0, count_right = 0; 

        for(auto c: s){
            counter_right[c-'a']++;
            if(counter_right[c-'a'] == 1){
                count_right++;
            }
        }
        long long max_score = count_right;
        for(int i = 0; i< s.size(); ++i){
            counter_right[s[i]-'a']--;
            if(counter_right[s[i]-'a'] == 0){
                count_right--;
            }
            counter_left[s[i]-'a']++;
            if(counter_left[s[i]-'a'] == 1){
                count_left++;
            }

            max_score = max(max_score, count_left + count_right);
        }

        cout<<max_score<<endl; 

    }

}

