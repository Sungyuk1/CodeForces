#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//note n and m are small, only up to 200. We also get 2 full seconds
//try brute force, but can easily memo
int n, m;
vector<vector<long long>>board(200, vector<long long>(200, 0));
vector<vector<vector<long long>>> memo; //x, y, direction -> sum of values going in that direction for that cell

int dfs(int x, int y, int dir){
    if(x<0 || x >= n || y<0 || y>=m){
        return 0;
    }

    /*if(memo[x][y][dir] != -1){
        //cout<<"memo hit"<<endl;
        return memo[x][y][dir];
    }*/

    if(dir == 0){
        //memo[x][y][dir] = board[x][y] + dfs(x-1, y-1, dir);
        //return memo[x][y][dir];
        return board[x][y] + dfs(x-1, y-1, dir);
    }else if(dir == 1){
        //memo[x][y][dir] = board[x][y] + dfs(x-1, y+1, dir);
        //return memo[x][y][dir];
        return board[x][y] + dfs(x-1, y+1, dir);
    }else if(dir == 2){
        //memo[x][y][dir] = board[x][y] + dfs(x+1, y-1, dir);
        //return memo[x][y][dir];
        return board[x][y] + dfs(x+1, y-1, dir);
    }else{
        //3
        //memo[x][y][dir] = board[x][y] + dfs(x+1, y+1, dir);
        //return memo[x][y][dir];
        return board[x][y] + dfs(x+1, y+1, dir);
    }
    //return memo[x][y][dir];


}
int main(){
    int t; cin>>t;

    while(t--){
        cin>>n>>m;
        //board.clear();
        //memo = vector<vector<vector<long long>>>(200, vector<vector<long long>>(200, vector<long long>(4, -1)));

        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                long long temp; cin>>temp;
                board[i][j] = temp; 
            }
        }

        long long res = 0;

        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                long long sum_current = board[i][j] + dfs(i-1, j-1, 0) + dfs(i-1, j+1, 1) + dfs(i+1, j-1, 2) + dfs(i+1, j+1, 3);
                res = max(res, sum_current);
            }
        }

        cout<<res<<endl; 

        //cout<<"done"<<endl; 

        


    }

}