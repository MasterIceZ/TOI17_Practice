/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Up Kahn
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

vector<int> adj[100100];
int in[100100];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		in[v]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=1; i<=n; ++i){
		if(!in[i]){
			pq.push(i);
		}
	}
	queue<int> st;
	while(!pq.empty()){
		int now = pq.top();
		pq.pop();
		st.push(now);
		for(auto x: adj[now]){
			if(--in[x] == 0){
				pq.push(x);
			}
		}
	}
	if(st.size() != n){
		cout << "No";
	}
	else{
		cout << "Yes ";
		while(!st.empty()){
			cout << st.front() << " " ;
			st.pop();
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
