#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int main(){
    int t;cin>>t;

    while(t--){
        long long num_messages, initial_charge, cost_time, cost_power;
        cin>>num_messages>>initial_charge>>cost_time>>cost_power;

        vector<long long> m;
        for(int i = 0; i<num_messages; ++i){
            long long temp; cin>>temp;
            m.push_back(temp);
        }
        long long current_charge = initial_charge;

        if(m[0] != 0){
            long long cost_on = cost_time * (m[0]);
            //cout<<"cost on : "<<cost_on<<endl;
            if(cost_on > cost_power){
                current_charge-=cost_power;
            }else{
                current_charge-=cost_on;
            }
        }
        //cout<<"current charge : "<<current_charge<<endl;

        for(int i = 0; i<num_messages-1; ++i){
            if(current_charge<=0){
                break;
            }

            long long cost_on = cost_time * (m[i+1] - m[i]);
            if(cost_on > cost_power){
                current_charge-=cost_power;
            }else{
                current_charge-=cost_on;
            }
            //cout<<"current charge : "<<current_charge<<endl;
        }
        //need power to be greater than zero for the last message
        if(current_charge<=0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }

}