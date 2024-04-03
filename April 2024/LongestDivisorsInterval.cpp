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
        unsigned long long n; cin>>n;

        int x = 1;
        int interval_size = 0;
        while(x<=n && n%x == 0){
            x++;
            interval_size++;
        }

        cout<<interval_size<<endl;

    }

}