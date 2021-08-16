/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Marble
 * ALGO		: 
 * DATE		: 14 Aug 2021
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

int power[100100], parent[100100], pp[1000100];

int fr(int u){
	if(parent[u] == u){
		return u;
	}
	return parent[u] = fr(parent[u]);
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, k, q, u, v;
	cin >> n >> k >> q;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=1; i<=n; ++i){
		cin >> power[i];
		parent[i] = i;
		pp[power[i]] = i;
		pq.push(power[i]);
	}
	vector<int> ans;
	ans.push_back(pq.top());
	for(int i=1; i<=k; ++i){
		cin >> u >> v;
		int ru = fr(u), rv= fr(v);
		if(power[ru] > power[rv]){
			parent[rv] = ru;
		}
		else{
			parent[ru] = rv;
		}
		while(!pq.empty() && power[fr(pp[pq.top()])] != pq.top()){
			pq.pop();
		}
		ans.push_back(pq.top());
	}
	dbg(ans);
	while(q--){
		int x;
		cin >> x;
		int idx = lower_bound(all(ans), x) - ans.begin();
		cout << (idx > k ? -1 : idx) << "\n";
	}
	return 0;
}
