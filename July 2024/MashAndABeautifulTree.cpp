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

const int MAXM = 300300;

int n, m;
int arr[MAXM];

//divide and conquor 
int solve(int l, int r) {
    //If we are down to a single element, return 0 (no need to make any more swaps)
	if (r - l == 1) return 0;

    //Get the mid point of the array.
	int mid = (l + r) >> 1;

    //Find the largest element in the left half of this section of the array
	int mal = *max_element(arr + l, arr + mid);

    //Find the largest element in the right half of this section of the array
	int mar = *max_element(arr + mid, arr + r);

    //ans is the number of node swaps we have to make
	int ans = 0;

    //If the largest element in the left half of this section is bigger than 
    //the largest element in the right half of this section, make a swap. 
    //We want all the leaf nodes to be in sorted order, so no element in the 
    //left half should be bigger than the elements in the right half
	if (mal > mar) {
		++ans;
		for (int i = 0; i < (mid - l); ++i)
			swap(arr[l + i], arr[mid + i]);
	}

    //Recursively call on the right and left halfs of the current section. 
    //This represents moving down a layer in the binary tree. 
	return solve(l, mid) + solve(mid, r) + ans;
}

void solve() {
    cin >> m;
    for (int i = 0; i < m; ++i){ cin >> arr[i]; }

	int ans = solve(0, m);

    //If the entire array is sorted after the divide and conquour approach, 
    //their is a valid answer. Otherwise, it is impossible to make the leafs sorted
    //by swapping the children of the nodes of the full binary tree. 
	if (is_sorted(arr, arr + m)){ cout<<ans<<endl;}
    else{cout<<-1<<endl;}
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}