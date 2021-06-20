/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: MCM
 * ALGO		: Dynamic Programming
 * DATE		: 14 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int n, row[12], col[12], dp[12][12], path[12][12];

int divide(int l, int r){
	if(l == r){
		return dp[l][r] = 0;
	}
	if(dp[l][r] != -1){
		return dp[l][r];
	}	
	int nin = INT_MAX;
	for(int i=l; i<r; ++i){
		int now = divide(l, i) + divide(i+1, r) + row[l] * col[i] * col[r];
		if(now < nin || dp[l][r] == -1){
			nin = now;
			path[l][r] = i;
		}
	}
	return dp[l][r];
}

void solve(){
	memset(dp, -1, sizeof dp);
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> row[i] >> col[i];
	}
	cout << divide(0, n-1);
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
