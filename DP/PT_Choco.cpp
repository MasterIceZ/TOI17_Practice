/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_Choco
 * ALGO		: Dynamic Programming
 * DATE		: 26 Nov 2021
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

int dp[555][555];

void solve(){
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	// Add I
	for(int k=0; k<=33; ++k){
		// Add J
		for(int l=0; l<=33; ++l){
			//dp[i][j] => max(dp[i][j], dp[i - k][j - l] + 1);
			if(k == 0 && l == 0){
				continue;
			}
			for(int i=500-k; i>=0; --i){
				for(int j=500-l; j>=0; --j){
					dp[i + k][j + l] = max(dp[i + k][j + l], dp[i][j] + 1);
				}
			}
		}
	}
	int q, x, y;
	cin >> q;
	while(q--){
		cin >> x >> y;
		cout << dp[x][y] << "\n";
	}
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
