/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: RO
 * ALGO		: Dynamic Programming
 * DATE		: 24 Nov 2021
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
	int n, k;
	ll cur = 0;
	string s;
	cin >> n >> k >> s;
	s = " " + s;
	int rr = 0, oo = 0;
	for(int i=1; i<=n; ++i){
		rr += (s[i] == 'R');
		oo += (s[i] == 'O');
	}
	if(oo % rr == 0 && oo / rr == k){
		cout << n;
		return ;
	}
	int res = 0;
	unordered_map<ll, int> mp;
	for(int i=1; i<=n; ++i){
		if(s[i] == 'R'){
			cur -= k;
		}
		else{
			cur += 1;
		}
		if(mp[cur]){
			res = max(res, i - mp[cur]);
		}	
		else{
			mp[cur] = i;
		}
	}
	cout << res;
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
