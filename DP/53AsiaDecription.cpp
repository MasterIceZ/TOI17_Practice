/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 53Asia_Decryption
 * ALGO		: Dynamic Programming
 * DATE		: 25 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int dp[3][100100];

void solve(){
	string pat, txt;
	cin >> pat >> txt;
	int n = pat.size();
	int m = txt.size();
	if(n > m){
		cout << "RIP ASIA";
		return ;
	}
	pat = " " + pat;
	txt = " " + txt;
	for(int i=0; i<=1; ++i){
		for(int j=1; j<=m; ++j){
			dp[i][j] = 1e9 + 10;
		}
	}
	for(int i=1; i<=m; ++i){
		if(tolower(pat[1]) == tolower(txt[i])){
			dp[1][i] = 0;
		}
	}
	for(int i=2; i<=n; ++i){
		int last = -1;
		for(int j=1; j<=m; ++j){
			dp[i % 2][j] = 1e9 + 10;
			if(tolower(pat[i]) == tolower(txt[j]) && last != -1){
				dp[i % 2][j] = min(dp[i % 2][j], dp[(i + 1) % 2][last] + j - last - 1);
				dbg(i, j, dp[(i + 1) % 2][j]);
			}
			if(dp[(i + 1) % 2][j] != 1e9 + 10){
				last = j;
				dbg(last);
			}
		}
	}
	int res = 1e9 + 10;
	for(int i=n; i<=m; ++i){
		res = min(res, dp[n % 2][i]);
		dbg(i, dp[n % 2][i]);
	}
	cout << (res == 1e9 + 10 ? "RIP ASIA": to_string(res));
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
