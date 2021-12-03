#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll a[100100];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	ll l = 0, r = 1e18;
	while(l < r){
		ll mid = (l + r) >> 1;
		ll sum = 0;
		for(int i=1; i<=n; ++i){
			sum += mid / a[i];
		}
		if(sum >= m){
			r = mid;
		}
		if(sum < m){
			l = mid + 1;
		}
	}
	cout << l;
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
