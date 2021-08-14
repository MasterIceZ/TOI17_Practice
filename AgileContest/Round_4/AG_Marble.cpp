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

int power[100100], parent[100100], mini[100100];

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
	set<int> s;
	for(int i=1; i<=n; ++i){
		cin >> power[i];
		parent[i] = i;
	}
	for(int i=1; i<=k; ++i){
		cin >> u >> v;
		int ru = fr(u), 
	}
	return 0;
}
