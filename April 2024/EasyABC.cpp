#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

pair<int, int> directions[8] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
vector<string>lines;
string smallest_string; 

void dfs(int x1, int y1, int x2, int y2, string current){

    if(current.size() == 1){
        //cout<<"starting loop for : "<<x1<<" "<<y1<<endl;
        for(auto& dir: directions){
            int new_x = x1+dir.first;
            int new_y = y1+dir.second;
            
            if(new_x < 0 || new_x == 3 || new_y <0 ||new_y == 3 || (new_x == x1 && new_y == y1)){
                continue;
            }

            string new_string = current+lines[new_x][new_y];
            //cout<<"new string : "<<new_string<<" | added : "<<new_x<<" "<<new_y<<endl;
            
            dfs(x1, y1, new_x, new_y, new_string);
        }

    }else{
        //equal to 2
        //cout<<"starting loop for : "<<x1<<" "<<y1<<" and "<<x2<<" "<<y2<<endl;
        for(auto& dir: directions){
            int new_x = x2+dir.first;
            int new_y = y2+dir.second;
            
            if(new_x < 0 || new_x == 3 || new_y <0 ||new_y == 3 || (new_x == x1 && new_y == y1) || (new_x == x2  && new_y == y2)){
                continue;
            }

            string new_string = current+lines[new_x][new_y];
            //cout<<"new string : "<<new_string<<" | added : "<<new_x<<" "<<new_y<<endl;
            smallest_string = min(smallest_string, new_string);
        }
    }

}
int main(){
    lines.clear();
    string line1; getline (cin,line1);
    lines.push_back(line1);
    string line2; getline (cin,line2);
    lines.push_back(line2);
    string line3; getline (cin,line3);
    lines.push_back(line3);

    smallest_string=line1;

    for(int i = 0; i<3; ++i){
        for(int j = 0; j<3; ++j){
            if(smallest_string[0] >= lines[i][j]){
                string new_string = "";
                new_string+=lines[i][j];
                dfs(i, j, -1, -1, new_string);
            }
        }
    }
    cout<<smallest_string<<endl;

}