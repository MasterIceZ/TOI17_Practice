/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: dnafactory
 * ALGO		: Sweepline
 * DATE		: 13 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

void solve(){
	int n, m;
	map<int, int> mp;
	cin >> n >> m;
	for(int i=1, s, e; i<=m; ++i){
		cin >> s >> e;
		mp[s]++, mp[e + 1]--;
	}
	int ans = 0, sum = 0;
	for(auto x: mp){
		dbg(x.first, x.second);
		sum += x.second;
		ans = max(ans, sum);
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
