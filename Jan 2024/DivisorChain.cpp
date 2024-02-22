#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;

//A helper function which lets us know if a bit is set provided a mask 
bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_cases;
    cin>>test_cases;

    while(test_cases--){
        int number;
        cin>>number;

        int power_2;
        vector<int> ans;

        //we start the chain with the current number
        ans.push_back(number);

        //reduce number to 2L
        //start from the least significant bit which is the 1s spot
        for (int i = 0; ; ++i) {
            if (bit(number, i)) {
                if (number == (1 << i)) {
                    power_2 = i;
                    break;
                }
                //We subtrack a divisor from the number, then we add the new number to the series
                number -= (1 << i);
                ans.push_back(number);
            }
        }

        //reduce 2L to 1
        while (power_2 > 0) {
            number -= (1 << (power_2 - 1));
            ans.push_back(number);
            --power_2;
        }

        cout << size(ans) << "\n";
        for (int y : ans) {
            cout << y << " ";
        }
        cout << "\n";


    }

}