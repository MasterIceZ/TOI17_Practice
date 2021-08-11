/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Pick Two Sequences
 * ALGO		: Dynamic Programming
 * DATE		: 11 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int a[100100], dpl[100100], dpr[100100];

void solve(){
	int n, nax, ans = -1e9, qs;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	nax = -1e9, qs = 0;
	for(int i=1; i<=n; ++i){
		qs = max(qs + a[i], 0);
		nax = max(nax, qs);
		dpl[i] = nax;
	}
	nax = -1e9, qs = 0;
	for(int i=n; i>=1; --i){
		qs = max(qs + a[i], 0);
		nax = max(nax, qs);
		dpr[i] = nax;
	}
	for(int i=1; i<=n; ++i){
		ans = max(ans, dpl[i] + dpr[i + 1]);
	}
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		memset(dpl, 0, sizeof dpl);
		memset(dpr, 0, sizeof dpr);
		solve();
		cout << endl;
	}
	return 0;
}
