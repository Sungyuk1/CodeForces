#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

long long n, current_diff, x, operation_count, min_operations=1e9, a[100005];

int main() {
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];

    //1) create every possible starting common difference
	for(int i = -1; i<=1; i++){
        for(int j = -1; j<=1; j++) {
            
            current_diff = a[1] + j - a[0] - i;
            operation_count = abs(i); //if we reduce the start number by 1 or increase by 1 that is an operation

            //Now iterate through the sequence and check if we can get a valid arithmetic progression
            int k;
            for(k = 1; k<n; k++) {
                //current first element + (current_diff*num elementx)
                x = abs(a[k] - ((a[0]+i) + (k*current_diff)));

                //if the value at k is different from the kth progression by more than 1,
                //then such an arithmetic progression is unreachable
                if(x>1) break;

                operation_count += x;
            }
            if(k==n){
                min_operations = min(min_operations, operation_count);
            } 
	    }
    }
	cout<<(min_operations<1e9 ? min_operations:-1)<<endl;
}