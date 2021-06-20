/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Matrix Chain Mul
 * ALGO		: Dynamic Programming
 * DATE		: 15 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int dp[12][12], path[12][12];
int row[12], col[12];

int divide(int l, int r){
	if(l == r){
		return 0;
	}
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	int nin = INT_MAX;
	for(int k=l; k<r; ++k){
		int now = divide(l, k) + divide(k+1, r) + row[l] * col[k] * col[r];
		if(now < nin){
			nin = now;
			path[l][r] = k;		
		}
	}
	return dp[l][r] = nin;
}

void divide2(int l, int r){
	if(l == r){
		cout << "A" << l+1;
		return ;
	}
	cout << "(";
	divide2(l, path[l][r]);
	cout << " x ";
	divide2(path[l][r]+1, r);
	cout << ")";
}

void solve(){
	memset(dp, -1, sizeof dp);
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> row[i] >> col[i];
	}
	cout << divide(0, n-1) << endl;
	divide2(0, n-1);
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
