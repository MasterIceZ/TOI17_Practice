/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Longest
 * ALGO		: Dynamic Programming
 * DATE		: 17 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

char a[1010][1010];
int l[1010][1010], r[1010][1010], u[1010][1010], d[1010][1010];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == '1'){
				r[i][j] = r[i][j-1] + 1;
			}
		}
		for(int j=m; j>=1; --j){
			if(a[i][j] == '1'){
				l[i][j] = l[i][j+1] + 1;
			}
		}
	}
	for(int j=1; j<=m; ++j){
		for(int i=1; i<=n; ++i){
			if(a[i][j] == '1'){
				d[i][j] = d[i-1][j] + 1;
			}
		}
		for(int i=n; i>=1; --i){
			if(a[i][j] == '1'){
				u[i][j] = u[i+1][j] + 1;
			}
		}
	}
	int ans = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			ans = max({ans, u[i][j] + l[i][j] - 1, d[i][j] + l[i][j] - 1, u[i][j] + r[i][j] - 1, d[i][j] + r[i][j] - 1});
		}
	}
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
		memset(l, 0, sizeof l), memset(r, 0, sizeof r);
		memset(d, 0, sizeof d), memset(u, 0, sizeof d);
	}
	return 0;
}
