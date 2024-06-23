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

//find the gaps, and pug the gaps by biggest size
void solve(){
    long long n, m; cin>>n>>m;
    vector<long long>infected(m);
    for(long long i = 0; i<m; ++i){
        cin>>infected[i];
    }
    
    if(n==m){
        cout<<m<<endl; 
        return; 
    }
    sort(infected.begin(), infected.end());

    //1) Calculate the size of all the gaps
    vector<long long>gaps; 
    //interval lengths : +1 if ends are included, -1 if ends are not included
    for(long long i = 0; i<m-1; ++i){
        gaps.push_back(infected[i+1] - infected[i] -1);
    }
    gaps.push_back(infected[0] + (n-infected.back())-1);

    sort(gaps.begin(), gaps.end());

    //2) Create state variables for the current time and the number of houses saved
    //   Since we have a circle and infections spread by 1 each unit of time, 
    //   we know that the number of uninfected houses in each gap will be 
    //   original gap size - (2*current_time)
    //   This is because a house will get infected by a house on each end of the gap each turn
    long long current_time = 0; 
    long long saved = 0; 

    //3) Greedily take the longest gap and try to save it. Stop if the infection can no longer
    //   spread or if there are no more uninfected houses. We can save a "gap" by blocking both 
    //   ends so that all the houses inside are uninfected
    while(!gaps.empty()){
        long long biggest_gap = gaps.back(); gaps.pop_back();

        biggest_gap-=(2*current_time);
        if(biggest_gap ==1){
            saved++;
            current_time++;
        }else if(biggest_gap==2){
            saved++;
            current_time++;
        }else if(biggest_gap>=3){
            saved+=biggest_gap-1;
            current_time+=2; 
        }else{
            //neg gap
            cout<<n - saved<<endl; 
            return; 
        }

    }
    cout<<n-saved<<endl;
}



int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}