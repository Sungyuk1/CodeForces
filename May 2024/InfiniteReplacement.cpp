#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <cmath>

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        string s; cin>>s;
        string t; cin>>t;
        //cout<<"t : "<<t<<endl; 

        //cout<<t.find("a")<<endl; 
        //cout<<t.find('a')<<endl; 
        //out<<string::npos<<endl; 
        if(t.find("a") != string::npos) {
            //cout<<"found a in t "<<endl; 
            //check if all as
            //multiple 'a's will also cause infinity 

            if(t.size()==1){
                //just a
                cout<<1<<endl;
            }else{
                cout<<-1<<endl; 
            }
            continue; 
        }

        //2^n
        long long ans =  pow(2, s.size());
        cout<<ans<<endl; 
    }

}