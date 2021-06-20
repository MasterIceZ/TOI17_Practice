/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Break the Sticks
 * ALGO		: Dynamic Programming
 * DATE		: 14 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int a[55];
int dp[55][55];

int divide(int l, int r, int start, int sz){
	if(l == r){
		return 0;
	}
	if(dp[l][r]){
		return dp[l][r];
	}
	dp[l][r] = INT_MAX;
	for(int i=l; i<r; ++i){
		dp[l][r] = min(dp[l][r], sz + divide(l, i, start, a[i] - start) + divide(i+1, r, a[i], sz - a[i] + start));
	}
	return dp[l][r];
}

void solve(){
	int stick, n;
	cin >> stick >> n;
	for(int i=0; i<n; ++i){
		cin >> a[i];
	}
	cout << divide(0, n, 0, stick);
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
