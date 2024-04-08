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
        int n; cin>>n;
        vector<int> array;
        long long count = 0;
        
        for(int i = 0; i<n; ++i){
            int temp; cin>>temp;
            array.push_back(temp);
        }

        bool impossible = false;

        for(int i = n-1; i>0; --i){
            while(array[i] <= array[i-1]){
                array[i-1] = array[i-1]/2;
                count++;
                if(array[i] == 0 && array[i-1] == 0){
                    impossible=true;
                    break;
                }
            }
            if(impossible){
                break;
            }
        }

        if(impossible){
            cout<<-1<<endl;
        }else{
            cout<<count<<endl;
        }
    }

}