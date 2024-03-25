#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>

using namespace std;

//you can swap elements that are k indices apart
//Find maximum difference betwen index and value at index
//find cycle sizes
int main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        int result = 0;
        for(int i = 1; i<=n; ++i){
            int temp; cin>>temp;
            result = gcd(result, abs(temp - i));

        }

        cout<<result<<endl;
    }

}