/*
 * AUTHOR	: Hydrolyzed~
 * TASK		:
 * CENTER	: RYW
 * DATE		: 26 Jun 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;

const int MxN = 77;
int dp[MxN][MxN*MxN + 2];

void solve(){
	memset(dp, 0, sizeof dp);
	int k, l;
	cin >> n >> k >> l;
	l = min(l, n*n);
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		for(int j=min(i, k); j>=1; --j){
			for(int w = i-j; w<=l; ++w){
				dp[j][w] = max(dp[j][w], x + dp[j-1][w + j - i]);
			}
		}
	}
	int nax = 0;
	for(int i=0; i<=l; ++i){
		nax = max(nax, dp[k][i]);
	}
	cout << nax;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
