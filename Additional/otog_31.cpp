#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	int n, i;
	cin >> n;
	ll ans = 0, x, y, z, a;
	for(i=1; 4 + i<=n; i+=4){
		cin >> x >> y >> z >> a;
		ans += x + y + z + a;
		ans -= min({x, y, z, a});
	}
	for(; i<=n; ++i){
		cin >> x;
		ans += x;
	}
	cout << ans;
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
