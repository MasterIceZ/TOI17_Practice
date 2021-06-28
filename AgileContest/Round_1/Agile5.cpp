/*
 * AUTHOR	: Hydrolyzed~
 * TASK		:
 * CENTER	: RYW
 * DATE		: 26 Jun 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

const int MxN = 277777;

int n, m;
int a[MxN], dp[2][MxN];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int ans = -1;
	memset(dp, -1, sizeof dp);
	for(int k=0; k<=(40 + log2(n)); ++k){
		for(int i=1; i<=n; ++i){
			if(a[i] == k){
				dp[k%2][i] = i + 1;
			}
			else{
				dp[k % 2][i] = dp[(k + 1) % 2][dp[(k + 1) % 2][i]];
			}
			if(dp[k%2][i] >= 1){
					ans = max(ans, k);
			}
//			cout << dp[k % 2][i] << " ";
		}
//		cout << endl;
	}
	cout << ans;
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
