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

int a[3030], dp[3030][3030];

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<k; ++i){
		dp[i][0] = a[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=i-1; j>=max(1, i- k + 1); --j){
			int minn = 1e9 + 10;
//			for(int l=max(0, i - k); l<j; ++l){
//				minn = min(minn, dp[j][l] + a[i]);
//			}
			dp[i][j] = dp[j][max(0, i - k)] + a[i];
			if(j != i - 1){
				dp[i][j] = min(dp[i][j], dp[i][j + 1]);
			}
		}
	}
//	for(int i=0; i<=n; ++i){
//		for(int j=0; j<=n; ++j){
//			cout << dp[i][j] << " ";
//		}
//		cout << "\n";
//	}
	int ans = 1e9 + 10;
	for(int i = n - k + 2; i<=n; ++i){
		for(int j = n - k + 1; j<i; ++j){
			ans = min(dp[i][j], ans);
		}
	}
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
