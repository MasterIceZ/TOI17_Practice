#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int dp[3][333], have[666], cz[3][333];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> dp[0][i];
		have[dp[0][i]] = true;
		cz[0][i] = cz[0][i - 1] + (dp[0][i] == 0);
		dp[0][i] += dp[0][i - 1];
	}
	for(int i=1; i<=n; ++i){
		cin >> dp[1][i];
		have[dp[1][i]] = true;
		cz[1][i] = cz[1][i - 1] + (dp[1][i] == 0);
		dp[1][i] += dp[1][i - 1];
	}
	vector<int> qsz;
	qsz.push_back(0);
	for(int i=2*n; i>=1; --i){
		if(!have[i]){
			qsz.push_back(qsz.back() + i);
		}
	}
	int ans = 0;
	for(int i=1; i<=n; ++i){
		ans = max(ans, dp[0][i] + dp[1][n] - dp[1][i - 1] + qsz[cz[0][i] + cz[1][n] - cz[1][i - 1]]);
	}
	cout << ans << "\n";
	return 0;
}
