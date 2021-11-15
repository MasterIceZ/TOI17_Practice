/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: pieces
 * ALGO		: Math
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
	int l, w, n, m, q, x, last;
	cin >> l >> w >> n >> m >> q;
	unordered_map<ll, ll> mpx, mpy;
	last = 0;
	for(int i=1; i<=n; ++i){
		cin >> x;
		mpx[x - last] += 1;
		last = x;
	}
	mpx[l - last] += 1;
	last = 0;
	for(int i=1; i<=m; ++i){
		cin >> x;
		mpy[x - last] += 1;
		last = x;
	}
	mpy[w - last] += 1;
	while(q--){
		ll a;
		cin >> a;
		ll ans = 0;
//		for(auto x: mpx){
//			if(a % x.first == 0){
//				ans += (x.second * (mpy[a / x.first]));
//			}
//		}
		for(ll i=1; i*i<=a; ++i){
			if(a % i == 0){
				ans += (mpx[i] * (mpy[a / i]));
				ans += (mpy[i] * (mpx[a / i]));
			}
		}
		ll sq = sqrt(a);
		if(sq * sq == a){
			ans -= mpx[sq] * mpy[sq];
		}
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
