/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 48_Beads
 * ALGO		: Dynamic Programming
 * DATE		: 15 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int a[111], dp[111][111][3];

int divide(int l, int r){
	if(l == r){
		dp[l][r][1] = a[l];
		return 0;
	}
	if(dp[l][r][1] != -1){
		return dp[l][r][0];
	}
	int nin = INT_MAX;
	for(int k=l; k<r; ++k){
		int now = divide(l, k) + divide(k+1, r) + dp[l][k][1] * dp[k+1][r][1];
		if(now < nin){
			nin = now;
			dp[l][r][1] = (dp[l][k][1] + dp[k+1][r][1]) % 100;
		}
	}
	return dp[l][r][0] = nin;
}

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	cout << divide(1, n);
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
