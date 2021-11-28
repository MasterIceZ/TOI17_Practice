/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: company
 * ALGO		: Depth First Search
 * DATE		: 26 Nov 2021
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

const int MxN = 100100;
vector<int> adj[MxN];
int in[MxN], cur;

void dfs(int u){
	for(auto x: adj[u]){
		dfs(x);
		cur++;
		dbg(x, cur);
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		for(int j=1, a, b; j<=x; ++j){
			cin >> a >> b;
			if(b > 50){
				adj[a].push_back(i);
				in[i]++;
			}
		}
	}
	queue<int> q;
	for(int i=1; i<=n; ++i){
		if(in[i] == 0){
			q.push(i);
			dbg(i);
		}
	}
	int ans = 0;
	while(!q.empty()){
		cur = 0;
		dfs(q.front());
		dbg(q.front(), cur);
		q.pop();
		ans = max(cur, ans);
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
