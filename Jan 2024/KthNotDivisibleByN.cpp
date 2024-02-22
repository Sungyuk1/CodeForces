#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int number_of_test_cases;
    cin>>number_of_test_cases;
    vector<int> outputs;

    for(int i = 0; i<number_of_test_cases; ++i){
        int n;
        int k;
        cin>>n>>k;

        if(n > k){
            outputs.push_back(k);
        }
        else if (n == k){
            outputs.push_back(k+1);
        }
        else{//2 3
            int current_num = (k/(n-1))*n; //6
            int remaining_spots = k%(n-1);

            if(remaining_spots != 0){
                current_num+=remaining_spots;
            }else{
                current_num-=1;
            }

            /*while(remaining_spots > 0){
                current_num++;
                if(current_num%n != 0){
                    remaining_spots--;
                }
            }*/
            if(k%n == 0){
                outputs.push_back(current_num);
            }
            else{
                outputs.push_back(current_num);
            }
        }

    }

    for(auto num: outputs){
        cout<<num<<endl;
    }



    return 0; 

}