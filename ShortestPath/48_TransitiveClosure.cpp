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

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

void solve(){
	int n;
	cin >> n;
	vector<vector<int>> dp(n + 1, vector<int> (n + 1));
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> dp[i][j];
		}
	}
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				dp[i][j] |= dp[i][k] & dp[k][j];
			}
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
//		cout << endl;
	}
	return 0;
}
