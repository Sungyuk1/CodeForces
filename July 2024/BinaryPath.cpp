#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

void solve(){
    int n; cin >> n;
    string row[2];
    cin >> row[0] >> row[1];
    string ans="";
    ans+=row[0][0]; // push the first position (1,1)

    // Find the shortest (lex) path
    int turn;   // index in which it goes downward
    bool done = false;  // has already gone downward?

    for (int i=0; i<n; ++i) {
        if (!done && i == n-1) { // hit only if we get to pos (1,n)
            ans+=row[1][n-1];
            turn = n-1;
            continue;
        }
 
        if (row[0][i+1] == '1' && row[1][i] == '0' && !done) {
            //since we want the lexi smallest, go down the first chance that going down will let us
            //add a smaller digit to our answer. If they are both the same, stay on the higher row
            //so that we still keep the option of moving down
            done = true;
            ans+=row[1][i];
            turn = i;
        } else {
            if (done) ans+=row[1][i]; //if we already move down, all we can do is move right
            else ans+=row[0][i+1]; //Move right if moving down does not give us a smaller string
        }
    }

    cout << ans << '\n';

    // Count paths
    //To count how many path of the same type are there, startig from the point in wich it goes 
    //downward, we increment a counter until the char in position (1,i) == (2,i-1), for each
    //decrementing i. This means that turning down before we did wouldn't have modified the path.

    int num = 1;
    for (int i=turn; i>0; --i) {
        if (row[0][i] == row[1][i-1]) ++num;
        else break;
    }
 
    cout << num << '\n';
}


//take first zero
/*void solve(){
    int n; cin>>n; 
    string row1; cin>>row1; 
    string row2; cin>>row2; 

    int counter = 1; 
    int current_row = 1; 
    string min_string = ""; 
    min_string+=row1[0];

    for(int i = 0; i<n; ++i){
        if(current_row == 2){
            min_string+=row2[i];
        }else if(i == n-1){
            min_string+=row2.back();
        }else if(row1[i+1] > row2[i]){
            //cout<<"Moving Down"<<endl; 
            current_row =2;
            i--;
        }else if(row1[i+1] < row2[i]){
            //cout<<"reseting counter"<<endl; 
            min_string+=row1[i+1];
            counter = 1; 
        }else if(row1[i+1] == row2[i]){
            min_string+=row1[i+1];
            counter++; 
            //cout<<"Counter incremented cause equal"<<endl; 
        }
    }

    cout<<min_string<<endl; 
    cout<<counter<<endl; 

}*/

/*void solve(){
    int n; cin>>n; 
    string row1; cin>>row1; 
    string row2; cin>>row2; 

    //iterate and check what the val of the string would be if we made the downward jump here
    string lexi_smallest = row1.substr(0, 1) + row2; 
    int lexi_smallest_count = 1; 
    string current_row1 = row1;
    string current_row2 = row2.back();
    for(int i = n-2; i>=0; --i){
        current_row2= row2[i] + current_row2;
        current_row1.pop_back();

        string current_string = current_row1 + current_row2;
        //cout<<"index : "<<i<<endl; 
        //cout<<"current string : "<<current_string<<endl;

        if(current_string < lexi_smallest){
            lexi_smallest = current_string;
            lexi_smallest_count = 1; 
        }else if(current_string == lexi_smallest){
            lexi_smallest_count++;
        }
    }
    cout<<lexi_smallest<<endl; 
    cout<<lexi_smallest_count<<endl; 

}*/

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}