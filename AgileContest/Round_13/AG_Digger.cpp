/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

ll dp[5][1010][1010];

void solve(){
	int n, k;
	cin >> n >> k;
	for(int x=1; x<=3; ++x){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				cin >> dp[x][i][j];
				dp[x][i][j] += dp[x][i - 1][j] + dp[x][i][j - 1] - dp[x][i - 1][j - 1]; 
			}
		}	
	}
	ll ans = 0;
	for(int i=k; i<=n; ++i){
		for(int j=k; j<=n; ++j){
			ll mine1, mine2, mine3;
			mine1 = mine2 = mine3 = 0;
			for(int x=i; x<=i+k-1; ++x){
				for(int y=j; y<=j+k-1; ++y){
					dbg(x, y, x - k, y - k);
					mine1 = max(mine1, dp[1][x][y] - dp[1][x - k][y] - dp[1][x][y - k] + dp[1][x - k][y - k]);
					mine2 = max(mine2, dp[2][x][y] - dp[2][x - k][y] - dp[2][x][y - k] + dp[2][x - k][y - k]);
					mine3 = max(mine3, dp[3][x][y] - dp[3][x - k][y] - dp[3][x][y - k] + dp[3][x - k][y - k]);
				}
			}
			ans = max(ans, mine1 + mine2 + mine3);
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
		cout << "\n";
	}
	return 0;
}
