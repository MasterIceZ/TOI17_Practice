/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: String Partition
 * ALGO		: Greedy
 * DATE		: 12 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int mp[111];

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	unordered_set<int> st;
	for(int i=1; i<n; ++i){
		if(n % i == 0){
			st.insert(i);
		}
	}
	int ans = 1e9 + 10, current;
	for(auto x: st){
		int current_answer = 0;
		for(int stp=0; stp<x; ++stp){
			current = 0;
			for(int i=stp; i<n; i+=x){
				mp[s[i] - 'a']++;
				current = max(current, mp[s[i] - 'a']);
			}
			current_answer += (n / x) - current;
			memset(mp, 0, sizeof mp);
		}
		ans = min(ans, current_answer);
	}
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
