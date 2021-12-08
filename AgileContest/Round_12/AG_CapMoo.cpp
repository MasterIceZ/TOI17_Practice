/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Cap Moo
 * ALGO		: String Matching, Math
 * DATE		: 6 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int mp[100];

void solve2(){
	string s, k, now;
	cin >> s;
	int n = s.size();
	unordered_set<int> st;
	for(int i=1; i<n; ++i){
		if(n % i == 0){
			st.insert(i);
		}
	}
	int ans = 1e9 + 10, cur;
//	unordered_map<char, int> mp;
	for(auto x: st){
		int now_ans = 0;
		for(int stp=0; stp<x; ++stp){
			cur = 0;
			for(int i=stp; i<n; i+=x){
				mp[s[i] - 'a']++;
				cur = max(cur, mp[s[i] - 'a']);
			}
			now_ans += (n / x) - cur;
//			mp.clear();
			memset(mp, 0, sizeof mp);
		}
		ans = min(ans, now_ans);
	}
	cout << ans;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
//		solve();
		solve2();
		cout << "\n";
	}
	return 0;
}
