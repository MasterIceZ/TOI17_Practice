/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PZ_Camera
 * ALGO		: Two-Pointers, Math
 * DATE		: 9 Nov 2021
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

const ll MAX = 1000100;
const int MxN = 100100;
ll a[MxN], mp[MAX + 10], mkr[MAX + 10];
ll dp[MxN], qs[MxN];

void solve(){
	for(ll i=1; i<=MAX; ++i){
		if(mp[i]){
			continue;
		}
		for(ll j=1; i*j*j<=MAX; ++j){
			mp[j*j*i] = i;
		}
	}
	int n, q;
	ll k;
	cin >> n >> q >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		a[i] = mp[a[i]];
	}
	int j = 0, cnt = 0;
	for(int i=1; i<=n; ++i){
		while(j <= n && cnt < k){
			j += 1;
			mkr[a[j]] += 1;
			if(mkr[a[j]] == 1){
				cnt++;
			}
		}
		dp[i] = j;
		mkr[a[i]] -= 1;
		if(!mkr[a[i]]){
			cnt--;
		}
	}
	for(int i=1; i<=n; ++i){
		qs[i] += qs[i - 1] + dp[i];
	}
	dbg(to_vector(dp, 1, n));
	while(q--){
		int l, r;
		cin >> l >> r;
		ll idx = upper_bound(dp + 1, dp + n + 1, r) - (dp +	1);
		if(idx < l){
			cout << 0 << "\n";
			continue;
		}
		ll ans = (r + 1) * (idx - l + 1) - (qs[idx] - qs[l - 1]);
		cout << ans << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
