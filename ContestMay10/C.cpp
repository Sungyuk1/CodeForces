#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <stdio.h>
#include <cstring>

using namespace std;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
    //we create an empty string. Then iterate from 1-12. If i == a or i== b we add R
    //to the string for red. If i == c or i == d we add B to the string for blue
    //Then we check if the string creates an iterweaving of the chars R and B
	string s;
	for (int i = 1; i <= 12; i++) {
		if (i == a || i == b) {s += "R";}
		if (i == c || i == d) {s += "B";}
	}
	cout << (s == "RBRB" || s == "BRBR" ? "YES\n" : "NO\n");
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }

}