#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool solve(vector<int>& a, int n){
    for(int i = n-1; i>0; --i){
        if(a[i-1] > a[i]){
            vector<int> digits; 
            int num = a[i-1];

            while(num){
                int digit = num%10;
                if(!digits.empty() && digit > digits.back()){
                    return false;
                }
                digits.push_back(digit);
                num= num/10; 
            }
            int last = digits.back();
            //cout<<"last digit : "<<digits.back()<<endl;
            //cout<<"first digit : "<<digits[0]<<endl;
            if(digits[0] > a[i]){
                return false;
            }else{
                a[i-1] = digits.back();
            }
        }
    }
    return true; 

}

//Longest range of consequtive factors
int main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        vector<int> a; 

        for(int i = 0; i<n; ++i){
            int temp; cin>>temp; 
            a.push_back(temp);
        }
        bool res = solve(a, n); 

        if(res){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }

}