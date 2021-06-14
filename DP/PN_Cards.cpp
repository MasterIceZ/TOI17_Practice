/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll dp[3][5050];
ll a[5050], b[5050];

void solve(){
	int n, m;
	memset(dp, 0, sizeof dp);
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=m; ++i){
		cin >> b[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			dp[i%2][j] = max({abs(a[i] - b[j]) + dp[(i+1) % 2][j-1], dp[i%2][j-1], dp[(i+1)%2][j]});
//			cout << dp[i%2][j] << " ";
		}
//		cout << endl;
	}
	cout << dp[n%2][m];
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
