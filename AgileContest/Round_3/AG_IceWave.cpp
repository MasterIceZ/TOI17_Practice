#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

const int offset = 20000;

ll dp[2][2 * offset + 1], ans;

void query(){
	ans = 0;
	int n;
	cin >> n;
	memset(dp, 0, sizeof dp);
	dp[0][offset] = 1;
	for(int i=1, num; i<=n; ++i){
		cin >> num;
		int now = i&1, nex = (i&1)^1;
		fill(dp[now], dp[now] + 2 * offset + 1, 0);
		for(int j=0; j<=2*offset; ++j){
			if(j + num <= 2 * offset){
				dp[now][j + num] += dp[nex][j];
				dp[now][j + num] %= MOD;
			}
			if(j - num >= 0){
				dp[now][j - num] += dp[nex][j];
				dp[now][j - num] %= MOD;
			}
		}
		ans += dp[now][offset];
		ans %= MOD;
		dp[now][offset]++;
		dp[now][offset] %= MOD;
	}
	cout << ans;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		query();
		cout << "\n";
	}	
	return 0;
}
