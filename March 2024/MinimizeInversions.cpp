#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        //create array of pairs
        pair<int, int> ab[n];

        for(int i = 0;i < n;++i)
        {
            cin >> ab[i].first;
        }
        for(int i = 0;i < n;++i)
        {
            cin >> ab[i].second;
        }
        //sort array. 
        sort(ab,ab+n);
        for(int i = 0;i < n;++i)
        {
            cout << ab[i].first << ' ';
        }
        cout << "\n";
        for(int i = 0;i < n;++i)
        {
            cout << ab[i].second << ' ';
        }
        cout << "\n";



    }

}