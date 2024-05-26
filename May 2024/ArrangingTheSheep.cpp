#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

void solve(){
	int n; cin >> n;
	string s;cin >> s;
	
    int cnt = 0;
	for(auto x : s)
		cnt += (x == '*' ? 1 : 0);
	
    int pos = -1; //position of the middle sheep
	int cur = -1;
    //find the middle sheep
	for(int i = 0; i < n; i++){
	 	if(s[i] == '*'){
	 	    cur++;
	 	    if(cur == cnt/2)
	 	    	pos = i;
	 	}	
	}

	long long ans = 0;
	cur = pos - cnt / 2; //position of the first sheep - 
	for(int i = 0; i < n; i++)
		if(s[i] == '*'){
		 	ans += abs(cur - i); //abs(position of the first sheep )
		 	cur++;
		}
	cout << ans << endl;
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
        
    }

}

/*
void solve(){
    int n; cin>>n; 
    string s; cin>>s;
    vector<pair<char, int>>stack;
    for(auto c: s){
        if(stack.empty()){
            stack.push_back({c, 1});
        }else if(stack.back().first == c){
            stack.back().second++;
        }else{
            stack.push_back({c, 1});
        }
    }

    //if all empty or all sheep
    if(stack.size() == 1){
        cout<<0<<endl; 
        return;
    }

    if(stack.back().first == '.'){
        stack.pop_back();
    }
    int start_index = 0; 
    if(stack[0].first == '.'){
        start_index++;
    }

    long long ans_forwards = 0; 

    for(int i = start_index; i<stack.size()-1; i+=2){
        ans_forwards+=(stack[i].second * stack[i+1].second);
    }

    long long ans_backwards = 0; 

    for(int i = stack.size()-1; i>start_index+1; i-=2){
        ans_backwards+=(stack[i].second * stack[i-1].second);
    }

    cout<<min(ans_forwards, ans_backwards)<<endl; 


}*/