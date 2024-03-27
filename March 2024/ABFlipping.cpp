#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

//You can flip an index at most once if i = A and i+1=B
//AB = 1
//AAB -> 
int main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        int total = 0;
        int cont_A = 0;
        string s; cin>>s;

        for(int i = 0; i<n; ++i){
            if(s[i] == 'A'){
                cont_A++;
            }else{
                total+=cont_A;
                if(cont_A>0){
                    cont_A = 1;
                }
                
            }
        }

        cout<<total<<endl;

    }

}