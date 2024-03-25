#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;
//add 1 to k, or add a decimal multiple of x
//note x*10^0 is just x
int main(){
    int t; cin>>t;

    while(t--){
        int x, y; cin>>x>>y;

        //get largest x that is bigger than y
        int current_number = 0;
        int largest_x = x;
        int op_count = 0;
        while(largest_x<y){
            largest_x = largest_x*10;
        }
        //cout<<"largest x ("<<x<<") for y("<<y<<") : " <<largest_x<<endl;       
        while(current_number<y){
            if(current_number + largest_x > y){
                largest_x= largest_x/10;
                if(largest_x == 0 || largest_x<x){
                    break;
                }
            }else{
                current_number+=largest_x;
                //cout<<"Adding "<<largest_x<<" | new current_number : "<<current_number<<endl;
                op_count++;
            }
        }
        op_count+=y-current_number;
        cout<<op_count<<endl;
        //cout<<"-------"<<endl;


    }

}