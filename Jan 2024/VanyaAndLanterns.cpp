#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>  
#include <iomanip>
using namespace std;
//Compile with C++17
//g++ VanyaAndLanterns.cpp -std=c++17 

/*
Vanya walks late at night along a straight street of length l, lit by n lanterns. Consider the coordinate system with the beginning of the street corresponding to the point 0, and its end corresponding to the point l. Then the i-th lantern is at the point ai. The lantern lights all points of the street that are at the distance of at most d from it, where d is some positive number, common for all lanterns.

Vanya wonders: what is the minimum light radius d should the lanterns have to light the whole street?

Input
The first line contains two integers n, l (1 ≤ n ≤ 1000, 1 ≤ l ≤ 109) — the number of lanterns and the length of the street respectively.

The next line contains n integers ai (0 ≤ ai ≤ l). Multiple lanterns can be located at the same point. The lanterns may be located at the ends of the street.

Output
Print the minimum light radius d, needed to light the whole street. The answer will be considered correct if its absolute or relative error doesn't exceed 10 - 9.
*/

bool canCover(int & length_of_street,  vector<int> & lamp_locations, double d){
    vector<double> stree(length_of_street, 0.0);

    //create intervals and merge the intervals
    vector< pair<double, double> > intervals;
    for (int i = 0; i<lamp_locations.size(); ++i){
        double start = max(0.0, lamp_locations[i] - d);
        double end = min((double)length_of_street, lamp_locations[i] + d);
        intervals.push_back({start, end});
    }

    sort(intervals.begin(), intervals.end());

    if (intervals.front().first > 0 || intervals.back().second < length_of_street){
        //cout<<"Front Back Error"<<endl;
        //cout<<"Front : "<<intervals.front().first<<endl;
        //cout<<"Back : "<<intervals.back().second<<endl;
        //cout<<"Length of intervals : "<<intervals.size()<<endl;
        //cout<<intervals[0].first<<" "<<intervals[0].second<<endl;
        //cout<<intervals[1].first<<" "<<intervals[1].second<<endl;
        return false;
    }
    //merge all intervals
    vector< pair<double, double> > stack;
    for(int i = 0; i< intervals.size(); ++i){
        if (stack.empty()){
            stack.push_back(intervals[i]);
        }
        else if (stack.back().second >= intervals[i].first){
            stack.back().second = max(stack.back().second, intervals[i].second);
        }
        else{
            return false;
        }

    }

    return true;
}

/*int main()
{
    int number_of_lanterns;
    int length_of_street;

    cin>>number_of_lanterns>>length_of_street;

    vector<int> lamp_locations;
    int location;

    for(int i = 0; i<number_of_lanterns; ++i){
        cout<<lamp_locations.size()<<endl;
        cin>>location;
        lamp_locations.push_back(location);
    }


    cout<<"Done With Input"<<endl;
    cout<<lamp_locations.size()<<endl;
    cout<<lamp_locations.back()<<endl;

    double left = 0.0;
    double right = (double)length_of_street;
    double min_radius = 9999999.0;

    while(left < right){
        //Accidentally was doing left/right not (left+right)/2
        double mid = (left+right)/2.0;

        cout<<"Left->"<<left<<" Right->"<<right<<" Mid->"<<mid<<endl;
        bool result = canCover(length_of_street, lamp_locations, mid);
        cout<<"Result : "<<result<<" radius ->"<<mid<<endl;

        if(result == true){
            min_radius = min(min_radius, mid);
            right = mid-0.000000001;
        }else{
            left = mid+0.000000001;
            
        }
    }

    //cout<<left<<endl;
    cout<<right<<endl;
    //cout<<(left+right)/2.0<<endl;
    //cout<<"Min Radius : "<<min_radius<<endl;
    return 0;

}*/

/*Sort lanterns in non-decreasing order. Then we need to find maximal distance between two neighbour lanterns, let it be maxdist. Also we need to consider street bounds and count distances from outside lanterns to street bounds, it will be (a[0] - 0) and (l - a[n - 1]). The answer will be max(maxdist / 2, max(a[0] - 0, l - a[n - 1]))*/
int main()
{
    int number_of_lanterns;
    int length_of_street;

    cin>>number_of_lanterns>>length_of_street;

    vector<int> lamp_locations;
    int location;

    for(int i = 0; i<number_of_lanterns; ++i){
        cin>>location;
        lamp_locations.push_back(location);
    }

    sort(lamp_locations.begin(), lamp_locations.end());

    //Find max difference
    int max_diff = 0;
    for(int i = 1; i<lamp_locations.size(); ++i){
        max_diff = max(max_diff, lamp_locations[i] - lamp_locations[i-1]);
    }
    long double output = ((long double)max_diff)/2.0;
    
    //account for end bounds
    output = max(((long double)lamp_locations[0]), output);
    output = max(((long double)length_of_street-lamp_locations.back()), output);
    
    cout<<std::setprecision (10)<<output<<endl;
}
