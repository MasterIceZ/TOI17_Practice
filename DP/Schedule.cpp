/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Schedule TOI8
 * ALGO		: Dynamic Programming
 * DATE		: 13 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int k, a[1010], b[1010];
pair<int, int> dp[1010][1010];

pair<int, int> operator + (const pair<int, int> A, const pair<int, int> B){
	if(A.second + B.second > k){
		return make_pair(A.first + 1, B.second);
	}
	return make_pair(A.first, A.second + B.second);
}

void solve(){
	int n;
	cin >> k >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int j=1; j<=n; ++j){
		cin >> b[j];
	}
	dp[0][0] = make_pair(1, 0);
	for(int i=1; i<=n; ++i){
		dp[i][0] = dp[i-1][0] + make_pair(0, a[i]);
		dp[0][i] = dp[0][i-1] + make_pair(0, b[i]);
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			dp[i][j] = min(dp[i][j-1] + make_pair(0, b[j]), dp[i-1][j] + make_pair(0, a[i]));
		}
	}
	cout << dp[n][n].first << endl << dp[n][n].second;
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
