#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MxN = 100100;

int n;
ll lmin[MxN], lmax[MxN], rmin[MxN], rmax[MxN];
pair<ll, ll> p[MxN];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> p[i].first >>p[i].second;
	}
	sort(p + 1, p + n + 1);
	lmin[0] = rmin[n + 1] = 1e18;
	lmax[0] = rmax[n + 1] = -1e18;
	for(int i=1; i<=n; ++i){
		ll now = -p[i].first + p[i].second;
		lmax[i] = max(lmax[i - 1], now);
		lmin[i] = min(lmin[i - 1], now);
	}
	for(int i=n; i>=1; --i){
		ll now = p[i].first + p[i].second;
		rmax[i] = max(rmax[i + 1], now);
		rmin[i] = min(rmin[i + 1], now);
	}
	while(q--){
		ll x;
		cin >> x;
		int idx = upper_bound(p + 1, p + n + 1, make_pair(x, (ll)1e9)) - (p + 1);
		cout << min(x + lmin[idx], -x + rmin[idx + 1]) << " ";
		cout << max(x + lmax[idx], -x + rmax[idx + 1]);
		cout << "\n";
	}
	return 0;
}
