/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 48_HandShake
 * ALGO		: Dynamic Programming
 * DATE		: 18 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	int n, v;
	cin >> n >> v;
	vector<pair<ll, ll>> a(n);
	for(int i=0, x, t; i<n; ++i){
		cin >> x >> t;
		a[i].first = x + v * t; //Position
		a[i].second = v * t - x; // 
	}
	sort(all(a));
	int sz = 0;
	vector<ll> dp(n+1);
	for(int i=0; i<n; ++i){
		int idx = upper_bound(dp.begin(), dp.begin() + sz, a[i].second) - dp.begin();
		if(sz == idx){
			++sz;
		}
		dp[idx] = a[i].second;
	}
	cout << sz;
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
