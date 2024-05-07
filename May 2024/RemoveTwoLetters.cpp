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

        long long count = n-1; //abc = a, c
        for(int i = 1; i+1<n; ++i){
            if(s[i-1] == s[i+1]){
                count--;
            }
        }

        cout<<count<<endl; 


        
    }

}

/*
//memory limit exceeded
while(t--){
        int n; cin>>n;
        string s; cin>>s; 

        unordered_set<string>string_set; 

        for(int i = 0; i<n-1; ++i){
            //string new_string = s.substr(0, i) + s.substr(i+2);
            //cout<<"new string : "<<new_string<<endl; 
            string_set.insert(s.substr(0, i) + s.substr(i+2));
        }

        //cout<<"ans : "<<string_set.size()<<endl; 
        cout<<string_set.size()<<endl; 
    }*/