/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Stocks
 * ALGO		: Dynamic Programming
 * DATE		: 12 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int dp[1000100][5];

void solve(){
	int n;
	cin >> n;
	dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = -1e9;
	int ans = -1e9;
	for(int i=1; i<=n; ++i){
		int x;
		cin >> x;
		dp[i][0] = max(dp[i-1][0], -x);
		dp[i][1] = max(dp[i-1][1], dp[i-1][0] + x);
		dp[i][2] = max(dp[i-1][2], dp[i-1][1] - x);
		dp[i][3] = max(dp[i-1][3], dp[i-1][2] + x);
		ans = max({ans, dp[i][0], dp[i][1], dp[i][2], dp[i][3]});	
//		cout << "DP : " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
	}
	for(int i=1; i<=n; ++i){		
		ans = max({dp[i][0], dp[i][1], dp[i][2], dp[i][3], ans});	
	}
	cout << max(ans, 0);
	memset(dp, 0, sizeof dp);
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
