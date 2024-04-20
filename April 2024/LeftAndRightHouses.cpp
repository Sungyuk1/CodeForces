#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <math.h> 

using namespace std;

//each index must differ between a and b
//sumnation of a and b must be equal

//Maybe make sure that we have at least n/2 unique numbers
int main(){
    int t; cin>>t;

    while(t--){
        long long n; cin>>n;
        string houses; cin>>houses;

        long long total_right = 0; 
        for(auto c: houses){
            if(c == '1'){
                total_right++;
            }
        }

        long long rolling_right = 0; 
        int min_index = -1; 

        long long left_happy = 0;
        long long right_happy = total_right;

        if(ceil((n)/2.0) <= right_happy){
            min_index = 0; 
        }

        for(int i = 1; i<=n; ++i){
            if(houses[i-1] == '1'){
                rolling_right++;
            }
            
            left_happy = i - rolling_right;
            right_happy = total_right - rolling_right;

            /*cout<<"index : "<<i<<endl; 
            cout<<"left happy : "<<left_happy<<endl; 
            cout<<"left happy minimum requirement : "<<ceil(i/2.0)<<endl; 
            cout<<"right happy : "<<right_happy<<endl; 
            cout<<"right happy minimum requirement : "<<ceil((n-i)/2.0)<<endl; */
            

            if(ceil(i/2.0) <= left_happy && ceil((n-i)/2.0) <= right_happy){
                //cout<<"Found valid index at "<<i<<endl; 
                if(min_index < 0){
                    min_index = i; 
                }else{
                    double current_mid_dist = abs(n/2.0 - min_index);
                    //cout<<"current mid dist : "<<current_mid_dist<<endl;
                    double new_mid_dist = abs(n/2.0 - i);
                    //cout<<"new mid dist : "<<new_mid_dist<<endl; 
                    if(current_mid_dist > new_mid_dist){
                        min_index = i; 
                    }
                }

            }
            //cout<<"---------"<<endl; 
            //cout<<" "<<endl; 
        }
        cout<<min_index<<endl; 

    }

}