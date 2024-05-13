#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <array>
#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;

    //1) You made an error in the contest where you set location and arrival time to size k istead of k+1
    //you for got to add locatation[0] = 0 and arrival_times[0] = 0
    vector<long long> location(k+1), arrival_times(k+1);
    location[0] = 0;
    arrival_times[0] = 0;
    for(int i = 1; i <= k; i++)
    {
        cin >> location[i];
    }
    for(int i = 1; i <= k; i++)
    {
        cin >> arrival_times[i];
    }

    for(int i = 0; i < q; i++)
    {
        long long query; cin >> query;
        int l = 0, r = k;

        //1) For each query, we binary search to find the last sign we passed (since the array a is sorted).
        while(l <= r){
            int mid = (l+r)>>1; 
            if(location[mid] > query){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        //2) If the last sign we passed is equal to our current location, return the arrival time of the
        //   last sign
        if(location[r] == query){
            cout << arrival_times[r] << " ";
            continue;
        }
        //3) You don't need floating numbers. Made mistake during contest of using floating numbers
        //long long speed_at_current_loc = (arrival_times[r+1]-arrival_times[r])/(location[r+1]-location[r]);
        //long long distance_travelled_from_last_sign = query-location[r];
        //long long ans = arrival_times[r] + (distance_travelled_from_last_sign*speed_at_current_loc);

        //4) To avoid using floating numbers multiply everything first before the division
        //   So multiply the distance travelled past the sign with the differences of the arrival time of the two
        //   signs used to calculate the speed before dividing by the differences in the location of the two signs
        //   used to calculate speed
        long long ans = arrival_times[r] + (query-location[r])*(arrival_times[r+1]-arrival_times[r])/(location[r+1]-location[r]);
        cout << ans << " ";
    }
    cout << endl;
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }

}