/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 33;
int n;
vector<pair<int, int>> adj[MxN];
int deg[MxN], used[MxN * 10];
vector<int> ans;

void dfs(int u){
	if(ans.size() == n + 1){
		for(auto x: ans){
			cout << (char)(x + 'A') << " ";
		}	
		cout << "\n";
		exit(0);
	}
	for(auto x: adj[u]){
		if(used[x.second]){
			continue;
		}
		used[x.second] = true;
		ans.push_back(x.first);
		dfs(x.first);
		ans.pop_back();
		used[x.second] = false;
	}
}

void solve(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		string s;
		cin >> s;
		int u = s[0] - 'A', v = s[1] - 'A';
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
		deg[u]++, deg[v]++;
	}
	for(int i=0; i<26; ++i){
		sort(adj[i].begin(), adj[i].end());
	}
	int stp = -1, minn = 1e9 + 10;
	for(int i=0; i<26; ++i){
		if(deg[i] % 2 && stp == -1){
			stp = i;
		}
		else if(deg[i]){
			minn = min(minn, i);
		}
	}
	stp = (stp == -1 ? minn: stp);
	ans.push_back(stp);
	dfs(stp);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
