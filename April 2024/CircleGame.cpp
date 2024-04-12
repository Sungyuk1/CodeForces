#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        vector<int> circle;
        int smallest_index = 0;

        for(int i = 0; i<n; ++i){
            int temp; cin>>temp; 
            circle.push_back(temp);
            if(temp<circle[smallest_index]){
                smallest_index = i; 
            }
        }

        if(n%2 == 1){
            cout<<"Mike"<<endl;
            continue;
        }

        if (smallest_index % 2 == 0) cout << "Joe\n";
        else cout << "Mike\n";


        

    }

}