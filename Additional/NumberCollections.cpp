/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MxN = 100100;
vector<int> adj[MxN], rev[MxN];
int a[MxN] ,dp[MxN], in[MxN], k;

int dfs2(int u, int p){
	int res = 0;
	for(auto x: rev[u]){
		if(abs(a[x] - a[u]) > k){
			return x;
		}
		res = dfs2(x, u);
	}
	return res;
}

void dfs(int u, int p){
	dp[u] += 2 * dp[p];
	int mi = 0;
	for(auto x: rev[u]){
		mi = dfs2(x, u);
	}
	cerr << u << " " << mi << "\n";
	dp[u] -= dp[mi];
	for(auto x: adj[u]){
		dfs(x, u);
	}
}

void solve(){
	int n, m;
	cin >> n >> m >> k;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		rev[v].push_back(u);
		in[v]++;
	}
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		dp[i] = 1;
	}
	for(int i=1; i<=n; ++i){
		if(in[i] == 0){
			dfs(i, 0);
			break;
		}
	}
	int sum = 0;
	for(int i=1; i<=n; ++i){
		sum += dp[i];
	}
	cout << sum;
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
