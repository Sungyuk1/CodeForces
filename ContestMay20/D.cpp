#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

void solve(){
    long long n; cin>>n; 
    string s; cin>>s;

    long long N_count = 0, S_count = 0, E_count = 0, W_count = 0; 
    
    for(auto c: s){
        if(c=='N'){
            N_count++;
        }else if(c=='S'){
            S_count++;
        }else if(c=='E'){
            E_count++;
        }else{
            W_count++;
        }
    }

    if(abs(N_count - S_count)%2 == 1 || abs(E_count - W_count)%2 == 1){
        //cout<<"ans : "<<"NO"<<endl; 
        cout<<"NO"<<endl; 
        return; 
    }

    long long N_1=0, N_2 = 0; 
    long long S_1=0, S_2 = 0; 
    long long E_1=0, E_2 = 0; 
    long long W_1=0, W_2 = 0; 

    if(N_count > S_count){
        S_1+=S_count;
        N_1+=S_count;
        long long rem_n = N_count-S_count;
        N_1+=rem_n/2;
        N_2+=rem_n/2;

        if(N_1 > 1 && S_1 >1){
           S_1--;
           N_1--;
           N_2++;
           S_2++; 
        }
    }else{
        N_1+=N_count;
        S_1+=N_count;
        long long rem_s = S_count-N_count;
        S_1+=rem_s/2;
        S_2+=rem_s/2;

        if(S_count > 1 && N_count >1){
           S_1--;
           N_1--;
           N_2++;
           S_2++; 
        }
    }

    if(E_count > W_count){
        W_1+=W_count;
        E_1+=W_count;
        long long rem_e = E_count-W_count;
        E_1+=rem_e/2;
        E_2+=rem_e/2;

        if(E_1 > 0 && W_1>0 && N_2 == 0 && S_2 == 0){
           E_1--;
           W_1--;
           E_2++;
           W_2++; 
        }

    }else{
        E_1+=E_count;
        W_1+=E_count;
        long long rem_w = W_count-E_count;
        W_1+=rem_w/2;
        W_2+=rem_w/2;

        if(E_1 > 0 && W_1>0 && N_2 == 0 && S_2 == 0){
           E_1--;
           W_1--;
           E_2++;
           W_2++; 
        }
    }

    //cout<<"num ops R : "<<N_1 + S_1 + E_1 + W_1<<endl; 
    //cout<<"num ops H : "<<N_2 +S_2 +E_2 + W_2<<endl; 
    if(N_1 + S_1 + E_1 + W_1 == 0 || N_2 +S_2 +E_2 + W_2 == 0){
        //cout<<"ans : NO"<<endl; 
        cout<<"NO"<<endl; 
        return; 
    }

    string output = "";
    for(auto c: s){
        if(c=='N'){
            if(N_1){
                N_1--;
                output+='R';
            }else{
                N_2--;
                output+='H';
            }
        }else if(c=='S'){
            if(S_1){
                S_1--;
                output+='R';
            }else{
                S_2--;
                output+='H';
            }
        }else if(c=='E'){
            if(E_1){
                E_1--;
                output+='R';
            }else{
                E_2--;
                output+='H';
            }
        }else{
            if(W_1){
                W_1--;
                output+='R';
            }else{
                W_2--;
                output+='H';
            }
        }
    }

    //cout<<"ans : "<<output<<endl; 
    cout<<output<<endl; 

}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}