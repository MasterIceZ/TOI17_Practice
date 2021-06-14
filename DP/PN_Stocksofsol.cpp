/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Cards
 * ALGO		: Dynamic Programming
 * DATE		: 13 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int dpl[1000100], dpr[1000100];

void solve(){
	memset(dpl, 0, sizeof dpl);
	memset(dpr, 0, sizeof dpr);
	int n;
	cin >> n;
	vector<int>v(n+1);
	for(int i=1; i<=n; ++i){
		cin >> v[i];
	}
	int nin = v[1];
	for(int i=2; i<n; ++i){
		dpl[i] = max(dpl[i-1], v[i] - nin);
		nin = min(nin, v[i]);
	}
	int nax = v[n];
	for(int i=n-1; i>1; --i){
		dpr[i] = max(dpr[i+1], nax - v[i]);
		nax = max(nax, v[i]);
	}
	int ans = 0;
	for(int i=1; i<n; ++i){
		ans = max(ans, dpl[i] + dpr[i+1]);
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
