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
#include <cstring>

using namespace std;

string line1, line2, line3; 
vector<string>board; 

bool hasWon(char symbol){
    //check vertical
    for(int i = 0; i<3; ++i){
        if(board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol){
            return true; 
        }
    }

    //check horizontal
    for(int i = 0; i<3; ++i){
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol){
            return true; 
        }
    }

    //check diagonals
    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol){
        return true; 
    }
    if(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol){
        return true; 
    }

    return false; 
}

//brute force
//handle case of multiple wins
void solve(){
    cin>>line1>>line2>>line3; 
    board.clear(); 
    board.push_back(line1);
    board.push_back(line2);
    board.push_back(line3);
    
    int win_count = 0; 
    bool plus_won = false;
    bool x_won = false;
    bool o_won = false; 

    if(hasWon('+')){
        plus_won = true; 
        win_count++;
    }
    
    if(hasWon('X')){
        x_won = true; 
        win_count++;
    }
    
    if(hasWon('O')){
        o_won=true;  
        win_count++;
    }

    if(win_count != 1){
        cout<<"DRAW"<<endl; 
        return; 
    }

    if(plus_won){
        cout<<"+"<<endl; 
    }else if(x_won){
        cout<<"X"<<endl; 
    }else{
        cout<<"O"<<endl; 
    }
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}