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
    long long n, m; cin>>n>>m;

    vector<long long>number_of_rooms(n);
    vector<long long>prefixSumRoomNumber(n+1);
    prefixSumRoomNumber[0] = 0;
    for(int i = 0; i<n; ++i){
        cin>>number_of_rooms[i];
        prefixSumRoomNumber[i+1] = number_of_rooms[i] + prefixSumRoomNumber[i];
    }

    long long current_index = 1; 
    for(int i =0; i<m; ++i){
        long long room_number; cin>>room_number;
        //bin search? In order though so sequencial might be fine
        while(room_number > prefixSumRoomNumber[current_index]){
            current_index++;
        }

        cout<<current_index<<" "<<room_number-prefixSumRoomNumber[current_index-1]<<endl; 
    }


}

int main(){
    solve();
}