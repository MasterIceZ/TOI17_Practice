/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Sterile City
 * ALGO		: Floyd Warshall
 * DATE		: 18 Sep 2021
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

const ll INF = (1 << 30);
ll dist[555][555], dp[5][555];

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i){
		dp[0][i] = dp[1][i] = dp[2][i] = INF;
		for(int j=1; j<=n; ++j){
			dist[i][j] = INF;
		}
	}
	for(int u, v, i=1; i<=m; ++i){
		ll w;
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = min(dist[u][v], w);
	}
	vector<int> magic;
	for(int i=1, x; i<=k; ++i){
		cin >> x;
		magic.push_back(x);
	}
	for(int i=1; i<=n; ++i){
		dist[i][i] = 0;
	}
	for(int x=1; x<=n; ++x){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				dist[i][j] = min(dist[i][j], dist[i][x] + dist[x][j]);
			}
		}
	}
	for(auto x: magic){
		for(auto y: magic){
			if(x == y){
				continue;
			}
			if(dp[0][x] >= 1e9 || dist[x][y] < dist[x][dp[0][x]]){
				dp[2][x] = dp[1][x];
				dp[1][x] = dp[0][x];
				dp[0][x] = y;
			}
			else if(dp[1][x] >= 1e9 || dist[x][y] < dist[x][dp[1][x]]){
				dp[2][x] = dp[1][x];
				dp[1][x] = y;
			}
			else if(dp[2][x] >= 1e9 || dist[x][y] < dist[x][dp[2][x]]){
				dp[2][x] = y;
			}
		}
	}
	ll ans = INF;
	for(auto x: magic){
		for(auto y: magic){
			if(x == y || dist[x][y] >= 1e9){
				continue;
			}
			for(auto z:magic){
				if(z == x || z == y){
					continue;
				}
				if(dp[0][z] != x && dp[0][z] != y && dp[0][z] != INF){
					ans = min(ans, dist[x][y] + dist[z][dp[0][z]]);
				}
				else if(dp[1][z] != x && dp[1][z] != y && dp[1][z] != INF){
					ans = min(ans, dist[x][y] + dist[z][dp[1][z]]);
				}
				else if(dp[2][z] != x && dp[2][z] != y && dp[2][z] != INF){
					ans = min(ans, dist[x][y] + dist[z][dp[2][z]]);
				}
			}
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
	}
	return 0;
}
