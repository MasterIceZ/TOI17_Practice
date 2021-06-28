/*
 * AUTHOR	: Hydrolyzed~
 * TASK		: Tension7
 * CENTER	: RYW
 * DATE		: 26 Jun 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

struct Node{
	int v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;
int a[666], dp[666][666];

void solve(){
	memset(dp, 0, sizeof dp);
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		a[i] += a[i-1];
	}
	for(int sz=1; sz<n; ++sz){
		for(int i=1; i+sz<=n; ++i){
			int j = i + sz;
			dp[i][j] = INT_MIN;
			for(int k=i; k<j; ++k){
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + max(a[k] - a[i-1], a[j] - a[k]) + 2 * min(a[k] - a[i-1], a[j] - a[k]));
			}
		}
	}
	/*
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cout << dp[i][j] << " " ;
		}
		cout << endl;
	}
	* */
	cout << dp[1][n];
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
