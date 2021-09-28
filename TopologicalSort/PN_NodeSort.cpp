/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Node Sort
 * ALGO		: Kahn's Algorithm
 * DATE		: 28 Sep 2021
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

int in[50500];
vector<int> adj[50500];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i){
		cin >> v >> u;
		adj[u].push_back(v);
		in[v]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=1; i<=n; ++i){
//		dbg(in[i], i);
		if(!in[i]){
			pq.push(i);
		}
	}
	vector<int> ans;
	int tmp = -1;
	bool diff = false;
	while(!pq.empty()){
		int now = pq.top();
		if(pq.size() >= 2){
			tmp = now;
			diff = true;
		}
		pq.pop();
		ans.push_back(now);
		for(auto x: adj[now]){
			if(--in[x] == 0){
				pq.push(x);
			}
		}
	}
	if(ans.size() != n){
//		dbg(ans);
		cout << "Never";
	}
	else if(diff){
		cout << "Different";
		for(int i=0; i<ans.size(); ++i){
			if(ans[i] == tmp){
				swap(ans[i], ans[i + 1]);
				break;
			}
		}
		for(auto x: ans){
			cout << " " << x;
		}
	}
	else{
		cout << "Same";
		for(auto x: ans){
			cout << " " << x;
		}
	}
	for(int i=1; i<=n; ++i){
		adj[i].clear();
	}
	memset(in, 0, sizeof in);
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
