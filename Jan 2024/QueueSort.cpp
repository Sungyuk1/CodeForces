#include <iostream>
#include <vector>
using namespace std;

//Can take the first element, put it in the back, and swap it with the previous one until it is either 
//the first element or stricly greater.
int main()
{
    ios_base::sync_with_stdio(0);
    int number_of_test_cases;
    cin>>number_of_test_cases;

    for(int i = 0; i<number_of_test_cases; i++){
        int array_length;
        vector<int> numbers;
        cin>>array_length;

        for(int j = 0; j<array_length; ++j){
            int temp;
            cin>>temp;
            numbers.push_back(temp);
        }

        int mini_index = 0;
        for(int j = 1; j<array_length; ++j){
            if(numbers[j] < numbers[mini_index]){
                mini_index = j;
            }
        }

        //If any part of the numbers behind the index where the min index is is not sorted, we cannot get a solution
        //Any number from the front will be added in correct position as long as the back is in ascending order. 
        bool impossible = false;
        for(int j = mini_index+1; j<array_length; ++j){
            if(numbers[j] < numbers[j-1]){
                impossible = true;
                cout<<"-1"<<endl;
                break;
            }
        }
        
        if(impossible == false){
            cout<<mini_index<<endl;
        }
    }

}