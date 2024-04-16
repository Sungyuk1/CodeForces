#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//Longest range of consequtive factors
int main(){
    int t; cin>>t;

    while(t--){
        string x, y;
        cin>>x>>y;

        if(x<y){
            swap(x, y);
        }else if(x == y){
            cout<<x<<endl; 
            cout<<y<<endl;
            continue;
        }

        int pointer = 0;
        while(y[pointer] == x[pointer]){
            pointer++;
        }
        pointer++;
        int n = x.size();

        while(pointer<n){
            if(y[pointer] < x[pointer]){
                swap(y[pointer], x[pointer]);
            }
            pointer++; 
        }

        cout<<x<<endl; 
        cout<<y<<endl; 

    }

}