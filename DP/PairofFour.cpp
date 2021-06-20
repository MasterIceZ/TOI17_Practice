/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Pair Of Four TOI10
 * ALGO		: Dynamic Programming
 * DATE		: 15 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

char a[1010];
int dp[1010][1010];

int divide(int l, int r){
	if(l == r){
		return 0;
	}
	if(dp[l][r]){
		return dp[l][r];
	}
	if(a[l] == a[r]){
		return dp[l][r] = 1 + divide(l+1, r-1);
	}
	for(int x=l; x<r; ++x){
		dp[l][r] = max(dp[l][r], divide(l, x) + divide(x+1, r));
	}
	return dp[l][r];
}

void solve(){
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> a[i];
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
