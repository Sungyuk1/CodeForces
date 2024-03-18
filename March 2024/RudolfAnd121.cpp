#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

//A operation reduces 2 from element i, and reduces 1 from both neighbors
//The ends cannot be choosen as the elements
//We want to reduce the array to zero

//idea 1 : always take away from the largest element? Maybe largest odd/even?

void solve(vector<int>& arr, int&n){
    for(int i = 0; i<n-2; ++i){
        if(arr[i] < 0){
            cout<<"NO"<<endl;
            return;
        }
        int op = arr[i];
        arr[i]-=op;
        arr[i+1]-= 2*op;
        arr[i+2]-=op;
    }

    if(arr[n-1] != 0 || arr[n-2] != 0){
        cout<<"NO"<<endl;
        return;
    }else{
        cout<<"YES"<<endl;
        return;
    }

}
int main(){
    int t;cin>>t;

    while(t--){
        int n; cin>>n;
        vector<int> arr;

        for(int i = 0; i<n; ++i){
            int temp; cin>>temp;
            arr.push_back(temp);
        }

        solve(arr, n);

    }
}