#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[555][555], qs[555][555];
const ll MOD = 1e9 + 7;

void solve(){
	ll n, h;
	cin >> n >> h;
	if(h > n){
		cout << 0;
	}
	cout << (qs[n][n] - qs[n][h - 1] + MOD) % MOD;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	ll le, ri;
	dp[0][0] = 1, qs[0][0] = 1;
	for(int i=1; i<=400; ++i){
		qs[0][i] = 1;
	}
	for(int i=1; i<=400; ++i){
		for(int j=1; j<=i; ++j){
			for(int k=1; k<=i; ++k){
				le = dp[k - 1][j - 1];
				ri = qs[i - k][min(i - k, j - 1)];
				dp[i][j] = (dp[i][j] + (le * ri) % MOD) % MOD;
				if(j == 1){
					continue;
				}
				le = qs[k - 1][min(k - 1, j - 2)];
				ri = dp[i - k][j - 1];
				dp[i][j] = (dp[i][j] + (le * ri) % MOD) % MOD;
			}
			qs[i][j] = (dp[i][j] + qs[i][j - 1]) % MOD;
		}
	}
	int q;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
