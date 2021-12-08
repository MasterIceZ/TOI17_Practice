/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Really
 * ALGO		: Counting Sort, Math 
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

ll a[100100], bucket[100100];
ll rs[100100];

void solve2(){
	ll n, k;
	cin >> n >> k;
	ll sum = 0;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		bucket[a[i]] = i;
	}
	vector<ll> jumps;
	jumps.push_back(0ll);
	int id = 1;
	for(int i=1; i<=n; ++i){
		ll now = (bucket[i] - bucket[a[id]] + n) % n;
		id = bucket[i];
		dbg(now);
		jumps.push_back(now);
		sum += now;
	}
	jumps[0] = (bucket[1] - bucket[a[id]] + n) % n;
	dbg(jumps);
	rs[1] = jumps[1];
	for(int i=2; i<=n; ++i){
		rs[i] = rs[i - 1] + jumps[i];
	}
	ll ans = 0;
	if(k <= n){
		cout << rs[k];
		return ;
	}
	jumps[1] = jumps[0];
	rs[1] = jumps[1];
	for(int i=2; i<=n; ++i){
		rs[i] = rs[i - 1] + jumps[i];
	}
	ans = sum + rs[n] * ((k - n )/ n) + rs[k % n];
	cout << ans;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
//		solve();
		solve2();
		cout << "\n";
	}
	return 0;
}
