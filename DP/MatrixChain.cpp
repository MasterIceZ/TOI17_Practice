/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Matrix Chain
 * ALGO		: Dynamic Programming
 * DATE		: 14 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int row[12], col[12];
int path[12][12], dp[12][12];

void divide(int l, int r){
	if(l >= r){
		cout << "A" << l + 1 ;
		return ;
	}
	cout << "(";
	divide(l, path[l][r]);
	cout << " x ";
	divide(path[l][r] + 1, r);
	cout << ")";
}

void solve(){
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> row[i] >> col[i];
	}
	for(int sz=1; sz<n; ++sz){
		for(int i=0; i+sz<n; ++i){
			int j = i + sz;
			int ans = INT_MAX;
			for(int k=i; k<j; ++k){
				int now = dp[i][k] + dp[k+1][j] + row[i] * col[k] * col[j];
				if(now < ans){
					ans = now;
					path[i][j] = k;
				}
			}
			dp[i][j] = ans;
		}
	}
	cout << dp[0][n-1] << endl;
	divide(0, n-1);
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
