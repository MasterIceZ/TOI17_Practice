#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

ll a[22];

ll inverse(ll a, ll b){
	if(b == 0){
		return 1 % MOD;
	}
	if(b == 1){
		return a % MOD;
	}
	ll tmp = inverse(a, b / 2);
	ll res = (tmp * tmp) % MOD;
	if(b & 1){
		res = (res * a) % MOD;
	}
	return res;
}

ll choose(ll n, ll r){
	ll res = 1, div = 1;
	for(int i=n-r+1; i<=n; ++i){
		res *= i;
		res %= MOD;
	}
	for(int i=1; i<=r; ++i){
		div *= (i % MOD);
		div %= MOD;
	}
	res *= inverse(div, MOD-2);
	res %= MOD;
	return res;
}

void solve(){
	ll n, s, sum = 0;
	scanf("%lld %lld", &n, &s);
	for(int i=0; i<n; ++i){
		scanf("%lld", &a[i]);
	}
	for(int i=0; i<(1<<n); ++i){
		ll now = s;
		for(int j=0; j<n; ++j){
			if((1 << j) & i){
				now -= (a[j] + 1);
			}
		}
		if(now < 0){
			continue;
		}
		if(__builtin_popcount(i) & 1){
			sum -= choose(now + n - 1, n - 1);
		}
		else{
			sum += choose(now + n - 1, n - 1);
		}
		sum %= MOD;
		sum += MOD;
		sum %= MOD;
	}
	printf("%lld\n", (sum + MOD) % MOD);
}

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		solve();
	}
	return 0;
}
