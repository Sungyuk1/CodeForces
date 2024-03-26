#include <iostream>
#include <vector>
#include <algorithm>  
#include <unordered_set>
#include <numeric>

using namespace std;

//given three numbers, check if we can make them all equal with 3 splits
int main(){
    int t;cin>>t;

    while(t--){
        long long max_bomb_timer_value, inital_bomb_time, num_tools;
        cin>>max_bomb_timer_value>>inital_bomb_time>>num_tools;
        long long total = inital_bomb_time;

        //each tool can be used once
        //vector<int> tools;
        for(int i = 0; i<num_tools; ++i){
            long long temp; cin>>temp;
            if(temp >= max_bomb_timer_value){
                total+=max_bomb_timer_value;
                total-=1;
            }else{
                total+=temp;
            }
            //tools.push_back(temp);
        }

        //sort(tools.begin(), tools.end());
        //int N = tools.size();

        cout<<total<<endl;

        //return the maximum time in seconds until the bomb explodes
    }

    //can't simulate gotta do math solution


}

/*
Bad TLE simulation approach

sort(tools.begin(), tools.end());
        int N = tools.size();
        int pointer_left = 0;
        int pointer_right = N-1;
        int count = 0; 
        int current_time = inital_bomb_time;

        while(current_time > 0){
            count++;
            if(pointer_left<=pointer_right && current_time == 1){
                //last second use biggest possible
                //cout<<"Value of tool used : "<<tools[pointer_right]<<endl;
                current_time = min(current_time + tools[pointer_right], max_bomb_timer_value);
                pointer_right--;
                //cout<<"New current_time : "<<current_time<<endl;
            }
            else if(pointer_left<=pointer_right && current_time + tools[pointer_left] <= max_bomb_timer_value){
                //cout<<"Value of tool used : "<<tools[pointer_left]<<endl;
                current_time = min(current_time + tools[pointer_left], max_bomb_timer_value);
                pointer_left++;
                //cout<<"New current_time : "<<current_time<<endl;
            }
            current_time--;
            //cout<<"current_time at the end of the turn : "<<current_time<<endl;
            //cout<<"----------"<<endl;
        }
        cout<<count<<endl;

        //return the maximum time in seconds until the bomb explodes
    }
*/
