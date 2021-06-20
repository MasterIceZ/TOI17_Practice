/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Key TOI12
 * ALGO		: Dynamic Programming
 * DATE		: 14 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

char a[1010], b[1010];
char c[2020];
bool dp[1010][1010];
int n, m;

bool solve(){
	memset(dp, false, sizeof dp);
	cin >> (c + 1);
	dp[0][0] = 1;
	for(int i=0; i<=n; ++i){
		for(int j=0; j<=m; ++j){
			if(i != 0 && dp[i-1][j] && a[i] == c[i + j]){
				dp[i][j] = 1;
			}
			if(j != 0 && dp[i][j-1] && b[j] == c[i + j]){
				dp[i][j] = 1;
			}
		}
	}
	return dp[n][m];
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> (a + 1) >> (b + 1);
	int q = 1;
	n = strlen(a + 1), m = strlen(b + 1);
	cin >> q;
	while(q--){
		cout << (solve()?"Yes":"No");
		cout << endl;
	}
	return 0;
}
