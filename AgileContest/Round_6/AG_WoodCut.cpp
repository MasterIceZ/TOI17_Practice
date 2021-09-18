/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Wood Cut
 * ALGO		: Dynamic Programming 
 * DATE		: 18 Sep 2021
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

const ll MOD = 1e9 + 7;
ll a[100100], qs[100100];

void solve(){
	int l, r;
	cin >> l >> r;
	ll sum = 0;
	for(int i=l; i<=r; ++i){
		sum += (((MOD + qs[i] - qs[i - 1]) % MOD) * ((MOD + qs[r] - qs[i]) % MOD)) % MOD;
		sum %= MOD;
	}
	cout << sum;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q = 1;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		qs[i] += qs[i - 1] + a[i];
		qs[i] %= MOD;
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
