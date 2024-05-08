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
        vector<int>a(n);
        vector<int>b(n);

        for(int i = 0; i<n; ++i){
            cin>>a[i];
        }  
        for(int i = 0; i<n; ++i){
            cin>>b[i];
        }  

        if(n==1){
            if(a[0] == b[0]){
                cout<<2<<endl; 
            }else{
                cout<<1<<endl;
            }
            continue;
        }

        vector<int> freq_a(n + n+1);
        vector<int> freq_b(n + n+1);

        //calculate the longest subarray of equal elements in a
        int equalSubarrayStart = 0;
        for (int i = 1; i <n; ++i)
        {
            if (a[i] != a[i - 1])
            {
                //max subarray in a with equal elem of value a[i-1] is max of current subarray and previous maximum
                freq_a[a[i - 1]] = max(freq_a[a[i - 1]], i - equalSubarrayStart);
                equalSubarrayStart = i;
            }
        }
        freq_a[a[n-1]] = max(freq_a[a[n-1]], n - equalSubarrayStart);

        equalSubarrayStart = 0;
        for (int i = 1; i <n; ++i)
        {
            if (b[i] != b[i - 1])
            {
                freq_b[b[i - 1]] = max(freq_b[b[i - 1]], i - equalSubarrayStart);
                equalSubarrayStart = i;
            }
        }
        freq_b[b[n-1]] = max(freq_b[b[n-1]], n - equalSubarrayStart);


        int ans = 0;
        //elements range from 1 to 2*n
        for (int i = 1; i < freq_a.size(); ++i)
        {   //cout<<"num : "<<i<<" | freq_a : "<<freq_a[i]<<" | freq_b : "<<freq_b[i]<<endl;  
            ans = max(ans, freq_a[i] + freq_b[i]);
        }

        //cout << "ans : "<<ans << '\n';
        cout<<ans<<endl; 


        



    }

}