#include <iostream>
#include <vector>
#include <algorithm>  
#include <unordered_map>
#include <unordered_set>
using namespace std;
//cound't solveCode
int main()
{

    int number_test_cases;
    cin>>number_test_cases;

    for(int i = 0; i<number_test_cases; ++i){

        int number_of_nodes;
        cin>>number_of_nodes;
        
        string directions="";
        cin>>directions;

        //adjcancy dict with weighted edges
        unordered_map<int, vector<int>> adj_dict;
        unordered_map<int, pair<int, int>> edge_costs;
        unordered_set<int> leaf_nodes;

        //root node value is 1
        for(int j = 1; j<=number_of_nodes; ++j){
            int left;
            int right;
            cin>>left>>right;

            if(left == 0 && right == 0){
                leaf_nodes.insert(j);
            }else { 
                
                if (left != 0){
                    adj_dict[j].push_back(left);
                    if(directions[j] == 'L'){
                        edge_costs[j].first = 0;
                    }else{
                        edge_costs[j].first = 1;
                    }
                }

                if (right != 0){
                    adj_dict[j].push_back(right);

                    if(directions[j] == 'R'){
                        edge_costs[j].second = 0;
                    }else{
                        edge_costs[j].second = 1;
                    }
                }
            }

            
        }

        //dfs

    }



}