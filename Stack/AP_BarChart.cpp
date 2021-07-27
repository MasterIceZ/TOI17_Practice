/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Bar Chart
 * ALGO		: Stack
 * DATE		: 21 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll dpl[100100], dpr[100100], h[100100];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> h[i];
		dpl[i] = i - 1;
		while(dpl[i] > 0 && h[dpl[i]] >= h[i]){
			dpl[i] = dpl[dpl[i]];
		}
	}
	for(int i=n; i>=1; --i){
		dpr[i] = i + 1;
		while(dpr[i] <= n && h[dpr[i]] >= h[i]){
			dpr[i] = dpr[dpr[i]];
		}
	}
	ll ans = 0;
	for(int i=1; i<=n; ++i){
		ans = max(ans, (dpr[i] - dpl[i] - 1) * h[i]);
	}
	cout << ans;
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
