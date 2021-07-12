/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Disaster TOI9
 * ALGO		: Depth First Search
 * DATE		: 6 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int n;
vector<pair<int, int>> adj[33];
int deg[33];
vector<int> ans;
bool visited[333];

int k(char s){
	return s - 'A';
}

void dfs(int u){
	if(ans.size() == n + 1){
		for(auto x: ans){
			cout << (char)('A' + x) << " ";
		}
		cout << endl;
		exit(0);
	}
	for(auto x: adj[u]){
		if(visited[x.second]){
			continue;
		}
//		cout << "U : " << u << ", F : " << x.first << ", S : " << x.second << endl;
		visited[x.second] = true;
		ans.push_back(x.first);
		dfs(x.first);
		visited[x.second] = false;
//		cout << ans.back() << " " << x.first << endl;
		ans.pop_back();
	}
}

void solve(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		string a;
		cin >> a;
		int u = k(a[0]), v = k(a[1]);
		deg[u]++, deg[v]++;
		adj[u].emplace_back(v, i), adj[v].emplace_back(u, i);
	}
	for(int i=0; i<26; ++i){
		sort(all(adj[i]));
	}
	int mn = 1e9 + 2, stp = -1;
	for(int i=0; i<26; ++i){
		if(deg[i] % 2 == 1 && stp == -1){
			stp = i;
		}
		else if(deg[i]){
			mn = min(mn, i);
		}
	}
	stp = (stp == -1 ? mn : stp);
	ans.push_back(stp);
//	visited[stp] = true;
	dfs(stp);
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
