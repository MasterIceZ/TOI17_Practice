/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Pattaya Beach
 * ALGO		: Dynamic Programming
 * DATE		: 17 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int a[3030], b[3030];
int dp[3][3030];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		cin >> b[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(a[i] == b[j]){
				dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
			}
			else{
				dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
			}
		}
	}
	cout << dp[n % 2][n];
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
