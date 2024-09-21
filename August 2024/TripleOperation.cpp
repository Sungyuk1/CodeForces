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

//Max value of right given constraints
const int MAX = 200'007; 

//array holding the number of divide by 3 operations to turn an index into 0 
int cost[MAX];

//prefix sums holding the rolling total of the number of operations needed
//to turn every index from 0 to i into 0 by dividing by 3. We can use this
//prefixSums as soon as we have at least 1 index equal to 0 that we can use for
//the multiplication. 
int psum[MAX];

//calculates the cost of turning an index into 0 by dividing by 3
int numberOfDiv3Operations(int x) {
	int cnt = 0;
	while (x) {
		x /= 3;
		cnt++;
	}
	return cnt;
}

void solve() {
	int l, r; cin >> l >> r;

    //turn first element into 0 -> cost[l]
    //then the second element will gain the same number of ternery digits 
    //that the first element had. So we will need remove those digits plus
    //the ternery digits that were already in the second element. This is why
    //we prefix sum starting from l-1. We need to count the ternery digits in 
    //left again.
    //Now we have a 0 that we can use for the multiplication. Because of this, 
    //the rest of the elements can just use their original costs, which the 
    //prefix sums array lets us get in O(1) time. 
	cout << psum[r] - psum[l - 1] + cost[l] << '\n';
}

int main() {
	psum[0] = 0;
	for (int i = 1; i < MAX - 1; i++) {
		cost[i] = numberOfDiv3Operations(i);
		psum[i] = psum[i - 1] + cost[i];
	}
	
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
}