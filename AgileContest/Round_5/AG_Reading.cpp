#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, m, qsQ[100100], qsP[100100];

void solve(){
	ll a, b, c, d, idx, k;
	scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &k);
	ll l = 0, r = 1e18;
	while(l < r){
		ll mid = (l + r) / 2;
		idx = min(c, (ll)(upper_bound(qsP + 1, qsP + n + 1, qsP[a - 1] + mid) - (qsP + 1)));
		ll idxP = idx - a + 1;
		idx = min(d, (ll)(upper_bound(qsQ + 1, qsQ + m + 1, qsQ[b - 1] + mid) - (qsQ + 1)));
		ll idxQ = idx - b + 1;
		if(idxP + idxQ < k){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	printf("%lld", l);
	return ;
}

int main(){
	int q;
	scanf("%lld %lld %d", &n, &m, &q);
	for(int i=1; i<=n; ++i){
		scanf("%lld", &qsP[i]);
		qsP[i] += qsP[i - 1];
	}
	for(int j=1; j<=m; ++j){
		scanf("%lld", &qsQ[j]);
		qsQ[j] += qsQ[j - 1];
	}
	while(q--){
		solve();
		printf("\n");
	}
	return 0;
}
