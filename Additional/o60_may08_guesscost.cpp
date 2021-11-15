#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MxN = 333;
ll a[MxN], dp[MxN][MxN];

ll divide(int l, int r){
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	if(l == r){
		return dp[l][r] = a[l];
	}
	if(l + 1 == r){
		return dp[l][r] = a[l] + a[r];
	}
	ll res = 1e10;
	for(int i=l; i<r; ++i){
		res = min(res, a[i] + max(divide(l, i - 1), divide(i + 1, r)));
	}
	return dp[l][r] = res;
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
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
