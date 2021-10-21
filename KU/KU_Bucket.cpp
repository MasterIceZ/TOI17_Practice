/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_Bucket
 * ALGO		: Sweepline, Dynamic Programmin on Tree
 * DATE		: 21 Oct 2021
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

vector<int> adj[333];
int dp[333], nax, mxpos;

void dfs(int u){
	for(auto x: adj[u]){
		dfs(x);
		dp[u] += dp[x];
	}
	if(dp[u] > nax){
		nax = dp[u];
		mxpos = u;
	}
}

void solve(){
	int n, q, l, r;
	cin >> n >> q;
	vector<pair<int, int>> line;
	for(int i=1; i<=n; ++i){
		cin >> l >> r;
		line.emplace_back(l, i);
		line.emplace_back(r, i);
	}
	sort(all(line));
	stack<int> st;
	set<int> root, ans;
	for(auto x: line){
		int idx = x.second;
		if(st.empty()){
			st.push(idx);
			root.insert(idx);
		}
		else if(st.top() == idx){
			st.pop();
		}
		else{
			adj[st.top()].push_back(idx);
			st.push(idx);
		}
	}
	while(q--){
		int idx;
		cin >> idx;
		dp[idx] = 1;
	}
	for(auto x: root){
		nax = 0;
		dfs(x);
		if(nax != 0){
			ans.insert(mxpos);
		}
	}
	cout << ans.size() << "\n";
	for(auto x: ans){
		cout << x << " ";
	}
	for(int i=0; i<=300; ++i){
		adj[i].clear();
	}
	memset(dp, 0, sizeof dp);
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
