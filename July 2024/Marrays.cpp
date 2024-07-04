#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cmath>

using namespace std;

void solve(){
    int n, m; cin>>n>>m; 
    vector<int>a(n); 
    for(int i = 0; i<n; ++i){
        cin>>a[i];
    }
    unordered_map<int, int> mods; 
    for(auto num: a){
        mods[num%m]++;
    }

    int number_of_groups = 0; 

    if(mods.contains(0)){
        number_of_groups++;
        mods.erase(0);
        //cout<<"m in array. Group all M multiples together. num groups : "<<number_of_groups<<endl; 
    }
    //note cant change mods while iterarteing
    unordered_set<int>visited; 

    for(auto & p: mods){
        if(visited.contains(p.first)){
            continue; 
        }
        //cout<<" "<<endl; 
        //cout<<"current mod : "<<p.first<<endl; 
        if(mods.contains(m-p.first)){
            //cout<<"found matching mod : "<<m-p.first<<endl; 
            if(m-p.first == p.first){
                number_of_groups++;
                //mods.erase(p.first);
                visited.insert(p.first);
                //cout<<"matching mods are the same. Put all in same group. Num groups : "<<number_of_groups<<endl; 
            }else{
                //calculate difference in count of the two numbers
                int diff = abs(p.second - mods[m-p.first]);
                //cout<<"occurences of "<<p.first<<" : "<<p.second<<endl; 
                //cout<<"occurences of "<<m-p.first<<" : "<<mods[m-p.first]<<endl; 
                //cout<<"difference between occurences : "<<diff<<endl; 
                if(diff > 1){
                    //left overs need to be put in their own group
                    number_of_groups+=diff -1; 
                    //cout<<"Put left Over matches in own group. Number of groups : "<<number_of_groups<<endl; 
                }
                number_of_groups++;
                //cout<<"Put matches into same group : "<<number_of_groups<<endl; 
                //mods.erase(p.first);
                //mods.erase(m-p.first);
                visited.insert(p.first);
                visited.insert(m-p.first);
            }
        }else{
            //no valid pairs
            number_of_groups+=p.second;
            //cout<<"No matching mods. Put everything in own group. Number of groups : "<<number_of_groups<<endl; 
            //mods.erase(p.first);
            visited.insert(p.first);
        }
    }
    cout<<number_of_groups<<endl; 

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}