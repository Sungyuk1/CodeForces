#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(){
    //get parent by division by 2
    int t; cin>>t;

    while(t--){
        long long n; cin>>n;
        long long unsigned current_num = n;
        long long unsigned path_sum = n;

        while(current_num != 1){
            //go to parent
            current_num = current_num/2;
            path_sum+=current_num;
        }
        cout<<path_sum<<endl;
    }

}