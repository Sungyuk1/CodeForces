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
        long long n; cin>>n;
        int count = INT_MAX;

        string N = to_string(n);

        if(n%25 == 0){
            cout<<"0"<<endl;
            continue;
        }
        
        for(int i = 0; i<N.size(); ++i){
            for(int j = i+1; j<N.size(); ++j){
                string back = "";
                back+=N[i];
                back+=N[j];
                if(back=="25" || back=="50" || back=="75" || (i!= 0 && back == "00")){
                    count = min(count, (int)N.size()- j -1 +(j-i-1));
                }
            }
        }
        cout<<count<<endl;

    }

}