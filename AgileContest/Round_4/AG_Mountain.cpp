/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Mountain
 * ALGO		: Math
 * DATE		: 14 Aug 2021
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

const ll MxN = 1e6;
const ll MOD = 2e6 + 3;
ll fac[2 * MxN + 12], inV[MOD + 2];

ll inverse(ll n){
	if(n == 0){
		return 0;
	}
	for(ll i=0; i<MOD; ++i){
		if((i * n) % MOD == 1){
			return i;
		}
	}
}

ll cat(int n){
	ll ret = fac[2 * n];
	ll inv = inverse((fac[n] * fac[n]) % MOD);
//	ll inv = inV[(fac[n] * fac[n]) % MOD];
	ret *= inv;
	ret %= MOD;
	inv = inverse((n + 1) % MOD);
//	inv = inV[(n + 1) % MOD];
	ret *= inv;
	ret %= MOD;
	return ret;
}

void solve(){
	ll n, q;
	cin >> n >> q;
	ll catalan = cat(n);
//	dbg(catalan, fac[n]);
	if(q == 0){
		cout << catalan;
	}
	else{
		cout << (fac[n] - catalan  + MOD ) % MOD;
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	
	fac[0] = 1;
	for(ll i=1; i<=2 * MxN; ++i){
		fac[i] = fac[i - 1] * i;
		fac[i] %= MOD;
	}
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
