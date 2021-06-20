#include<bits/stdc++.h>
using namespace std;
int dp[5050][5050], pal[5050][5050];
int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for(int sz=2; sz <= s.size(); ++sz){
		for(int l=0; l+sz<=s.size(); ++l){
			pal[l][l] = dp[l][l] = 1;

			int r = l + sz - 1;
			pal[l][r] = pal[l+1][r-1] && s[l] == s[r];
			dp[l][r] = dp[l][r-1] + dp[l+1][r] - dp[l+1][r-1] + pal[l][r];
		}
	}
	int q;
	for(cin >> q; q--; ){
		int l, r;
		cin >> l >> r;
		--l, --r;
		cout << dp[l][r] << endl;
	}
	return 0;
}
