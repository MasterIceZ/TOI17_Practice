/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: RT_Hire Friend
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

void solve(){
	ll n;
	cin >> n;
	map<ll, ll> mp;
	for(ll i=1, s, e; i<=n; ++i){
		cin >> s >> e;
		mp[s]++, mp[e + 1]--;
	}
	ll amt = 0, sum = 0, last = 0;
	for(auto x: mp){
		if(sum > 1){
			amt += (sum - 1) * (x.first - last);
		}
		sum += x.second;
		last = x.first;
	}
	cout << amt;
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
