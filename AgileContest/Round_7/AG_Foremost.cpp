/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Foremost
 * ALGO		:
 * DATE		: 9 Oct 2021
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

const int MxN = 200200;
int a[MxN];

void solve(){
	int n, k;
	cin >> n >> k;
	assert(n == k);
	unordered_map<int, int> mp;
	ll sum = 0;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		mp[a[i]] += 1;
		sum += a[i];
	}
	ll ans = 1e9;
	for(auto x: mp){
		ll cnt = 0;
		cnt = sum - (x.first * x.second) - (n - x.second);
		dbg(x.first, cnt);
		ans = min(ans, cnt);
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
