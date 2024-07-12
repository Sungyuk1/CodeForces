#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

void solve(){
    int n, m, k; cin>>n>>m>>k; 
    string s; cin>>s; 
    s = "L" + s + "L";
    //cout<<"Adjusted String : "<<s<<endl; 

    int current_loc = 0; 
    n++;

    while(current_loc < n && k >= 0){
        //cout<<" "<<endl; 
        //cout<<"Current_loc : "<<current_loc<<endl; 
        //cout<<"Type at current_loc : "<<s[current_loc]<<endl; 
        //cout<<"Current k : "<<k<<endl; 

        if(s[current_loc] == 'L'){
            //find the fartest log we can jump to
            int next_jump = current_loc+1;
            if (current_loc + m >= n){
                //cout<<"Can reach land from this log "<<endl; 
                cout<<"YES"<<endl; 
                return; 
            }
            int largest_water_jump = -1; 
            for(int j = current_loc + m; j>=next_jump; --j){
                if(s[j] == 'L'){
                    next_jump = j; 
                    largest_water_jump = -1; 
                    //cout<<"Furthest log at : "<<j<<endl; 
                    break; 
                }else if(s[j] == 'W'){
                    largest_water_jump = max(largest_water_jump, j);
                }
            }
            //cout<<"No logs found in next jump area. Furthest water at : "<<largest_water_jump<<endl; 
            next_jump = max(largest_water_jump, next_jump);

            if(s[next_jump] == 'W'){
                k--;
                if(k < 0){
                    //cout<<"Swam too many times"<<endl; 
                    cout<<"NO"<<endl; 
                    return;
                }
            }
            current_loc = next_jump; 
        }else if(s[current_loc] == 'W'){
            int next_jump = current_loc+1;
            if(s[next_jump] == 'W'){
                k--;
                if(k < 0){
                    //cout<<"Swam too many times"<<endl; 
                    cout<<"NO"<<endl; 
                    return;
                }
            }
            current_loc = next_jump; 
        }else{
            //Croc
            //cout<<"hit croc"<<endl; 
            cout<<"NO"<<endl; 
            return; 
        }
    }
    if(k < 0){
        //cout<<"Cant reach land without swimming too much"<<endl; 
        cout<<"NO"<<endl; 
    }else{
        cout<<"YES"<<endl; 
    }

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}