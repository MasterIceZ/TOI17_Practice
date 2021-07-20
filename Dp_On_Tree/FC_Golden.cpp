/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: FC_Golden Age
 * ALGO		: Dynamic Programming
 * DATE		: 19 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int n, dp[5050][111], a[5050];
int query(int u, int k){
	if(!k || u > n){
		return 0;
	}
	if(dp[u][k] != -1){
		return dp[u][k];
	}
	for(int i=0; i<=k-1; ++i){
		dp[u][k] = max(dp[u][k], a[u] + query(2 * u, i) + query(2 * u + 1, k - i - 1));
	}
	return dp[u][k];
}

void solve(){
	int k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int nax = 0;
	for(int i=1; i<=n; ++i){
		nax = max(nax, query(i, k));
	}
	cout << nax;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		memset(dp, -1, sizeof dp);
		solve();
		cout << endl;
	}
	return 0;
}
