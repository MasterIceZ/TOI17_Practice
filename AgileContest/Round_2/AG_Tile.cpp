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

struct Node{
	int v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;

char a[3][5050];
int dp[3][5050];

const int MOD = 1e9 + 7;

void solve(){
	cin >> n;
	memset(dp, 0, sizeof dp);
	for(int i=1; i<=2; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	dp[1][0] = dp[2][0] = 1;
	for(int i=1; i<=n; ++i){
		if(a[1][i] == '.' && a[2][i] == '.'){
			dp[1][i] = dp[1][i-1] + dp[2][i-1];
			dp[1][i] %= MOD;
			dp[2][i] = dp[1][i];
		}
		else if(a[1][i] == '#' && a[2][i] == '.'){
			dp[2][i] = dp[2][i-1];
			dp[2][i] %= MOD;
			dp[1][i] = 0;
		}
		else if(a[1][i] == '.' && a[2][i] == '#'){
			dp[1][i] = dp[1][i-1];
			dp[1][i] %= MOD;
			dp[2][i] = 0;
		}
		else{
			dp[1][i] = dp[0][i] = 0;
		}
//		cout << "(" << dp[1][i] << ", " << dp[2][i] << ")" << endl;
	}
	cout << (dp[2][n] + dp[1][n])%MOD ; 
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
