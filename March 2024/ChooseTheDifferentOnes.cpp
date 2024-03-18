#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int main(){
    int t;cin>>t;

    while(t--){
        int n, m, k;
        cin>>n>>m>>k;

        vector<int> k_a(k, 0);

        for(int i = 0; i<n; ++i){
            int temp; cin>>temp;
            if(temp<= k && k_a[temp-1] == 0){
                k_a[temp-1] = 1;
            }
        }

        vector<int> k_b(k, 0);

        for(int i = 0; i<m; ++i){
            int temp; cin>>temp;
            if(temp <= k && k_b[temp-1] == 0){
                k_b[temp-1] = 1;
            }
        }
        int only_a = 0;
        int only_b = 0;
        int exit = false;
        for(int i = 0; i<k; ++i){
            if(k_a[i] == 0 && k_b[i] == 0){
                exit = true;
                break;
            }
            else if(k_a[i] == 1 && k_b[i] == 0){
                only_a++;
            } 
            else if(k_a[i] == 0 && k_b[i] == 1){
                only_b++;
            }
            
        }

        if(exit||only_a > k/2 || only_b > k/2){
            cout<<"NO"<<endl;
            continue;
        }else{
            cout<<"YES"<<endl;
        }
        



    }
}