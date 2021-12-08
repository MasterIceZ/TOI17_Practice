#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MxN = 200200;
ll a[MxN];

void solve(){
	ll n, m;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> a[i];
	}
	ll l = 1, r = 1e18;
	while(l < r){
		ll mid = (l + r) >> 1, cnt = 0;
		for(int i=1; i<=m; i++){
			cnt += a[i] / mid;
			cnt += (a[i] % mid != 0);
		}
//		cerr << mid << " " << cnt << " J\n";
		if(cnt > n){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	cout << (r == 1e18 ? -1: r);
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
