#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <stdio.h>
#include <cstring>

using namespace std;

void solve()
{
 
}

int main(){
    int t; cin>>t;

    while(t--){
        string s; cin>>s;
        vector<int>counter(26, 0);
        int char_count = 0; 

        for(auto c: s){
            if(counter[c-'a'] == 0){
                char_count++;
            }

            counter[c-'a']++;
        }

        if(char_count<2){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl; 

            for(int i = 1; i<s.size(); ++i){
                if(s[i] != s[0]){
                    char temp = s[i];
                    s[i] = s[0];
                    s[0] = temp;
                    break;
                }
            }
            //cout<<"yes ans : "<< s<<endl; 
            cout<<s<<endl; 
        }
        
    }

}