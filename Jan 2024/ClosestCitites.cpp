#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;

//closest city costs 1 coin, but every other city costs the distance. So Floyd Wharshall

/*void solve(){
    int number_of_integers;
    cin>>number_of_integers;

    vector<int> cities;

    for(int i = 0; i<number_of_integers; ++i){
        int city;
        cin>>city;
        cities.push_back(city);
    }

    vector< vector<int>> dist(number_of_integers, vector<int>(number_of_integers, 0));

    for(int i = 0; i<number_of_integers; ++i){
        for(int j = 0; j<number_of_integers; ++j){

            if(i == 0 && j == 1){
                dist[i][j] = 1;

            }
            else if(i == number_of_integers-1 && j == number_of_integers-2){
                dist[i][j] = 1;
            }
            else if(i+1 == j){
                if(abs(cities[i] - cities[j]) < abs(cities[i] - cities[i-1])){
                    dist[i][j] = 1;
                }else{
                    dist[i][j] = abs(cities[i] - cities[j]);
                }

            }
            else if(i-1 == j){
                if(abs(cities[i] - cities[j]) < abs(cities[i] - cities[i+1])){
                    dist[i][j] = 1;
                }else{
                    dist[i][j] = abs(cities[i] - cities[j]);
                }
            }
            else{
                dist[i][j] = abs(cities[i] - cities[j]);

            }

        }
    }

    //FLoyd Warshall
    for(int i = 0; i<number_of_integers; ++i){
        //bool change_made=false;
        for(int j = 0; j<number_of_integers; ++j){
            for(int k = 0; k<number_of_integers; ++k){
                if (dist[i][j] + dist[j][k]<dist[i][k]){
                    dist[i][k] = dist[i][j] + dist[j][k];
                    //hange_made = true;
                }
            }
        }
        //if(change_made == false){
        //    break;
       // }

    }

    //Floyd Warhsall not needed because it is a line

    int number_of_queries;
    cin>>number_of_queries;
    while(number_of_queries--){
        int i;
        int j;
        cin>>i>>j;
        //Querries are 1 indexed but our array is 0 indexed
        cout<<dist[i-1][j-1]<<endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int number_of_test_cases;
    cin>>number_of_test_cases;

    while(number_of_test_cases--){
        solve();

        
    }

}*/

#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;

void solve(){
    int number_of_integers;
    cin>>number_of_integers;

    vector<int> cities;

    for(int i = 0; i<number_of_integers; ++i){
        int city;
        cin>>city;
        cities.push_back(city);
    }

    vector<int> moving_right;
    moving_right.push_back(0);
    moving_right.push_back(1);
    int rolling_sum = 1;

    for(int i = 1; i<number_of_integers-1; ++i){
        if(abs(cities[i] - cities[i+1]) < abs(cities[i] - cities[i-1])){
            rolling_sum+=1;
            moving_right.push_back(rolling_sum);
        }else{
            rolling_sum+=cities[i+1] - cities[i];
            moving_right.push_back(rolling_sum);
        }

    }

    vector<int> moving_left;
    moving_left.push_back(0);
    moving_left.push_back(1);
    int rolling_total = 1;

    for(int i = number_of_integers-2; i>0; --i){
        if(abs(cities[i] - cities[i-1]) < abs(cities[i] - cities[i+1])){
            rolling_total+=1;
            moving_left.push_back(rolling_total);
        }else{
            rolling_total+=abs(cities[i-1] - cities[i]);
            moving_left.push_back(rolling_total);
        }

    }
    reverse(moving_left.begin(), moving_left.end());
    /*cout<<"Moving Left"<<endl;
    for(auto elem : moving_left){
        cout<<elem<<" ";
    }
    cout<<endl;*/

    int number_of_queries;
    cin>>number_of_queries;
    while(number_of_queries--){
        int i;
        int j;
        cin>>i>>j;
        
        if(i < j){
            cout<<moving_right[j-1]-moving_right[i-1]<<endl;

        }else{
            //0 in moving left is distance from end to there
            cout<<moving_left[j-1] - moving_left[i-1]<<endl;

        }
    }



}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int number_of_test_cases;
    cin>>number_of_test_cases;

    while(number_of_test_cases--){
        solve();

        
    }

}

