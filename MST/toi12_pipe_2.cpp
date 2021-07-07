/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi12_pipe
 * ALGO		: Minimum Spanning Tree
 * DATE		: 4 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const{
		return w > o.w;
	}
};

int mark[15050], dp[15050], ans[15050];
pair<int, int> pos[15050];

int create(int x, int y){
	return abs(pos[x].first - pos[y].first) + abs(pos[x].second - pos[y].second);
}

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; ++i){
		cin >> pos[i].first >> pos[i].second;
		ans[i] = dp[i] = 1 << 30;
		mark[i] = i;
	}
	int idx = 0;
	dp[0] = 0;
	for(int i=0; i<n; ++i){
		int now = mark[idx];
		ans[i] = dp[now];
		swap(mark[idx], mark[n - i - 1]);
		int mn = 1 << 30;
		for(int j=0; j<n-1-i; ++j){
			int cst = create(now, mark[j]);
			dp[mark[j]] = min(cst, dp[mark[j]]);
			if(dp[mark[j]] < mn){
				mn = dp[mark[j]];
				idx = j;
			}
		}
	}
	sort(dp, dp + n);
	int ans = 0;
	for(int i=0; i<=n - k; ++i){
		ans += dp[i];
	}
	cout << ans;
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
