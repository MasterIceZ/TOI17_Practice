/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi4_ogistic
 * ALGO		: Depth First Search
 * DATE		: 15 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Edge{
	char u, v;
	double val;
};

double c;
char a, b;

int hsh(char u){
	if(isupper(u)){
		if(u == 'X'){
			return 100;
		}
		else{
			return 200;
		}
	}
	return u - 'a';
}

char read(int u){
	if(u == 100){
		return 'X';
	}
	if(u == 200){
		return 'Y';
	}
	return (char)(u + 'a');
}

vector<pair<int, double>> adj[222];
bitset<222> visited;
bool ok = false;
vector<Edge> edges;
bool mtx[222][222];

void dfs(int u, int p){
	if(u == 200){
		ok = true;
		return ;
	}
	visited[u] = true;
	for(auto x: adj[u]){
		if(x.first == p || visited[x.first]){
			continue;
		}
		edges.push_back({read(u), read(x.first), x.second});
		dfs(x.first, u);
	}
}

double create(vector<double> val){
	sort(val.begin(), val.end());
	if(val.size() % 2){
		return val[val.size() / 2];
	}
	else{
		return (val[val.size() / 2 ] + val[val.size() / 2 - 1]) / 2;
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a >> b >> c;
		int u = hsh(a), v = hsh(b);
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}
	dfs(100, 100);
	if(!ok){
		cout << "broken";
		return ;
	}
	unordered_map <int, Edge> mp;
	int it = 0;
	for(auto x: edges){
		if(mtx[hsh(x.u)][hsh(x.v)]){
			continue;
		}
		mtx[hsh(x.u)][hsh(x.v)] = true;
		vector<double> tmp;
		for(auto y: adj[hsh(x.u)]){
			if(y.first == hsh(x.v)){
				tmp.push_back(y.second);
			}
		}
		mp[++it] = Edge{x.u, x.v, create(tmp)};
	}
	double sum = 0;
	for(int i=1; i<=it; ++i){
		cout << (char)(mp[i].u) << " " << (char)(mp[i].v) << " " << fixed << setprecision(1) << mp[i].val << "\n";
		sum += mp[i].val;
	}
	cout << fixed << setprecision(1) << sum << "\n";
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	while(q--){
		solve();
	}
	return 0;
}
