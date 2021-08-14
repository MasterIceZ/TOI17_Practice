/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Maximum SubArray
 * ALGO		: Dynamic Programming
 * DATE		: 12 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int dp[555][555];

void solve(){
	int ans = -2e9, n, x;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> x;
			dp[i][j] = dp[i - 1][j] + x;
		}
	}
	for(int k=1; k<=n; ++k){
		for(int i=k; i<=n; ++i){
			int sm = 0;
			for(int j=1; j<=n; ++j){
				sm += dp[i][j] - dp[i - k][j];
				ans = max(ans, sm);
				sm = max(0, sm);
			}
		}
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
