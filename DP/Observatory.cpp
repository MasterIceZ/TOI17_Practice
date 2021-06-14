/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Observatory
 * ALGO		: Dynamic Programming
 * DATE		: 12 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MxN = 2020;

int a[MxN][MxN], dpl[MxN][MxN], qsl[MxN][MxN];
int dpr[MxN][MxN], qsr[MxN][MxN];
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j]; 
			qsl[i][j] = a[i][j] - qsl[i-1][j-1] + qsl[i][j-1] + qsl[i-1][j];
			dpl[i][j] = dpl[i-1][j-1] + qsl[i][j] - qsl[i-1][j];
		}
	}
	int nax = -1e9;
	for(int i=k; i<=n; ++i){
		for(int j=k; j<=m; ++j){
			nax = max(nax, dpl[i][j] - dpl[i-k][j-k] - qsl[i][j-k] + qsl[i-k][j-k]);
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=m; j>=1; --j){
			qsr[i][j] = a[i][j] + qsr[i][j+1] + qsr[i-1][j] - qsr[i-1][j+1];
			dpr[i][j] = dpr[i-1][j+1] + qsr[i][j] - qsr[i-1][j];
		}
	}
	for(int i=k; i<=n; ++i){
		for(int j=1; j+k-1<=m; ++j){
			nax = max(nax, dpr[i][j] - dpr[i-k][j+k] - qsr[i][j+k] + qsr[i-k][j+k]);
		}
	}
	cout << nax;
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
