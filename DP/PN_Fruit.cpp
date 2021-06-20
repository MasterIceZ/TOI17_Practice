/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Fruit
 * ALGO		: Dynamic Programming
 * DATE		: 17 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll dp[100100], v[100100];

void solve(){
	memset(dp, 0, sizeof dp);
	memset(v, 0, sizeof v);
	ll n;
	cin >> n;
	for(ll i=1; i<=n; ++i){
		cin >> v[i];
		v[i] += v[i-1];
	}
	ll sz = 0;
	for(ll i=1; i<=n; ++i){
		if(v[i] <= 0){
			continue;
		}
		ll idx = lower_bound(dp, dp + sz, v[i]) - dp;
		dp[idx] = v[i];
		if(idx == sz){
			sz++;
		}
	}
	cout << 1+sz;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
