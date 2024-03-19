#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

//given three numbers, check if we can make them all equal with 3 splits
int main(){
    int t;cin>>t;

    while(t--){
        int a, b, c; cin>>a>>b>>c;

        //If the lengths of the threadlets are equal, the answer is yes
        if(a == b && b==c){
            cout<<"YES"<<endl;
            continue;
        }
        
        vector<int> lengths;
        lengths.push_back(a);
        lengths.push_back(b);
        lengths.push_back(c);
        sort(lengths.begin(), lengths.end());
        
        if(lengths[1]%lengths[0] != 0 || lengths[2]%lengths[0] != 0){
            cout<<"NO"<<endl;
            continue;
        }

        if((lengths[1]/lengths[0]) + (lengths[2]/lengths[0]) -2 <= 3){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }



        //If we cut the shortest, we only have 2 operations left. If all 3 of the 
        //threadlets are not the same length, we cannot make them all equal with 2 
        //operations

        //if b or c is not divisible by a, the anser is no. Otherwise, we do 
        //division to see how many times a divides into both b and c. If the total number is
        //less than or equal to 3, we have yes

        

    }

}