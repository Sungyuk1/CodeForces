#include <iostream>
#include <vector>
#include <algorithm>  
#include <map>
#include <unordered_map>
using namespace std;

//A helper function which lets us know if a bit is set provided a mask 
bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main(){
    int number_of_tests;
    cin>>number_of_tests;

    while(number_of_tests--){
        int array_length;
        cin>>array_length;

        //the vector stores the numbers we have so we can iterate through the map. 
        vector<int> array_numbers;
        //map<int, int> counter;
        
        unordered_map<int, int> counter;


        for(int i = 0; i<array_length; ++i){

            int number_of_bits;
            cin>>number_of_bits;
            int number = 0;
            for(int j = 0; j<number_of_bits; j++){
                int temp;
                cin>>temp;
                number+=pow(2, temp);
                //counter[temp]++;
            }
            while
        }

        bool hasUnique = false;
        for(auto elem : counter){
            if(elem.second == 1){
                cout<<"This turns it true : "<<elem.first<<endl;
                hasUnique = true;
                break;
            }
        }

        if(hasUnique){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }



    

        //If there are of the same numbers answer should always be true;
        //2 and 2 2 have the same bits set after the bitwise or

        //for each line the first is the number of set bits, and the rest are which bits are set. 
    }

}