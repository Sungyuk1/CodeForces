#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

/*void solve(vector<string>& output){
    int number_of_glasses;
        cin>>number_of_glasses;

        unordered_set<long long> total_seen;
        total_seen.insert(0);

        long long running_sum = 0;
        bool yes = false;


        //Do Prefix sum while cin input so we have O(n) not O(2n)

        for(int j = 0; j<number_of_glasses; ++j){
            int glass;
            cin>>glass;
            
            //flip even
            if(j%2 == 1){
                running_sum+=(-1* glass);
            }else{
                running_sum+=glass;
            }

            if(total_seen.find(running_sum) != total_seen.end()){
                yes = true;
                break;
            }else{
                total_seen.insert(running_sum);
            }


        }

        if(yes == true){
            output.push_back("YES");
        }else{
            output.push_back("NO");
        }
}

int main()
{
    int number_of_test_cases;
    cin>>number_of_test_cases;
    vector<string> output;

    for(int i = 0; i<number_of_test_cases; ++i){
        solve(output);
    }

    for(auto a: output){
        cout<<a<<endl;
    }

}*/

//Can't do sliding window because no guarantee that making the window smaller will decrease the sum, and that making the window bigger will increase the sum 
//C++ unordered_set causes tle. Must use map

#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    map<ll, ll> m;
    ll s = 0;
    m[0] = 1;
    for(int i = 0; i < n; ++i) {
        a[i] *= ((i % 2) ? -1 : 1);
        s += a[i];
        if(m[s]) {
            cout << "YES\n";
            return;
        }
        ++m[s];
    }
    cout << "NO\n";
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}