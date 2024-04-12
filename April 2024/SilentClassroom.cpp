#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(){
        int n; cin>>n; cin.get();
        string str; 
        vector<int> first_char_counts(26, 0);

        for(int i = 0; i<n; ++i){
            getline(cin, str);
            first_char_counts[str[0]-'a']++;

        }

        long long output = 0;
        
        for(int i = 0; i<26; ++i){
            int count = first_char_counts[i]/2;
            int count2 = count;
            if(first_char_counts[i]%2){
                count2++;
            }
            long long comb = (count*(count-1))/2;
            long long comb2 = (count2*(count2-1))/2;
            output+=comb + comb2;
        }

        cout<<output<<endl;
}