/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Magnet
 * ALGO		: Sweepline
 * DATE		: 11 Sep 2021
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

vector<ll> line;
ll n;

void solve(){
	ll x;
	cin >> x;
	if(x < line[0]){
		cout << line[0] - 1;
	}
	else if(x >= line.back()){
		cout << n - line.back() + 1;
	}
	else{ 
		int idx = upper_bound(all(line), x) - line.begin();
		cout << line[idx] - line[idx - 1];
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	map<ll, ll> mp;
	ll l, s, m, q;
	cin >> n >> m >> q;
	for(ll i=1; i<=m; ++i){
		cin >> l >> s;
		mp[l]++, mp[l + s]++;
	}
	for(auto x: mp){
		if(x.second % 2){
			line.push_back(x.first);
		}
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
